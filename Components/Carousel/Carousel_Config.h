//==============================================================================
#ifndef _CAROUSEL_CONFIG_H
#define _CAROUSEL_CONFIG_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Carousel_Info.h"
//==============================================================================
#define CAROUSEL_DEFAULT_POSITION_CALIBRATION_VALUE 2028.0
#define CAROUSEL_DEFAULT_POSITION_OFFSET 9.0

#define CAROUSEL_DEFAULT_MOVE_STAR_POWER 2.0
#define CAROUSEL_DEFAULT_MOVE_STOP_POWER 2.0
#define CAROUSEL_DEFAULT_MOVE_ACCELERATION 150.0
#define CAROUSEL_DEFAULT_MOVE_DECCELERATION 100.0
#define CAROUSEL_DEFAULT_MOVE_POWER 80

#define CAROUSEL_DEFAULT_POSITION_OFFSET 9.0

#define CAROUSEL_PODS_COUNT 20

#define CAROUSEL_POD_POSITION_ANGLE_STEP (360.0 / CAROUSEL_PODS_COUNT)
#define CAROUSEL_POD_POSITION_ANGLE_STEP_DEVIATION 0.10
#define CAROUSEL_POD_POSITION_ANGLE_STEP_DEVIATION_ERROR (CAROUSEL_POD_POSITION_ANGLE_STEP_DEVIATION)
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
