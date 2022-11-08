//==============================================================================
#ifndef _FLOW_METER_TYPES_H
#define _FLOW_METER_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Components_Config.h"
#include "FlowMeter/Adapters/FlowMeter_AdapterBase.h"
//==============================================================================
typedef enum
{
	FlowMeterOperationIdle,
	
} FlowMeterOperations;
//------------------------------------------------------------------------------
typedef enum
{
	FlowMeterOperationResultNoError,
	FlowMeterOperationResultTimeOut,
	
} FlowMeterOperationResult;
//------------------------------------------------------------------------------
typedef struct
{
	float k0;
	
} FlowMeterCalibrationT;
//------------------------------------------------------------------------------
typedef struct
{
	union
	{
		struct
		{
			uint8_t IsEnable : 1;
			
		};
		
		uint8_t Value;
	};
	
	FlowMeterOperations Operation;
	FlowMeterOperationResult OperationResult;
	
} FlowMeterStatusT;
//------------------------------------------------------------------------------
typedef struct
{
	uint16_t UpdateTime;
	
} FlowMeterOptionsT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	void* Child;
	
	FlowMeterAdapterBaseT Adapter;
	FlowMeterCalibrationT Calibration;
	FlowMeterOptionsT Options;
	FlowMeterStatusT Status;
	
	uint32_t Counter;
	uint32_t CounterPerSeconds;
	
	float TotalVolume;
	float RequestVolume;
	
	uint16_t UpdateTime;
	
} FlowMeterT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif