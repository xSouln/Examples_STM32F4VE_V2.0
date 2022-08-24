//==============================================================================
#ifndef BREW_GROUP_ADAPTER_H
#define BREW_GROUP_ADAPTER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "MotorDriver/MotorDriver.h"
#include "Adapters/BrewGroup_Config.h" // override default macroses
//==============================================================================
#ifndef BrewGroup_Result
#define BrewGroup_Result int8_t
#endif
//------------------------------------------------------------------------------
#ifndef BrewGroup_ResultAccept
#define BrewGroup_ResultAccept 0
#endif
//------------------------------------------------------------------------------
#ifndef BrewGroup_ResultError
#define BrewGroup_ResultError -1
#endif
//------------------------------------------------------------------------------
#ifndef BrewGroup_ResultBusy
#define BrewGroup_ResultBusy -2
#endif
//------------------------------------------------------------------------------
#ifndef BrewGroup_ResultNullPointer
#define BrewGroup_ResultNullPointer -3
#endif
//------------------------------------------------------------------------------
#ifndef BrewGroup_ResultInvalidParameter
#define BrewGroup_ResultInvalidParameter -4
#endif
//==============================================================================
typedef struct
{
	char* Description;
	void* Parent;
	
	MotorDriverT Driver;
	
} BrewGroupT;
//==============================================================================
BrewGroup_Result BrewGroup_Init(BrewGroupT* adapter, void* parent);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* BREW_GROUP_ADAPTER_H */

