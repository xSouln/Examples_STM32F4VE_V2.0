//==============================================================================
#ifndef RGB_CUPS_H
#define RGB_CUPS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "RGBCups/RGBCups_Types.h"
#include "RGBCups/RGBCups_Info.h"
#include "RGBCups/RGBCups_Config.h"
#include "RGBCups/Communications/RGBCups_RxRequests.h"
#include "RGBCups/Adapters/RGBCup_Adapter.h"
#include "RGBCups/Logic/RGBCups_DrawManager.h"
//------------------------------------------------------------------------------
static const RGBCupDrawManagerEx1T DrawManager1 =
{
	.Description = "RGBCupDrawManagerEx1T",
	
	.Diraction = 1,
	.Steps = 10,
	
	.GreenIncrement = 1,
	.RedIncrement = 1,
	.BlueIncrement = 1,
};
//------------------------------------------------------------------------------
static const RGBCupDrawManagerEx1T DrawManager2 =
{
	.Description = "RGBCupDrawManagerEx1T",
	
	.Diraction = 1,
	.Steps = 10,
	
	.GreenIncrement = 0,
	.RedIncrement = 0,
	.BlueIncrement = 1,
};

static const RGBCupDrawManagerEx2T DrawManager3 =
{
	.Description = "RGBCupDrawManagerEx2T",
	
	.Diraction = 1,
	.Steps = 10,
	
	.GreenIncrement = 1,
	.RedIncrement = 0,
	.BlueIncrement = 0,
};
//------------------------------------------------------------------------------
extern RGBCupT RGBCups[RGBCupsCount];
//==============================================================================
RGBCupsResult RGBCups_Init(void* parent, RGBCupInterfaceT* interface);

extern RGBCupsResult RGBCups_SetColor(RGBCupSelector cups, WS2812_PixelT pixel);
extern RGBCupsResult RGBCups_UpdateLayout(RGBCupSelector cups, uint32_t time_out);

extern RGBCupsResult RGBCups_DrawingStart(RGBCupSelector cups, RGBCupDrawManagerBaseT* pattern);
extern RGBCupsResult RGBCups_DrawingStop(RGBCupSelector cups);
extern void RGBCups_Draw(RGBCupSelector cups);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* RGB_CUPS_H */
