//==============================================================================
#include <string.h>
#include "RGBCups/Logic/RGBCups_Logics.h"
#include "RGBCups/Controls/RGBCups.h"
#include "RGBCups/Adapters/RGBCup_Adapter.h" 
//==============================================================================
static void RGBCups_DrawingManagerHandlerEx1(WS2812_T* driver)
{
	RGBCupDrawManagerEx1T* manager = (RGBCupDrawManagerEx1T*)driver->DrawManager;
	RGBCupT* cup = driver->Parent;
	
	cup->Status.DrawManager = (manager->StepNumber < 0) ?
		RGBCupDrawManageStateCycleStart : RGBCupDrawManageStateCycleWork;
	
	if (manager->StepNumber >= manager->Steps)
	{
		manager->StepNumber = manager->Steps;
		manager->Diraction = -1;
	}
	else if (manager->StepNumber < 0)
	{
		manager->StepNumber = 0;
		manager->Diraction = 1;
	}
	
	WS2812_PixelT pixel =
	{
		.Green = (uint8_t)(manager->GreenIncrement * manager->StepNumber),
		.Red = (uint8_t)(manager->RedIncrement * manager->StepNumber),
		.Blue = (uint8_t)(manager->BlueIncrement * manager->StepNumber)
	};
	
	manager->StepNumber += manager->Diraction;
	
	WS2812_FillPixels(driver, pixel, 0, ((RGBCupT*)driver->Parent)->PixelsCount);
}
//------------------------------------------------------------------------------
static void RGBCups_DrawingManagerHandlerEx2(WS2812_T* driver)
{
	RGBCupDrawManagerEx1T* manager = (RGBCupDrawManagerEx1T*)driver->DrawManager;
	RGBCupT* cup = driver->Parent;
	
	cup->Status.DrawManager = (manager->StepNumber < 0) ?
		RGBCupDrawManageStateCycleStart : RGBCupDrawManageStateCycleWork;
	
	if (manager->StepNumber >= manager->Steps)
	{
		manager->StepNumber = manager->Steps;
		manager->Diraction = -1;
		cup->Status.DrawManager = RGBCupDrawManageStateCycleStart;
	}
	else if (manager->StepNumber < 0)
	{
		manager->StepNumber = 0;
		manager->Diraction = 1;
		cup->Status.DrawManager = RGBCupDrawManageStateCycleStart;
	}
	
	WS2812_PixelT pixel =
	{
		.Green = (uint8_t)(manager->GreenIncrement * manager->StepNumber),
		.Red = (uint8_t)(manager->RedIncrement * manager->StepNumber),
		.Blue = (uint8_t)(manager->BlueIncrement * manager->StepNumber)
	};
	
	manager->StepNumber += manager->Diraction;
	
	WS2812_FillPixels(driver, pixel, 0, ((RGBCupT*)driver->Parent)->PixelsCount);
}
//==============================================================================
RGBCupsResult RGBCups_DrawManagerEx1Init(RGBCupT* cup, const RGBCupDrawManagerEx1T* pattern)
{
	const char* identificator = "RGBCupDrawManagerEx1T";
	
	if (cup && pattern)
	{
		RGBCupDrawManagerEx1T* manager = (RGBCupDrawManagerEx1T*)cup->DrawManager;
		
		if (memcmp(pattern->Description, identificator, strlen(identificator)) != 0)
		{
			return RGBCupsResultError;
		}
		
		if (manager && memcmp(manager->Description, identificator, strlen(identificator)) != 0)
		{
			free(manager);
			manager = 0;
		}
		
		if (!manager)
		{
			manager = calloc(1, sizeof(RGBCupDrawManagerEx1T));
		}
		
		manager->Description = (void*)identificator;
		manager->Parent = cup;
		
		manager->BlueIncrement = pattern->BlueIncrement;
		manager->GreenIncrement = pattern->GreenIncrement;
		manager->RedIncrement = pattern->RedIncrement;
		
		manager->Diraction = pattern->Diraction;
		manager->Steps = pattern->Steps;
		manager->StepNumber = -1;
		
		cup->DrawManagerInterface.Handler = (WS2812_ActionHandler)RGBCups_DrawingManagerHandlerEx1;
		
		cup->DrawManager = (RGBCupDrawManagerBaseT*)manager;
		
		return RGBCupsResultAccept;
	}
	
	return RGBCupsResultError;
}
//------------------------------------------------------------------------------
RGBCupsResult RGBCups_DrawManagerEx2Init(RGBCupT* cup, const RGBCupDrawManagerEx2T* pattern)
{
	const char* identificator = "RGBCupDrawManagerEx2T";
	
	if (cup && pattern)
	{
		RGBCupDrawManagerEx2T* manager = (RGBCupDrawManagerEx2T*)cup->DrawManager;
		
		if (memcmp(pattern->Description, identificator, strlen(identificator)) != 0)
		{
			return RGBCupsResultError;
		}
		
		if (manager && memcmp(manager->Description, identificator, strlen(identificator)) != 0)
		{
			free(manager);
			manager = 0;
		}
		
		if (!manager)
		{
			manager = calloc(1, sizeof(RGBCupDrawManagerEx2T));
		}
		
		manager->Description = (void*)identificator;
		manager->Parent = cup;
		
		manager->BlueIncrement = pattern->BlueIncrement;
		manager->GreenIncrement = pattern->GreenIncrement;
		manager->RedIncrement = pattern->RedIncrement;
		
		manager->Diraction = pattern->Diraction;
		manager->Steps = pattern->Steps;
		manager->StepNumber = -1;
		
		cup->DrawManagerInterface.Handler = (WS2812_ActionHandler)RGBCups_DrawingManagerHandlerEx1;
		
		cup->DrawManager = (RGBCupDrawManagerBaseT*)manager;
		
		return RGBCupsResultAccept;
	}
	
	return RGBCupsResultError;
}
//==============================================================================
