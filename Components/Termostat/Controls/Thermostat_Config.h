//==============================================================================
#ifndef _TERMOSTAT_CONFIG_H
#define _TERMOSTAT_CONFIG_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Components_Config.h"
//==============================================================================
#define TERMOSTAT_POINTS_BUFFER_SIZE_MASK 0x0f
#define TERMOSTAT_POINTS_BUFFER_SIZE (TERMOSTAT_POINTS_BUFFER_SIZE_MASK + 1)

#define TERMOSTAT_TEMPERATURE_UPDATE_PERIOD 100

typedef uint16_t TermostatPointT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif