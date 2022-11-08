//==============================================================================
#include "CupsController_LEDAdapter.h"
//==============================================================================
static void StartTransmite(WS2812_T* driver)
{
	CupsControllerLEDAdapterT* adapter = driver->Adapter;

	DMA_Stream_TypeDef* dma = adapter->DMA;
	REG_TIM_T* timer = (REG_TIM_T*)adapter->Timer;
	volatile uint32_t* compare_reg = &timer->CaptureCompare1Value;
	uint32_t compare_enable_flag = 1 << (adapter->PWM_Channel * 4);

	timer->CaptureCompareOutput.Value &= ~compare_enable_flag;
	*(compare_reg + adapter->PWM_Channel) = 0;

	dma->CR &= ~DMA_SxCR_EN;
	dma->CR &= ~DMA_SxCR_DBM;

	dma->PAR = (uint32_t)(&timer->CaptureCompare1Value + adapter->PWM_Channel);
	dma->M0AR = (uint32_t)(adapter->DrawMemory);
	dma->NDTR = adapter->DrawMemorySize;

	dma->CR |= DMA_SxCR_TCIE;
	dma->CR |= DMA_SxCR_EN;

	timer->CaptureCompareOutput.Value |= compare_enable_flag;
}
//==============================================================================
static void Handler(WS2812_T* driver)
{
	CupsControllerLEDAdapterT* adapter = driver->Adapter;
	DMA_Stream_TypeDef* dma = (DMA_Stream_TypeDef*)adapter->DMA;

	driver->Status.Transmitter = ((dma->NDTR > 0) && (dma->CR & DMA_SxCR_EN)) ? WS2812_TransmitterIsTransmit : WS2812_TransmitterStopped;
}
//------------------------------------------------------------------------------
static void EventListener(WS2812_T* driver, WS2812_EventSelector event, uint32_t args, uint32_t count)
{
	switch ((uint32_t)event)
	{
		default : break;
	}
}
//------------------------------------------------------------------------------
static WS2812_Result RequestListener(WS2812_T* driver, WS2812_RequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((uint32_t)selector)
	{
		case WS2812_RequestTransmitterEnable:
			StartTransmite(driver);
			return xResultAccept;

		default : break;
	}

	return xResultRequestIsNotFound;
}
//------------------------------------------------------------------------------
static int GetValue(WS2812_T* driver, WS2812_ValueSelector selector)
{
	CupsControllerLEDAdapterT* adapter = driver->Adapter;
	DMA_Stream_TypeDef* dma = (DMA_Stream_TypeDef*)adapter->DMA;

	switch ((uint32_t)selector)
	{
		case WS2812_ValuePeriod :
			return ((REG_TIM_T*)adapter->Timer)->Period;

		case WS2812_ValueTransmitterStatus :
			driver->Status.Transmitter = ((dma->NDTR > 0) && (dma->CR & DMA_SxCR_EN))
																		? WS2812_TransmitterIsTransmit : WS2812_TransmitterStopped;
			return driver->Status.Transmitter;

		default : return -1;
	}
}
//------------------------------------------------------------------------------
static WS2812_Result SetValue(WS2812_T* driver, WS2812_ValueSelector selector, uint32_t value)
{
	switch ((uint32_t)selector)
	{
		default : break;
	}

	return xResultValueIsNotFound;
}
//------------------------------------------------------------------------------
static WS2812_InterfaceT driver_interface =
{
	.Handler = (WS2812_ActionHandler)Handler,
	.EventListener = (WS2812_EventListener)EventListener,
	.RequestListener = (WS2812_RequestListener)RequestListener,
	.GetValue = (WS2812_ActionGetValue)GetValue,
	.SetValue = (WS2812_ActionSetValue)SetValue
};
//==============================================================================
xResult CupsControllerLEDAdapterInit(CupT* cup, CupsControllerLEDAdapterT* adapter)
{
	if (cup && adapter)
	{
		DMA_Stream_TypeDef* dma = adapter->DMA;
		REG_TIM_T* timer = adapter->Timer;
		volatile uint32_t* compare_reg = &timer->CaptureCompare1Value;

		timer->Control1.CounterEnable = false;

		if (!timer->BreakAndDeadTime.MainOutputEnable)
		{
			timer->BreakAndDeadTime.MainOutputEnable = true;
		}

		timer->CaptureCompareOutput.Value |= 1 << (adapter->PWM_Channel * 4);
		*(compare_reg + adapter->PWM_Channel) = 0;

		timer->DMAOrInterrupts.DMA_RequestEnable = true;
		timer->Control1.CounterEnable = true;

		dma->CR &= ~DMA_SxCR_EN;

		cup->PixelsCount = cup->DataBufferSize / WS2812_BITS_IN_PIXEL;
		cup->DataBufferSize = cup->PixelsCount * WS2812_BITS_IN_PIXEL;


		//HAL_TIM_Base_Start(adapter->Timer);
		//HAL_TIM_PWM_Start(adapter->Timer, adapter->PWM_Channel);

		return WS2812_Init(&cup->LED,
												cup,
												adapter,
												&driver_interface,
												cup->DataBuffer, cup->DataBufferSize);
	}

	return xResultError;
}
//==============================================================================
