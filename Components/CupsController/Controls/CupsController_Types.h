//==============================================================================
#ifndef _CUPS_CONTROLLER_TYPES_H
#define _CUPS_CONTROLLER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Components_Config.h"
#include "WS2812/WS2812.h"
#include "CupsController_Info.h"
#include "CupsController_Config.h"
#include "CupsController/Controls/CupsController_LED.h"
#include "CupsController/Controls/CupsController_Heater.h"
#include "CupsController/Controls/CupsController_Template.h"
//==============================================================================
typedef enum
{
	CupNumber1,
	CupNumber2,
	CupNumber3,
	CupNumber4,
	
	CupsCount
	
} Cups;
//------------------------------------------------------------------------------
typedef enum
{
	Cup1 = 1 << CupNumber1,
	Cup2 = 1 << CupNumber2,
	Cup3 = 1 << CupNumber3,
	Cup4 = 1 << CupNumber4,
	
	CupsAll = 0xff
	
} CupSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CupsControllerEventIdle,
	CupsControllerEventUpdateLayoutStarted,
	CupsControllerEventUpdateLayoutComplite,
	
} CupsControllerEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CupsControllerRequestIdle,
	
} CupsControllerRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CupsControllerValueIdle,
	
} CupsControllerValueSelector;
//==============================================================================
typedef union
{
	struct
	{
		uint32_t DrawingIsEnable : 1;
	};
	uint32_t Value;
	
} CupsControllerStatusT;
//------------------------------------------------------------------------------
typedef void (*CupsControllerEventListenerT)(void* cup, CupsControllerEventSelector event, uint32_t args, uint32_t count);
typedef xResult (*CupsControllerRequestListenerT)(void* cup, CupsControllerRequestSelector event, uint32_t args, uint32_t count);
//------------------------------------------------------------------------------
typedef struct
{
	CupsControllerEventListenerT EventListener;
	CupsControllerRequestListenerT RequestListener;
	
} CupsControllerInterfaceT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	CupsControllerInterfaceT* Interface;
	
	CupsControllerHeaterT Heater;
	
	CupsControllerStatusT Status;
	WS2812_T LED;
	CupLEDColorT Color;
	
	uint16_t PixelsCount;
	
	uint8_t Id;
	
	WS2812_BufT* DataBuffer;
	uint16_t DataBufferSize;
	
} CupT;
//------------------------------------------------------------------------------
typedef struct
{
	uint16_t DrawManagerUpdateTime;
	
} CupsControllerOptionsT;
//------------------------------------------------------------------------------
typedef struct
{
	void* Description;
	void* Parent;
	
	CupsControllerOptionsT Options;
	
	CupT Cups[CupsCount];
	
	xRxRequestT* Requests;
	
} CupsControllerT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* RGB_CUP_TYPES_H */
