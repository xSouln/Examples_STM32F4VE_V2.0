//==============================================================================
#include "Terminal.h"
#include "Terminal/Communication/Terminal_RxRequests.h"
#include "Components.h"
//==============================================================================
#define RESPONSE_DATA_BUFFER_SIZE 1024
//==============================================================================
static uint8_t response_data_buffer_memory[RESPONSE_DATA_BUFFER_SIZE];
xDataBufferT ResponseBuffer =
{
	.Data = response_data_buffer_memory,
	.Size = RESPONSE_DATA_BUFFER_SIZE
};
//------------------------------------------------------------------------------
TerminalTransferAdapterT TransferAdapter =
{
	.HeaderTransferStart = "HeaderTransferStart",
	.HeaderTransfer = "data: ",
	.HeaderTransferEnd = "HeaderTransferEnd"
};

//------------------------------------------------------------------------------
union
{
	struct
	{
		uint64_t Time_1ms : 1;
		
		uint64_t Time_5ms : 4;
		uint64_t Time_10ms : 4;
		
		uint64_t Time_100ms : 7;
		
		uint64_t Time_CameraUpdate : 10;
		uint64_t Time_TCPServerUpdate : 10;
		uint64_t Time_1000ms : 10;
	};
	
	uint64_t Value;
	
} Counters;
//------------------------------------------------------------------------------
const char TransferData[] = "111111111111111111\r111111111111111111\r111111111111111111\r111111111111111111\r111111111111111111\r111111111111111111\r111111111111111111\r111111111111111111\r";

REG_TIM_T* Timer7 = (REG_TIM_T*)TIM7;

uint64_t WorkTime;
xTxTransferT Transfer;
//==============================================================================
void TerminalTimerUpdateEvent()
{
	if (Counters.Time_5ms) { Counters.Time_5ms--; }
	if (Counters.Time_10ms) { Counters.Time_10ms--; }
	if (Counters.Time_100ms) { Counters.Time_100ms--; }
	if (Counters.Time_1000ms) { Counters.Time_1000ms--; }
	if (Counters.Time_CameraUpdate) { Counters.Time_CameraUpdate--; }
	Counters.Time_1ms = true;
	
	WorkTime++;
}
//==============================================================================
void TerminalHandler()
{
	static uint8_t time_update_template;
	
	if (!Counters.Time_5ms)
	{
		Counters.Time_5ms = 4;
		
		SerialPortHandler(&SerialPortUART);
		//SerialPortHandler(&SerialPortUSB);
		CameraHandler(&CameraOV2640);
		xTxTransferHandler(&Transfer);
	}
	
	if (!Counters.Time_10ms)
	{
		Counters.Time_10ms = 9;
		CupsControllerHandler();
	}
	
	if (!Counters.Time_100ms)
	{
		Counters.Time_100ms = 99;
		
		//CupsControllerHandler();
	}
	
	if (!Counters.Time_TCPServerUpdate)
	{
		Counters.Time_TCPServerUpdate = 10;
		
		//TCPServerHandler(&TCPServerWIZspi);
	}
	
	if (Counters.Time_1ms)
	{
		Counters.Time_1ms = false;
		
		CarouselHandler(&Carousel);
		SliderHandler(&Slider);
		BrewGroupHandler(&BrewGroup);
	}
	
	if (!Counters.Time_1000ms)
	{
		time_update_template++;
		
		Counters.Time_1000ms = 999;
		
		xTxTransmitString(&SerialPortUART.Tx, "serial port update 0\r");
		xTxTransmitString(&SerialPortUART.Tx, "serial port update 1\r");
		
		xTxTransferSetTxLine(&Transfer, &SerialPortUART.Tx);
		xTxTransferStart(&Transfer, (void*)TransferData, sizeof_str(TransferData));
		
		//xTxTransmitString(&SerialPortUSB.Tx, "usb serial port update 0\r");
		//xTxTransmitString(&SerialPortUSB.Tx, "usb serial port update 1\r");
		
		//RGBCupsSetColor(RGBCup1, Pixels[RGBCupNumber1]);
		//RGBCupsSetColor(RGBCup2, Pixels[RGBCupNumber2]);
	}
}
//------------------------------------------------------------------------------
xResult TerminalInit(void* parent)
{
	Terminal.Description = "TerminalT";
	Terminal.Parent = parent;
	
	Timer7->DMAOrInterrupts.UpdateInterruptEnable = true;
	Timer7->Control1.CounterEnable = true;
	
	xTxTransferInit(&Transfer, 10, 20, 0.7);
	TerminalTransferAdapterInit(&Transfer, &TransferAdapter);
	
	SerialPortUARTComponentInit(&Terminal);
	
	//SerialPortUSB_ComponentInit(&Terminal);
	//TCPServerWIZspiComponentInit(&Terminal);
	
	CameraOV2640ComponentInit(&Terminal);
	CupsControllerComponentInit(&Terminal);
	CarouselComponentInit(&Terminal);
	SliderComponentInit(&Terminal);
	BrewGroupComponentInit(&Terminal);
	//FlowDirectorComponentInit(&Terminal);
	
	xRxRequestManagerInit(&Terminal.RequestManager,
												&Terminal,
												(xRxRequestT*)TerminalRxRequests);
	
	return xResultAccept;
}
//==============================================================================
