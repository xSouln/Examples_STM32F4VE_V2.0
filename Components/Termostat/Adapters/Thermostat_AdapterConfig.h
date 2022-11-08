//==============================================================================
#ifndef _TERMOSTAT_ADAPTER_CONFIG_H
#define _TERMOSTAT_ADAPTER_CONFIG_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Termostat/Controls/Thermostat_Config.h"
//==============================================================================
#define TERMOSTAT_ADC_UPDATE_TIME 100

#define TERMOSTAT_ADC_POINTS_COUNT_SIZE_MASK 0x0f
#define TERMOSTAT_ADC_POINTS_COUNT_SIZE (TERMOSTAT_ADC_POINTS_COUNT_SIZE_MASK + 1)
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

