//==============================================================================
#include "CupsController_TemplateSmoothBlink.h"
#include "CupsController/Controls/CupsController.h"
//==============================================================================
static void PrivateDrawManagerHandler(WS2812_DrawManagerBaseT* manager)
{
	CupsControllerTemplateSmoothBlinkT* template = manager->Template;
	WS2812_T* driver = manager->Parent;
	CupT* cup = driver->Parent;
	
	switch((uint8_t)template->Data.State)
	{
		case CupsControllerTemplateSmoothBlinkStateOff:
			if (template->Data.TotalColor.Red
			|| template->Data.TotalColor.Green
			|| template->Data.TotalColor.Blue)
			{
				if (template->Data.TotalColor.Red)
				{
					template->Data.TotalColor.Red -= template->ColorDecrement;
					
					if (template->Data.TotalColor.Red < 0)
					{
						template->Data.TotalColor.Red = 0;
					}
				}
				
				if (template->Data.TotalColor.Green)
				{
					template->Data.TotalColor.Green -= template->ColorDecrement;
					
					if (template->Data.TotalColor.Green < 0)
					{
						template->Data.TotalColor.Green = 0;
					}
				}
				
				if (template->Data.TotalColor.Blue)
				{
					template->Data.TotalColor.Blue -= template->ColorDecrement;
					
					if (template->Data.TotalColor.Blue < 0)
					{
						template->Data.TotalColor.Blue = 0;
					}
				}
				break;
			}
			
			template->Data.State = CupsControllerTemplateSmoothBlinkStateOn;
			
		case CupsControllerTemplateSmoothBlinkStateOn:
			if (template->Data.TotalColor.Red < template->Data.RequestColor.Red
			|| template->Data.TotalColor.Green < template->Data.RequestColor.Green
			|| template->Data.TotalColor.Blue < template->Data.RequestColor.Blue)
			{
				if (template->Data.TotalColor.Red < template->Data.RequestColor.Red)
				{
					template->Data.TotalColor.Red += template->ColorIncrement;
					
					if (template->Data.TotalColor.Red > template->Data.RequestColor.Red)
					{
						template->Data.TotalColor.Red = template->Data.RequestColor.Red;
					}
				}
				
				if (template->Data.TotalColor.Green < template->Data.RequestColor.Green)
				{
					template->Data.TotalColor.Green += template->ColorIncrement;
					
					if (template->Data.TotalColor.Green > template->Data.RequestColor.Green)
					{
						template->Data.TotalColor.Green = template->Data.RequestColor.Green;
					}
				}
				
				if (template->Data.TotalColor.Blue < template->Data.RequestColor.Blue)
				{
					template->Data.TotalColor.Blue += template->ColorIncrement;
					
					if (template->Data.TotalColor.Blue > template->Data.RequestColor.Blue)
					{
						template->Data.TotalColor.Blue = template->Data.RequestColor.Blue;
					}
				}
				
				break;
			}
			
			if (template->RepetitionCount && template->RepetitionCount != -1)
			{
				template->RepetitionCount--;
			}
			
			if (template->RepetitionCount)
			{
				template->Data.State = CupsControllerTemplateSmoothBlinkStateOff;
				break;
			}
			
			template->Data.State = CupsControllerTemplateSmoothBlinkStateComplited;
			WS2812_DrawingStop(driver);
			
		default: return;
	}
	
	cup->Color.Red = template->Data.TotalColor.Red;
	cup->Color.Green = template->Data.TotalColor.Green;
	cup->Color.Blue = template->Data.TotalColor.Blue;
	
	WS2812_FillPixels(&cup->LED, cup->Color, 0, cup->PixelsCount);
}
//------------------------------------------------------------------------------
static xResult PrivateDrawManagerRequestDrawingStart(WS2812_DrawManagerBaseT* manager,
	CupsControllerTemplateSmoothBlinkRequestDrawingStartT* request)
{
	CupsControllerTemplateSmoothBlinkT* template = manager->Template;
	WS2812_T* driver = manager->Parent;
	CupT* cup = driver->Parent;
	
	template->Data.TotalColor.Red = cup->Color.Red;
	template->Data.TotalColor.Green = cup->Color.Green;
	template->Data.TotalColor.Blue = cup->Color.Blue;
	
	if (request)
	{
		template->Data.RequestColor.Red = request->Color.Red;
		template->Data.RequestColor.Green = request->Color.Green;
		template->Data.RequestColor.Blue = request->Color.Blue;
		
		template->ColorIncrement = request->ColorIncrement;
		template->ColorDecrement = request->ColorDecrement;
		
		template->RepetitionCount = request->RepetitionCount;
	}
	
	template->Data.State = CupsControllerTemplateSmoothBlinkStateOff;
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
static xResult PrivateDrawManagerRequestListener(WS2812_DrawManagerBaseT* manager, WS2812_DrawManagerRequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		case WS2812_DrawManagerRequestDrawingStart:
			return PrivateDrawManagerRequestDrawingStart(manager, (CupsControllerTemplateSmoothBlinkRequestDrawingStartT*)args);

		case WS2812_DrawManagerRequestDrawingStop:
			break;

		default : return xResultRequestIsNotFound;
	}

	return xResultAccept;
}
//------------------------------------------------------------------------------
static void PrivateDrawManagerEventListener(WS2812_DrawManagerBaseT* manager, WS2812_DrawManagerEventSelector selector, uint32_t args, uint32_t count)
{
	switch ((int)selector)
	{
		default: break;
	}
}
//------------------------------------------------------------------------------
static uint32_t PrivateDrawManagerGetValue(WS2812_DrawManagerBaseT* manager, WS2812_DrawManagerValueSelector selector)
{
	switch ((int)selector)
	{
		default : break;
	}

	return 0;
}
//------------------------------------------------------------------------------
static xResult PrivateDrawManagerSetValue(WS2812_DrawManagerBaseT* manager, WS2812_DrawManagerValueSelector selector, uint32_t value)
{
	CupsControllerTemplateSmoothBlinkT* template = manager->Template;
	
	switch ((int)selector)
	{
		case WS2812_DrawManagerValueColor:
			template->Data.RequestColor.Red = ((WS2812_ColorT*)value)->Red;
			template->Data.RequestColor.Green = ((WS2812_ColorT*)value)->Green;
			template->Data.RequestColor.Blue = ((WS2812_ColorT*)value)->Blue;
			break;
		
		default : return xResultValueIsNotFound;
	}

	return xResultAccept;
}
//==============================================================================
xResult CupsControllerTemplateSmoothBlinkBind(CupT* cup, CupsControllerTemplateSmoothBlinkT* template)
{
	cup->LED.DrawManager.Template = template;

	cup->LED.DrawManager.Handler = (WS2812_DrawManagerHandlerT)PrivateDrawManagerHandler;
	cup->LED.DrawManager.EventListener = (WS2812_DrawManagerEventListenerT)PrivateDrawManagerEventListener;
	cup->LED.DrawManager.RequestListener = (WS2812_DrawManagerRequestListenerT)PrivateDrawManagerRequestListener;
	cup->LED.DrawManager.GetValue = (WS2812_DrawManagerActionGetValueT)PrivateDrawManagerGetValue;
	cup->LED.DrawManager.SetValue = (WS2812_DrawManagerActionSetValueT)PrivateDrawManagerSetValue;

	return xResultAccept;
}
//==============================================================================
