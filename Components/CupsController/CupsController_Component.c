//==============================================================================
#include "CupsController_Component.h"
#include "CupsController/Adapters/LED/CupsController_LEDAdapter.h"
#include "CupsController/Adapters/Templates/CupsController_TemplateSmoothBlink.h"
#include "tim.h"
//==============================================================================
WS2812_BufT data_buffer_cups_12[(CUPS_CONTROLLER_LED_SYNC_START_DATA_COUNT
														+ CUPS_CONTROLLER_LED_DATA_BUFFER_SIZE_CUP1
														+ CUPS_CONTROLLER_LED_DATA_BUFFER_SIZE_CUP2
														+ CUPS_CONTROLLER_LED_SYNC_END_DATA_COUNT)];
//------------------------------------------------------------------------------
WS2812_BufT data_buffer_cups_34[(CUPS_CONTROLLER_LED_SYNC_START_DATA_COUNT
														+ CUPS_CONTROLLER_LED_DATA_BUFFER_SIZE_CUP3
														+ CUPS_CONTROLLER_LED_DATA_BUFFER_SIZE_CUP4
														+ CUPS_CONTROLLER_LED_SYNC_END_DATA_COUNT)];
//==============================================================================
struct
{
	uint32_t SetColor : 1;
	
} CupsControllerRequests;

Cups CupsControllerRequestCup;

CupsControllerTemplateSmoothBlinkRequestDrawingStartT RequestDrawingStart =
{
	.ColorIncrement = 0.2,
	.ColorDecrement = 0.2,
	
	.RepetitionCount = 10,
	
	.Color =
	{
		.Green = 0x10
	}
};
//==============================================================================
CupsControllerLEDAdapterT AdapterCup12 =
{
	.Timer = TIM1,
	.DMA = DMA2_Stream5,

	.PWM_Channel = 2,

	.DrawMemory = data_buffer_cups_12,
	.DrawMemorySize = sizeof(data_buffer_cups_12) / sizeof(data_buffer_cups_12[0]),
};
//------------------------------------------------------------------------------
CupsControllerLEDAdapterT AdapterCup34 =
{
	.Timer = TIM1,
	.DMA = DMA2_Stream5,

	.PWM_Channel = 3,

	.DrawMemory = data_buffer_cups_34,
	.DrawMemorySize = sizeof(data_buffer_cups_34) / sizeof(data_buffer_cups_34[0])
};
//------------------------------------------------------------------------------
CupsControllerTemplateSmoothBlinkT TemplateSmoothBlinkCup1 =
{
	.ColorIncrement = 0.20,
	.ColorDecrement = 0.33
};
//------------------------------------------------------------------------------
CupsControllerTemplateSmoothBlinkT TemplateSmoothBlinkCup2 =
{
	.ColorIncrement = 0.33,
	.ColorDecrement = 0.33
};
//------------------------------------------------------------------------------
CupsControllerTemplateSmoothBlinkT TemplateSmoothBlinkCup3 =
{
	.ColorIncrement = 0.33,
	.ColorDecrement = 0.33
};
//------------------------------------------------------------------------------
CupsControllerTemplateSmoothBlinkT TemplateSmoothBlinkCup4 =
{
	.ColorIncrement = 0.33,
	.ColorDecrement = 0.33
};
//==============================================================================
static void EventListener(void* cup, CupsControllerEventSelector event, uint32_t args, uint32_t count)
{
	switch ((uint8_t)event)
	{

		default : return;
	}
}
//==============================================================================
const static CupsControllerInterfaceT Interface =
{
	.EventListener = (CupsControllerEventListenerT)EventListener
};
//==============================================================================
inline void CupsControllerComponentHandler()
{
	CupsControllerHandler();
	
	if (CupsControllerRequests.SetColor)
	{
		CupsControllerRequests.SetColor = false;
		
		CupsControllerDrawingStart(Cup1|Cup2, &RequestDrawingStart);
	}
}
//------------------------------------------------------------------------------
inline void CupsControllerComponentTimeSynchronization()
{
	CupsControllerTimeSynchronization();
}
//==============================================================================
int CupsControllerComponentInit(void* parent)
{
	CupsControllerInit(parent, (CupsControllerInterfaceT*)&Interface);

	uint16_t buffer_offset = CUPS_CONTROLLER_LED_SYNC_START_DATA_COUNT;
	CupsController.Cups[CupNumber1].DataBuffer = data_buffer_cups_12 + buffer_offset;
	CupsController.Cups[CupNumber1].DataBufferSize = CUPS_CONTROLLER_LED_DATA_BUFFER_SIZE_CUP1;
	buffer_offset += CUPS_CONTROLLER_LED_DATA_BUFFER_SIZE_CUP1;

	CupsController.Cups[CupNumber2].DataBuffer = data_buffer_cups_12 + buffer_offset;
	CupsController.Cups[CupNumber2].DataBufferSize = CUPS_CONTROLLER_LED_DATA_BUFFER_SIZE_CUP2;

	CupsControllerLEDAdapterInit(&CupsController.Cups[CupNumber1], &AdapterCup12);
	CupsControllerLEDAdapterInit(&CupsController.Cups[CupNumber2], &AdapterCup12);
	//----------------------------------------------------------------------------
	buffer_offset = CUPS_CONTROLLER_LED_SYNC_START_DATA_COUNT;
	CupsController.Cups[CupNumber3].DataBuffer = data_buffer_cups_34 + buffer_offset;
	CupsController.Cups[CupNumber3].DataBufferSize = CUPS_CONTROLLER_LED_DATA_BUFFER_SIZE_CUP3;
	buffer_offset += CUPS_CONTROLLER_LED_DATA_BUFFER_SIZE_CUP3;

	CupsController.Cups[CupNumber4].DataBuffer = data_buffer_cups_34 + buffer_offset;
	CupsController.Cups[CupNumber4].DataBufferSize = CUPS_CONTROLLER_LED_DATA_BUFFER_SIZE_CUP4;

	CupsControllerLEDAdapterInit(&CupsController.Cups[CupNumber3], &AdapterCup34);
	CupsControllerLEDAdapterInit(&CupsController.Cups[CupNumber4], &AdapterCup34);
	//----------------------------------------------------------------------------
	CupsControllerTemplateSmoothBlinkBind(&CupsController.Cups[CupNumber1], &TemplateSmoothBlinkCup1);
	CupsControllerTemplateSmoothBlinkBind(&CupsController.Cups[CupNumber2], &TemplateSmoothBlinkCup2);
	CupsControllerTemplateSmoothBlinkBind(&CupsController.Cups[CupNumber3], &TemplateSmoothBlinkCup3);
	CupsControllerTemplateSmoothBlinkBind(&CupsController.Cups[CupNumber4], &TemplateSmoothBlinkCup4);
	//----------------------------------------------------------------------------
	WS2812_ColorT color =
	{
		.Green = 0x00,
		.Red = 0x00,
		.Blue = 0x10
	};

	CupsControllerSetColor(CupsAll, color);

  return 0;
}
//==============================================================================
