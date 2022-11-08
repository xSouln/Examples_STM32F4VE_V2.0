//==============================================================================
#ifndef _FLOW_DIRECTOR_TYPES_H
#define _FLOW_DIRECTOR_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Components_Types.h"
#include "FlowDirector_Config.h"
#include "FlowDirector/Controls/FlowDirector_MotorTypes.h"
#include "FlowDirector/Controls/FlowDirector_SensorsTypes.h"
//==============================================================================
typedef enum
{
	FlowDirectorEventIdle,
	FlowDirectorEventTimeout,
	FlowDirectorEventOvercurrent,
	FlowDirectorEventStatusChanged
	
} FlowDirectorEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	FlowDirectorRequestIdle,
	FlowDirectorRequestDelay
	
} FlowDirectorRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	FlowDirectorValueIdle,
	
} FlowDirectorValueSelector;
//------------------------------------------------------------------------------
typedef void (*FlowDirectorEventListenerT)(void* device, FlowDirectorEventSelector event, uint32_t args, uint32_t count);
typedef xResult (*FlowDirectorRequestListenerT)(void* device, FlowDirectorRequestSelector event, uint32_t args, uint32_t count);
//typedef uint32_t (*FlowDirectorActionGetValueT)(void* device, FlowDirectorValueSelector event, uint32_t args, uint32_t count);
//typedef xResult (*FlowDirectorActionSetValueT)(void* device, FlowDirectorValueSelector event, uint32_t args, uint32_t count);
//------------------------------------------------------------------------------
typedef struct
{
	FlowDirectorEventListenerT EventListener;
	FlowDirectorRequestListenerT RequestListener;
	
	//FlowDirectorActionGetValueT GetValue;
	//FlowDirectorActionSetValueT SetValue;
	
} FlowDirectorTerminalT;
//==============================================================================
typedef union
{
	struct
	{
		uint32_t Sensors : FlowDirectorSensorsCount;
		uint32_t Motion : 4;
		uint32_t Errors : 3;
		
		uint32_t InitResult : 4;
	};
	
	uint32_t Value;
	
} FlowDirectorStatusT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	FlowDirectorTerminalT* Terminal;
	
	FlowDirectorMotorT Motor;
	FlowDirectorSensorsT Sensors;
	
	FlowDirectorStatusT Status;
	
	xRxRequestT* Requests;
	
} FlowDirectorT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
