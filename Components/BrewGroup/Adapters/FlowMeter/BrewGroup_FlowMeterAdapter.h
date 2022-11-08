//==============================================================================
#ifndef _BREW_GROUP_FLOW_METER_ADAPTER_H
#define _BREW_GROUP_FLOW_METER_ADAPTER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "BrewGroup/Controls/BrewGroup_Types.h"
#include "FlowMeter/Controls/FlowMeter.h"
//==============================================================================
typedef struct
{
	REG_TIM_T* Register;
	
} BrewGroupFlowMeterAdapterDataT;
//------------------------------------------------------------------------------
typedef struct
{
	TIM_HandleTypeDef* Timer;
	
	BrewGroupFlowMeterAdapterDataT Data;
	
	uint16_t UpdateTime;
	
} BrewGroupFlowMeterAdapterT;
//==============================================================================
xResult BrewGroupFlowMeterAdapterInit(FlowMeterT* device, BrewGroupFlowMeterAdapterT* adapter);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

