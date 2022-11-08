//==============================================================================
#include "CupsController.h"
#include "CupsController_DrawManager.h"
#include "CupsController/Controls/CupsController_LED.h"
//==============================================================================
CupsControllerT CupsController;

static uint32_t draw_manager_update_time;
//==============================================================================
void CupsControllerHandler()
{
	if (!draw_manager_update_time)
	{
		draw_manager_update_time = CupsController.Options.DrawManagerUpdateTime;
		CupsControllerDrawManagerHandler(CupsAll);
	}
}
//------------------------------------------------------------------------------
void CupsControllerTimeSynchronization()
{
	if (draw_manager_update_time)
	{
		draw_manager_update_time--;
	}
}
//------------------------------------------------------------------------------
xResult CupsControllerSetColor(CupSelector cups, CupLEDColorT color)
{
	uint8_t request = cups;
	uint8_t i = 0;

	while (request && i < CupsCount)
	{
		if (request & 0x01)
		{
			if (CupsController.Cups[i].LED.DrawManager.Status.DrawingIsEnable)
			{
				WS2812_DrawingStop(&CupsController.Cups[i].LED);
			}
			WS2812_FillPixels(&CupsController.Cups[i].LED, color, 0, CupsController.Cups[i].PixelsCount);
			CupsController.Cups[i].Color = color;
		}

		request >>= 1;
		i++;
	}

	CupsControllerUpdateLayout(cups, 1000);

	return xResultAccept;
}
//------------------------------------------------------------------------------
xResult CupsControllerUpdateLayout(CupSelector cups, uint32_t time_out)
{
	uint8_t request = cups;
	uint8_t i = 0;

	while (request && i < CupsCount)
	{
		if (request & 0x03)
		{
			if (WS2812_GetTransmitterStatus(&CupsController.Cups[i].LED) == WS2812_TransmitterStopped)
			{
				WS2812_UpdateLayout(&CupsController.Cups[i].LED);
			}
		}

		request >>= 2;
		i += 2;
	}

	return xResultAccept;
}
//------------------------------------------------------------------------------
xResult CupsControllerDrawingStart(CupSelector cups, void* template_request)
{
	uint8_t request = cups;
	uint8_t i = 0;

	while (request && i < CupsCount)
	{
		if (request & 0x01)
		{
			WS2812_DrawingStart(&CupsController.Cups[i].LED, template_request);
		}

		request >>= 1;
		i++;
	}

	return xResultAccept;
}
//------------------------------------------------------------------------------
xResult CupsControllerDrawingStop(CupSelector cups)
{
	uint8_t request = cups;
	uint8_t i = 0;

	while (request && i < CupsCount)
	{
		if (request & 0x01)
		{
			WS2812_DrawingStop(&CupsController.Cups[i].LED);
		}

		request >>= 1;
		i++;
	}

	return xResultAccept;
}
//==============================================================================
xResult CupsControllerInit(void* parent, CupsControllerInterfaceT* interface)
{
	extern const xRxRequestT CupsControllerRxRequests[];

	CupsController.Description = "CupsControllerControlT";
	CupsController.Parent = parent;
	CupsController.Requests = (xRxRequestT*)CupsControllerRxRequests;
	CupsController.Options.DrawManagerUpdateTime = CUPS_CONTROLLER_DRAW_MANAGER_UPDATE_TIME;

	for (uint8_t i = 0; i < CupsCount; i++)
	{
		CupsController.Cups[i].Description = "CupsControllerT";
		CupsController.Cups[i].Parent = &CupsController;
		CupsController.Cups[i].Interface = interface;

		CupsController.Cups[i].Id = i;
	}

	return xResultAccept;
}
//==============================================================================
