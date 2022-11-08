//==============================================================================
#ifndef _FLOW_DIRECTOR_MOTOR_ADAPTER_BASE_H
#define _FLOW_DIRECTOR_MOTOR_ADAPTER_BASE_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Components_Types.h"
#include "FlowDirector_MotorAdapterConfig.h"
//==============================================================================
typedef enum
{
	FlowDirectorMotorEventIdle,
	FlowDirectorMotorEventTimeSynchronization
	
} FlowDirectorMotorEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	FlowDirectorMotorRequestIdle,
	FlowDirectorMotorRequestEnable,
	FlowDirectorMotorRequestDisable,
	FlowDirectorMotorRequestSetAngle,
	FlowDirectorMotorRequestSetOptions,
	FlowDirectorMotorRequestStop,
	
} FlowDirectorMotorRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	FlowDirectorMotorValueIdle,
	
} FlowDirectorMotorValueSelector;
//------------------------------------------------------------------------------
typedef void (*FlowDirectorMotorHandlerT)(void* device);

typedef void (*FlowDirectorMotorEventListenerT)(void* device, FlowDirectorMotorEventSelector selector, uint32_t args, uint32_t count);
typedef xResult (*FlowDirectorMotorRequestListenerT)(void* device, FlowDirectorMotorRequestSelector selector, uint32_t args, uint32_t count);

typedef uint32_t (*FlowDirectorMotorActionGetValueT)(void* device, FlowDirectorMotorValueSelector selector);
typedef xResult (*FlowDirectorMotorActionSetValueT)(void* device, FlowDirectorMotorValueSelector selector, uint32_t value);
//==============================================================================
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	
	FlowDirectorMotorHandlerT Handler;
	
	FlowDirectorMotorEventListenerT EventListener;
	FlowDirectorMotorRequestListenerT RequestListener;
	
} FlowDirectorMotorAdapterBaseT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

