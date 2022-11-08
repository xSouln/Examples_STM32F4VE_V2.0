//==============================================================================
#ifndef _CAROUSEL_TYPES_H
#define _CAROUSEL_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif
//==============================================================================
#include "Common/xTypes.h"
#include "Common/xRxTransaction.h"
#include "Carousel_Config.h"
#include "Components_Config.h"
#include "Carousel/Controls/Carousel_MotorBase.h"
#include "Carousel/Controls/Carousel_SensorsBase.h"
//==============================================================================
typedef enum
{
	CarouselEventIdle,
	CarouselEventPositionIsSet,
	CarouselEventZeroMark,
	CarouselEventCalibrationComplete,
	CarouselEventCalibrationError,
	CarouselEventTimeout,
	CarouselEventOvercurrent,
	CarouselEventStatusChanged

} CarouselEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselRequestIdle,
	CarouselRequestDelay

} CarouselRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselValueIdle,

} CarouselValueSelector;
//------------------------------------------------------------------------------
typedef void (*CarouselEventListenerT)(void* device, CarouselEventSelector event, uint32_t args, uint32_t count);
typedef xResult (*CarouselRequestListenerT)(void* device, CarouselRequestSelector event, uint32_t args, uint32_t count);

//typedef uint32_t (*CarouselActionGetValueT)(void* device, CarouselValueSelector event, uint32_t args, uint32_t count);
//typedef xResult (*CarouselActionSetValueT)(void* device, CarouselValueSelector event, uint32_t args, uint32_t count);
//------------------------------------------------------------------------------
typedef struct
{
	CarouselEventListenerT EventListener;
	CarouselRequestListenerT RequestListener;

	//CarouselActionGetValueT GetValue;
	//CarouselActionSetValueT SetValue;

} CarouselInterfaceT;
//==============================================================================
typedef CarouselMotorOptionsT CarouselRequestSetOptionsT;
//------------------------------------------------------------------------------
typedef struct
{
	float Angle;
	float Power;

	uint32_t Timeout;

	uint32_t Mode;

} CarouselRequestSetPositionT;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselCalibratinStatusNotCalibrated,
	CarouselCalibratinStatusCalibrating,
	CarouselCalibratinStatusCalibrated,
	CarouselCalibratinStatusError,
	CarouselCalibratinStatusBreak,

} CarouselCalibratinStatus;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselCalibratinStateIdle,
	CarouselCalibratinStateFindZeroMark,
	CarouselCalibratinStateMoveOutAtZeroMarkAndResetSteps,
	CarouselCalibratinStateFindZeroMarkBackSide,
	CarouselCalibratinStateMoveOutAtZeroMarkAndCalibrate

} CarouselCalibratinStates;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselBasingStopped,
	CarouselBasingFindZeroMark,
	CarouselBasingMoveOutAtZeroMark

} CarouselBasingStates;
//------------------------------------------------------------------------------
typedef enum
{
	CarouselBasingResultNoError,
	CarouselBasingResultError,
	CarouselBasingResultBreak,

} CarouselBasingResults;
//------------------------------------------------------------------------------
typedef union
{
	struct
	{
		uint32_t Sensors : 2; //CarouselSensors

		uint32_t Motion : 4; //CarouselMotionStates
		uint32_t MotionResult : 4; //CarouselMotionErrors

		uint32_t Calibration : 4; //CarouselCalibratinStatus
		uint32_t CalibrationState : 4;

		uint32_t Basing : 2; //CarouselBasingStates
		uint32_t BasingResult : 2; //CarouselMotionResult

		uint32_t InitResult : 4; //xResult
	};

	uint32_t Value;

} CarouselStatusT;
//------------------------------------------------------------------------------
typedef struct
{
	float Position;
	float Offset;

} CarouselCalibrationT;
//------------------------------------------------------------------------------
typedef struct
{
	int8_t Previous;
	int8_t Total;
	int8_t Next;

} CarouselPodPositionT;
//------------------------------------------------------------------------------
typedef struct
{
	OBJECT_HEADER;

	CarouselInterfaceT* Interface;

	CarouselMotorBaseT Motor;
	CarouselSensorsBaseT Sensors;

	CarouselStatusT Status;
	CarouselStatusT LastStatus;

	CarouselCalibrationT Calibration;

	float TotalAngle;
	float RequestAngle;

	int8_t TotalPod;
	int8_t RequestPod;

	xRxRequestT* Requests;
	xRxT* RxLine;

} CarouselT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
