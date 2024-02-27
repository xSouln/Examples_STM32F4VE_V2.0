//==============================================================================
#ifndef _X_CAN_CONFIG_H_
#define _X_CAN_CONFIG_H_
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
//includes:

#include "xTypes-Config.h"
#include "Registers/registers.h"
//==============================================================================
//defines:

#define CAN1_ENABLE 1
#define CAN2_ENABLE 1
#define CAN3_ENABLE 0
//------------------------------------------------------------------------------

typedef enum PACKED_PREFIX
{
#if defined(rCAN1) && CAN1_ENABLE == 1
	xCAN1,
#endif

#if defined(rCAN2) && CAN2_ENABLE == 1
	xCAN2,
#endif

#if defined(rCAN3) && CAN3_ENABLE == 1
	xCAN3,
#endif

#if defined(rCAN4) && CAN4_ENABLE == 1
	xCAN4,
#endif

	xCANsCounts

} xCAN_Numbers;
//------------------------------------------------------------------------------
#define xCAN_HandleT CAN_RegT
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif //_X_CAN_CONFIG_H_
