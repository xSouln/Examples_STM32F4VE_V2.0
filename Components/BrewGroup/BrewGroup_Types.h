//==============================================================================
#ifndef RGB_CUP_TYPES_H
#define RGB_CUP_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include <stdlib.h>
#include "main.h"
#include "WS2812/WS2812.h"
//==============================================================================
#ifndef RGBCupsResult
#define RGBCupsResult int8_t
#endif
//------------------------------------------------------------------------------
#ifndef RGBCupsResultAccept
#define RGBCupsResultAccept 0
#endif
//------------------------------------------------------------------------------
#ifndef RGBCupsResultError
#define RGBCupsResultError (RGBCupsResultAccept + 1)
#endif
//------------------------------------------------------------------------------
#ifndef RGBCupsResultBusy
#define RGBCupsResultBusy (RGBCupsResultError + 1)
#endif
//------------------------------------------------------------------------------
#ifndef RGBCupsResultTimeOut
#define RGBCupsResultTimeOut (RGBCupsResultBusy + 1)
#endif
//------------------------------------------------------------------------------
#ifndef RGBCupsResultNullPointer
#define RGBCupsResultNullPointer (RGBCupsResultTimeOut + 1)
#endif
//------------------------------------------------------------------------------
#ifndef RGBCupsResultInvalidParameter
#define RGBCupsResultInvalidParameter (RGBCupsResultNullPointer + 1)
#endif
//==============================================================================
typedef enum
{
	RGBCupNumber1,
	RGBCupNumber2,
	RGBCupNumber3,
	RGBCupNumber4,
	
	RGBCupsCount
	
} RGBCupsNumbers;
//------------------------------------------------------------------------------
typedef enum
{
	RGBCup1 = 1 << RGBCupNumber1,
	RGBCup2 = 1 << RGBCupNumber2,
	RGBCup3 = 1 << RGBCupNumber3,
	RGBCup4 = 1 << RGBCupNumber4,
	
	RGBCupsAll = 0xff
	
} RGBCupSelector;
//------------------------------------------------------------------------------
typedef enum
{
	RGBCupEventUpdateLayoutStarted,
	RGBCupEventUpdateLayoutComplite,
	
} RGBCupEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	RGBCupDrawManageStateCycleStart,
	RGBCupDrawManageStateCycleWork,
	RGBCupDrawManageStateCycleEnd
	
} RGBCupDrawManagerStatus;
//==============================================================================
typedef union
{
	struct
	{
		uint32_t Drawing : 3;
		RGBCupDrawManagerStatus DrawManager : 3;
	};
	uint32_t Value;
	
} RGBCupStatusT;
//------------------------------------------------------------------------------
typedef struct
{
	void* Handle;
	
} RGBCupAdapterInterfaceT;
//------------------------------------------------------------------------------
typedef void (*RGBCupsEventListener)(void* cup, RGBCupEventSelector event, uint32_t args, uint32_t count);

typedef struct
{
	RGBCupsEventListener EventListener;
	
} RGBCupInterfaceT;
//------------------------------------------------------------------------------
#define RGBCUP_DRAW_MANAGER_BASE\
	WS2812_DRAW_MANAGER_BASE;\
//------------------------------------------------------------------------------
typedef struct
{
	WS2812_DRAW_MANAGER_BASE;
	
}	RGBCupDrawManagerBaseT;
//------------------------------------------------------------------------------
typedef WS2812_DrawManagerInterfaceT RGBCupDrawManagerInterfaceT;
//------------------------------------------------------------------------------
typedef struct
{
	void* Description;
	void* Parent;
	
	void* Adapter;
	
	RGBCupAdapterInterfaceT* AdapterInterface;
	RGBCupInterfaceT* Interface;
	
	RGBCupStatusT Status;
	WS2812_T Driver;
	
	RGBCupDrawManagerBaseT* DrawManager;
	RGBCupDrawManagerInterfaceT DrawManagerInterface;
	RGBCupDrawManagerBaseT* DrawManagerPattern;
	
	uint16_t PixelsCount;
	
	uint8_t Id;
	
	WS2812_BufT* DataBuffer;
	uint16_t DataBufferSize;
	
} RGBCupT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* RGB_CUP_TYPES_H */
