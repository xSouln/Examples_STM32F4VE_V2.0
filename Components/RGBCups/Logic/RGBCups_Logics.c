//==============================================================================
#include <string.h>
#include "RGBCups/Logic/RGBCups_Logics.h"
#include "RGBCups/Controls/RGBCups.h"
#include "RGBCups/Adapters/RGBCup_Adapter.h" 
//==============================================================================
RGBCupsResult RGBCups_SetColor(RGBCupSelector cups, WS2812_PixelT pixel)
{
	uint8_t request = cups;
	uint8_t i = 0;
	
	while (request && i < RGBCupsCount)
	{
		if (request & 0x01)
		{
			WS2812_FillPixels(&RGBCups[i].Driver, pixel, 0, RGBCups[i].PixelsCount);
		}
		
		request >>= 1;
		i++;
	}
	
	return RGBCupsResultAccept;
}
//==============================================================================
RGBCupsResult RGBCups_UpdateLayout(RGBCupSelector cups, uint32_t time_out)
{
	uint8_t request = cups;
	uint8_t i = 0;
	
	while (request && i < RGBCupsCount)
	{
		if (request & 0x03)
		{
			/*
			while (WS2812_GetTransmitterStatus(&RGBCups[i].Driver) != WS2812_TransmitterStopped && time_out)
			{
				if (!time_out)
				{
					return RGBCupsResultTimeOut;
				}
			}
			*/
			if (WS2812_GetTransmitterStatus(&RGBCups[i].Driver) == WS2812_TransmitterStopped)
			{
				WS2812_UpdateLayout(&RGBCups[i].Driver);
			}
		}
		
		request >>= 2;
		i += 2;
	}
	
	return RGBCupsResultAccept;
}
//==============================================================================
RGBCupsResult RGBCups_DrawingStart(RGBCupSelector cups, RGBCupDrawManagerBaseT* pattern)
{
	uint8_t request = cups;
	uint8_t i = 0;
	
	if (pattern)
	{
		while (request && i < RGBCupsCount)
		{
			if ((request & 0x01))
			{
				RGBCupsResult result = RGBCups_DrawManagerEx1Init(&RGBCups[i], (RGBCupDrawManagerEx1T*)pattern);
				if (result == RGBCupsResultAccept) { goto start; }
				
				result = RGBCups_DrawManagerEx2Init(&RGBCups[i], (RGBCupDrawManagerEx2T*)pattern);
				
				start:;
				if (result == RGBCupsResultAccept)
				{
					RGBCups[i].DrawManagerPattern = pattern;
					WS2812_DrawingStart(&RGBCups[i].Driver, (WS2812_DrawManagerBaseT*)RGBCups[i].DrawManager, &RGBCups[i].DrawManagerInterface);
				}
			}
			
			request >>= 1;
			i++;
		}
		
		return RGBCupsResultAccept;
	}
	
	return RGBCupsResultError;
}
//------------------------------------------------------------------------------
RGBCupsResult RGBCups_DrawingStop(RGBCupSelector cups)
{
	uint8_t request = cups;
	uint8_t i = 0;
	
	while (request && i < RGBCupsCount)
	{
		if (request & 0x01)
		{
			WS2812_DrawingStop(&RGBCups[i].Driver);
		}
		
		request >>= 1;
		i++;
	}
	
	return RGBCupsResultAccept;
}
//------------------------------------------------------------------------------
void RGBCups_Draw(RGBCupSelector cups)
{
	uint8_t request = cups;
	uint8_t i = 0;
	
	while (request && i < RGBCupsCount)
	{
		if (request & 0x01)
		{
			WS2812_Draw(&RGBCups[i].Driver);
		}
		
		request >>= 1;
		i++;
	}
}
//==============================================================================
