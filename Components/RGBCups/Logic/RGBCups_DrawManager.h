//==============================================================================
#ifndef RGB_CUPS_DRAW_MANAGER_LOGICS_H
#define RGB_CUPS_DRAW_MANAGER_LOGICS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "RGBCups/RGBCups_Types.h"
//==============================================================================
typedef struct
{
	RGBCUP_DRAW_MANAGER_BASE;
	
	int8_t Diraction;
	
	int16_t Steps;
	int16_t StepNumber;
	
	float GreenIncrement;
	float RedIncrement;
	float BlueIncrement;
	
} RGBCupDrawManagerEx1T;
//------------------------------------------------------------------------------
typedef struct
{
	RGBCUP_DRAW_MANAGER_BASE;
	
	int8_t Diraction;
	
	int16_t Steps;
	int16_t StepNumber;
	
	float GreenIncrement;
	float RedIncrement;
	float BlueIncrement;
	
} RGBCupDrawManagerEx2T;
//==============================================================================
RGBCupsResult RGBCups_DrawManagerEx1Init(RGBCupT* cup, const RGBCupDrawManagerEx1T* pattern);
RGBCupsResult RGBCups_DrawManagerEx2Init(RGBCupT* cup, const RGBCupDrawManagerEx2T* pattern);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* RGB_CUPS_DRAW_MANAGER_LOGICS_H */
