//==============================================================================
#ifndef _WATER_PUMP_TYPES_H
#define _WATER_PUMP_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "WaterPump_Config.h"
#include "WaterPump/Adapters/WaterPump_AdapterBase.h"
//==============================================================================
typedef union
{
	struct
	{
		uint8_t IsEnable;
	};
	uint8_t Value;
	
} WaterPumpStateT;
//------------------------------------------------------------------------------
typedef struct
{
	union
	{
		struct
		{
			uint8_t IsEnable;
		};
		
		uint8_t Value;
	};
	
} WaterPumpStatusT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;
	
	WaterPumpAdapterBaseT Adapter;
	WaterPumpStatusT Status;
	
} WaterPumpT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif