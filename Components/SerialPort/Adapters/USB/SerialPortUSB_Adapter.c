//==============================================================================
#include "SerialPortUSB_Adapter.h"
#include "SerialPortUSB_TxAdapter.h"
#include "SerialPortUSB_RxAdapter.h"
//==============================================================================
extern USBD_HandleTypeDef hUsbDeviceFS;
extern USBD_DescriptorsTypeDef FS_Desc;
//------------------------------------------------------------------------------
static SerialPortT* selected_serial_port;
static uint8_t rx_buffer[CDC_DATA_HS_OUT_PACKET_SIZE];
//==============================================================================
static int8_t Init()
{
	SerialPortUSB_AdapterT* adapter = selected_serial_port->Adapter;
	
	adapter->hUsbDeviceFS = &hUsbDeviceFS;
  adapter->Handle = (USBD_CDC_HandleTypeDef*)hUsbDeviceFS.pClassData;
  adapter->Handle->RxBuffer = rx_buffer;
	
  return 0;
}
//------------------------------------------------------------------------------
static int8_t DeInit()
{
  selected_serial_port = 0;
	
  return 0;
}
//------------------------------------------------------------------------------
static int8_t TransmitCplt(uint8_t *Buf, uint32_t *Len, uint8_t epnum)
{
	if (selected_serial_port)
	{
		SerialPortUSB_AdapterT* adapter = selected_serial_port->Adapter;
		adapter->Status.IsTransmit = false;
	}
	
	return 0;
}
//------------------------------------------------------------------------------
static int8_t Control(uint8_t cmd, uint8_t* pbuf, uint16_t length)
{
  
  return 0;
}
//------------------------------------------------------------------------------
static int8_t Receive(uint8_t* buf, uint32_t *len)
{
	SerialPortUSB_AdapterT* adapter = selected_serial_port->Adapter;
	
	xCircleBufferAdd(&adapter->RxCircleBuffer, buf, (uint16_t)*len);
  HAL_PCD_EP_Receive(hUsbDeviceFS.pData, CDC_OUT_EP, rx_buffer, CDC_DATA_HS_OUT_PACKET_SIZE);
	
  return 0;
}
//==============================================================================
SerialPortAdapterResult SerialPortUSB_AdapterInit(SerialPortT* serial_port,
																									SerialPortUSB_AdapterT* adapter)
{
	if (!selected_serial_port && serial_port && adapter)
	{
		/* Stop the low level driver  */
		//USBD_LL_Stop(&hUsbDeviceFS);

		/* Initialize low level driver */
		//USBD_LL_DeInit(&hUsbDeviceFS);
		
		adapter->USBD_CDC_Itf.Init = Init;
		adapter->USBD_CDC_Itf.Control = Control;
		adapter->USBD_CDC_Itf.Receive = Receive;
		adapter->USBD_CDC_Itf.DeInit = DeInit;
		adapter->USBD_CDC_Itf.TransmitCplt = TransmitCplt;
		
		serial_port->Adapter = adapter;
		
		SerialPortUSB_TxAdapterInit(serial_port, adapter);
		SerialPortUSB_RxAdapterInit(serial_port, adapter);
		
		serial_port->Rx.Tx = &serial_port->Tx;
		
		selected_serial_port = serial_port;
		
		if (USBD_Init(&hUsbDeviceFS, &FS_Desc, DEVICE_FS) != USBD_OK)
		{
			Error_Handler();
		}
		if (USBD_RegisterClass(&hUsbDeviceFS, &USBD_CDC) != USBD_OK)
		{
			Error_Handler();
		}
		
		//USBD_LL_Reset(&hUsbDeviceFS);
		
		if (USBD_CDC_RegisterInterface(&hUsbDeviceFS, &adapter->USBD_CDC_Itf) != USBD_OK)
		{
			Error_Handler();
		}
		if (USBD_Start(&hUsbDeviceFS) != USBD_OK)
		{
			Error_Handler();
		}
		
		return SerialPortAdapterResultAccept;
	}
  
  return SerialPortAdapterResultError;
}
//==============================================================================
