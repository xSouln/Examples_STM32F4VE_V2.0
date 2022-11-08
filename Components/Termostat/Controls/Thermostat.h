//==============================================================================
#ifndef _TERMOSTAT_H
#define _TERMOSTAT_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Thermostat_Types.h"
//==============================================================================
xResult TermostatInit(TermostatT* device, void* parent);

extern void TermostatTimeSynchronization(TermostatT* device);
extern void TermostatHandler(TermostatT* device);

xResult TermostatStartMeasurement(TermostatT* device);
void TermostatStoptMeasurement(TermostatT* device);

xResult TermostatHeaterEnable(TermostatT* device);
void TermostatHeaterDisable(TermostatT* device);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif