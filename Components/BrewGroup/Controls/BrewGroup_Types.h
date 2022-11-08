//==============================================================================
#ifndef _BREW_GROUP_TYPES_H
#define _BREW_GROUP_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif 
//==============================================================================
#include "Common/xTypes.h"
#include "Common/xRxTransaction.h"
#include "BrewGroup_Config.h"
#include "BrewGroup/Controls/BrewGroup_MotorTypes.h"
#include "Termostat/Controls/Thermostat_Types.h"
#include "FlowMeter/Controls/FlowMeter_Types.h"
#include "WaterPump/Controls/WaterPump_Types.h"
#include "BrewGroup/Controls/BrewGroup_SensorsTypes.h"
//==============================================================================
typedef enum
{
	BrewGroupEventIdle,
	BrewGroupEventOpen,
	BrewGroupEventStartMove,
	BrewGroupEventClose,
	BrewGroupEventTimeout,
	BrewGroupEventOvercurrent,
	BrewGroupEventStatusChanged
	
} BrewGroupEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	BrewGroupRequestIdle,
	BrewGroupRequestDelay
	
} BrewGroupRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	BrewGroupValueIdle,
	
} BrewGroupValueSelector;
//------------------------------------------------------------------------------
typedef void (*BrewGroupEventListenerT)(void* device, BrewGroupEventSelector event, uint32_t args, uint32_t count);
typedef xResult (*BrewGroupRequestListenerT)(void* device, BrewGroupRequestSelector event, uint32_t args, uint32_t count);

//typedef uint32_t (*BrewGroupActionGetValueT)(void* device, BrewGroupValueSelector event, uint32_t args, uint32_t count);
//typedef xResult (*BrewGroupActionSetValueT)(void* device, BrewGroupValueSelector event, uint32_t args, uint32_t count);
//------------------------------------------------------------------------------
typedef struct
{
	BrewGroupEventListenerT EventListener;
	BrewGroupRequestListenerT RequestListener;
	
	//BrewGroupActionGetValueT GetValue;
	//BrewGroupActionSetValueT SetValue;
	
} BrewGroupTerminalT;
//==============================================================================
typedef union
{
	struct
	{
		uint32_t InitResult : 4;
	};
	
	uint32_t Value;
	
} BrewGroupStatusT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	BrewGroupTerminalT* Terminal;
	
	BrewGroupMotorT Motor;
	TermostatT Termostat;
	WaterPumpT WaterPump;
	FlowMeterT FlowMeter;
	BrewGroupSensorsT Sensors;
	
	BrewGroupStatusT Status;
	
	xRxRequestT* Requests;
	
} BrewGroupT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
