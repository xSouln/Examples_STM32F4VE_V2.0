//==============================================================================
#include "CupsController.h"
#include "CupsController_DrawManager.h"
#include "WS2812/WS2812.h"
//==============================================================================
void CupsControllerDrawManagerHandler()
{
	for (uint8_t i = 0; i < CupsCount; i++)
	{
		WS2812_DrawManagerHandler(&CupsController.Cups[i].LED);
	}
}
//------------------------------------------------------------------------------
void CupsControllerDrawManagerTimeSynchronization()
{
	
}
//------------------------------------------------------------------------------
void CupsControllerDrawManagerInit()
{

}
//==============================================================================
