//==============================================================================
#ifndef _CUPS_CONTROLLER_TEMPLATE_SMOOTH_BLINK
#define _CUPS_CONTROLLER_TEMPLATE_SMOOTH_BLINK
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif 
//==============================================================================
#include "CupsController/Controls/CupsController_Types.h"
//==============================================================================
typedef enum
{
	CupsControllerTemplateSmoothBlinkStateComplited,
	CupsControllerTemplateSmoothBlinkStateOff,
	CupsControllerTemplateSmoothBlinkStateOn
	
} CupsControllerTemplateSmoothBlinkStates;
//------------------------------------------------------------------------------
typedef struct
{
	CupsControllerTemplateSmoothBlinkStates State;
	
	struct
	{
		float Red;
		float Green;
		float Blue;
		
	} TotalColor;
	
	WS2812_ColorT RequestColor;

} CupsControllerTemplateDataSmoothBlinkT;
//------------------------------------------------------------------------------
typedef struct
{
	float ColorIncrement;
	float ColorDecrement;
	
	uint32_t RepetitionCount;

	CupsControllerTemplateDataSmoothBlinkT Data;

} CupsControllerTemplateSmoothBlinkT;
//------------------------------------------------------------------------------
typedef struct
{
	float ColorIncrement;
	float ColorDecrement;
	uint32_t RepetitionCount;
	
	WS2812_ColorT Color;

} CupsControllerTemplateSmoothBlinkRequestDrawingStartT;
//==============================================================================
xResult CupsControllerTemplateSmoothBlinkBind(CupT* cup, CupsControllerTemplateSmoothBlinkT* template);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

