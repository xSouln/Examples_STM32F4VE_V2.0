//==============================================================================
#ifndef _SLIDER_TYPES_H
#define _SLIDER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Common/xTypes.h"
#include "Common/xRxTransaction.h"
#include "Components_Config.h"
#include "Slider_Config.h"
#include "Slider/Controls/Slider_MotorBase.h"
#include "Slider/Controls/Slider_SensorsBase.h"
//==============================================================================
typedef enum
{
	SliderEventIdle,
	SliderEventOpen,
	SliderEventStartMove,
	SliderEventClose,
	SliderEventTimeout,
	SliderEventOvercurrent,
	SliderEventStatusChanged
	
} SliderEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	SliderRequestIdle,
	SliderRequestDelay
	
} SliderRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	SliderValueIdle,
	
} SliderValueSelector;
//------------------------------------------------------------------------------
typedef void (*SliderEventListenerT)(void* device, SliderEventSelector event, uint32_t args, uint32_t count);
typedef xResult (*SliderRequestListenerT)(void* device, SliderRequestSelector event, uint32_t args, uint32_t count);

//typedef uint32_t (*SliderActionGetValueT)(void* device, SliderValueSelector event, uint32_t args, uint32_t count);
//typedef xResult (*SliderActionSetValueT)(void* device, SliderValueSelector event, uint32_t args, uint32_t count);
//------------------------------------------------------------------------------
typedef struct
{
	SliderEventListenerT EventListener;
	SliderRequestListenerT RequestListener;
	
	//SliderActionGetValueT GetValue;
	//SliderActionSetValueT SetValue;
	
} SliderInterfaceT;
//==============================================================================
typedef enum
{
	SliderStateIdle,
	SliderStateOpening,
	SliderStateIsOpen,
	SliderStateClosing,
	SliderStateMoveOffTheSensor,
	SliderStateRealised
	
} SliderStates;
//------------------------------------------------------------------------------
typedef enum
{
	SliderResultNoError,
	SliderResultTimeout,
	SliderResultOvercurrent,
	SliderResultBreak
	
} SliderResults;
//------------------------------------------------------------------------------
typedef union
{
	struct
	{
		uint32_t State : 4; //SliderStates
		uint32_t Result : 4; //SliderMotionResult
		
		uint32_t InitResult : 4;
	};
	
	uint32_t Value;
	
} SliderStatusT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	SliderInterfaceT* Interface;
	
	SliderMotorBaseT Motor;
	SliderSensorsBaseT Sensors;
	
	SliderStatusT Status;
	
	uint32_t OpenTime;
	
	xRxRequestT* Requests;
	xRxT* RxLine;
	
} SliderT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
