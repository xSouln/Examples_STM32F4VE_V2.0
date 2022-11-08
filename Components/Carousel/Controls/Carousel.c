//==============================================================================
#include <string.h>
#include <math.h>
#include "Carousel.h"
//==============================================================================
extern void CarouselSensorsHandler(CarouselT* device);
extern void CarouselMotorDisable(CarouselT* device);
extern void CarouselMotorHandler(CarouselT* device);
//==============================================================================
static void CarouselUpdateSensors(CarouselT* device)
{
	device->Sensors.Interface.Handler(device);
}
//==============================================================================
xResult CarouselResetPosition(CarouselT* device)
{
	if (device->Status.Motion == CarouselMotionStateStopped)
	{
		device->Motor.Interface->SetValue(device, CarouselMotorValueEncoderPosition, 0);
		device->TotalAngle = 0;

		return xResultAccept;
	}

	return xResultBusy;
}
//------------------------------------------------------------------------------
xResult CarouselStop(CarouselT* device)
{
	CarouselMotorDisable(device);

	if (device->Status.Calibration == CarouselCalibratinStatusCalibrating)
	{
		device->Status.Calibration = CarouselCalibratinStatusBreak;
		device->Status.CalibrationState = CarouselCalibratinStateIdle;
	}

	if (device->Status.Basing != CarouselBasingStopped)
	{
		device->Status.BasingResult = CarouselBasingResultBreak;
		device->Status.Basing = CarouselBasingStopped;
	}

	return xResultAccept;
}
//------------------------------------------------------------------------------
xResult CarouselSetPosition(CarouselT* device, CarouselRequestSetPositionT* request)
{
	if (!device || !request)
	{
		return xResultLinkError;
	}

	if (device->Status.Motion != CarouselMotionStateStopped)
	{
		return xResultBusy;
	}

	device->Sensors.Interface.Handler(device);

	if (device->Sensors.State.Overcurrent)
	{
		return xResultError;
	}

	CarouselMotorDisable(device);

	device->RequestAngle = request->Angle;

	CarouselMotorRequestT motor_request =
	{
		.Position = (int)(request->Angle * device->Calibration.Position),
		.Power = request->Power,
		.TimeOut = request->Timeout,
		.Mode = request->Mode,
	};

	return device->Motor.Interface->RequestListener(device, CarouselMotorRequestMoveStart, (uint32_t)&motor_request, 0);
}
//------------------------------------------------------------------------------
static void CarouselCalibrationHandler(CarouselT* device)
{
	if (device->Status.Motion == CarouselMotionStateStopped
	&& device->Status.Calibration == CarouselCalibratinStatusCalibrating)
	{
		if (device->Status.MotionResult != CarouselMotionNoError)
		{
			device->Status.Calibration = CarouselCalibratinStatusError;
			device->Status.CalibrationState = CarouselCalibratinStateIdle;
			device->Interface->EventListener(device, CarouselEventCalibrationError, 0, 0);
			return;
		}

		CarouselRequestSetPositionT request;

		switch(device->Status.CalibrationState)
		{
			case CarouselCalibratinStateFindZeroMark:
				device->Status.CalibrationState = CarouselCalibratinStateMoveOutAtZeroMarkAndResetSteps;
				request.Angle = 10000;
				request.Mode = CarouselMotorModeMoveOutAtZeroMark;
				request.Power = 30.0;
				request.Timeout = 60000;
				CarouselSetPosition(device, &request);
				return;

			case CarouselCalibratinStateMoveOutAtZeroMarkAndResetSteps:
				device->Status.CalibrationState = CarouselCalibratinStateFindZeroMarkBackSide;
				request.Angle = 10000;
				request.Mode = CarouselMotorModeFindZeroMark;
				request.Power = 80.0;
				request.Timeout = 60000;
				CarouselResetPosition(device);
				CarouselSetPosition(device, &request);
				return;

			case CarouselCalibratinStateFindZeroMarkBackSide:
				device->Status.CalibrationState = CarouselCalibratinStateMoveOutAtZeroMarkAndCalibrate;
				request.Angle = 10000;
				request.Mode = CarouselMotorModeMoveOutAtZeroMark;
				request.Power = 30.0;
				request.Timeout = 60000;
				CarouselSetPosition(device, &request);
				return;
		}

		device->Calibration.Position = ((float)device->Motor.EncoderPosition / 360.0);
		CarouselResetPosition(device);

		device->Status.Calibration = CarouselCalibratinStatusCalibrated;
		device->Status.CalibrationState = CarouselCalibratinStateIdle;

		device->Interface->EventListener(device, CarouselEventCalibrationComplete, 0, 0);

		request.Angle = device->Calibration.Offset;
		request.Power = device->Motor.Options.Power;
		request.Mode = CarouselMotorModeCommom;
		request.Timeout = (uint32_t)(device->Calibration.Offset * 3000);

		CarouselSetPosition(device, &request);
	}
}
//------------------------------------------------------------------------------
void CarouselBasingHandler(CarouselT* device)
{
	if (device->Status.Motion == CarouselMotionStateStopped
	&& device->Status.Basing != CarouselBasingStopped)
	{
		if (device->Status.MotionResult != CarouselMotionNoError)
		{
			device->Status.BasingResult = CarouselBasingResultError;
			device->Status.Basing = CarouselBasingStopped;
			device->Interface->EventListener(device, CarouselEventCalibrationError, 0, 0);
			return;
		}

		CarouselRequestSetPositionT request;

		switch(device->Status.Basing)
		{
			case CarouselBasingFindZeroMark:
				if (device->Sensors.State.ZeroMark)
				{
					device->Status.Basing = CarouselBasingMoveOutAtZeroMark;
					request.Angle = 10000;
					request.Mode = CarouselMotorModeMoveOutAtZeroMark;
					request.Power = 30.0;
					request.Timeout = 60000;
					CarouselSetPosition(device, &request);
					return;
				}
		}

		CarouselResetPosition(device);
		device->Status.BasingResult = CarouselBasingResultNoError;
		device->Status.Basing = CarouselBasingStopped;
	}
}
//------------------------------------------------------------------------------
void CarouselHandler(CarouselT* device)
{
	device->LastStatus.Value = device->Status.Value;

	CarouselSensorsHandler(device);
	CarouselMotorHandler(device);

	device->Status.Sensors = device->Sensors.State.Value;
	device->TotalAngle = device->Motor.EncoderPosition / device->Calibration.Position;

	CarouselCalibrationHandler(device);
	CarouselBasingHandler(device);

	if (device->LastStatus.Value != device->Status.Value)
	{
		device->Interface->EventListener(device, CarouselEventStatusChanged, 0, 0);
	}
}
//==============================================================================
xResult CarouselSetOptions(CarouselT* device, CarouselMotorOptionsT* request)
{
	if (!device || !request)
	{
		return xResultLinkError;
	}

	if (device->Status.Motion == CarouselMotionStateStopped)
	{
		memcpy(&device->Motor.Options, request, sizeof(device->Motor.Options));

		return xResultAccept;
	}

	return xResultBusy;
}
//------------------------------------------------------------------------------
xResult CarouselSetColibration(CarouselT* carousel, CarouselCalibrationT* request)
{
	if (carousel->Status.Motion == CarouselMotionStateStopped)
	{
		memcpy(&carousel->Calibration, request, sizeof(carousel->Calibration));

		return xResultAccept;
	}

	return xResultBusy;
}
//------------------------------------------------------------------------------
xResult CarouselCalibrateAsync(CarouselT* carousel)
{
	if (carousel->Status.Calibration != CarouselCalibratinStatusCalibrating
		&& carousel->Status.Motion == CarouselMotionStateStopped)
	{
		CarouselRequestSetPositionT request;

		request.Angle = -10000;
		request.Power = 80.0;
		request.Timeout = 60000;
		request.Mode = CarouselMotorModeStopAtZeroMark;

		carousel->Calibration.Position = CAROUSEL_DEFAULT_POSITION_CALIBRATION_VALUE;
		carousel->Status.CalibrationState = CarouselCalibratinStateFindZeroMark;
		carousel->Status.Calibration = CarouselCalibratinStatusCalibrating;

		CarouselResetPosition(carousel);
		CarouselSetPosition(carousel, &request);

		return xResultAccept;
	}
	return xResultBusy;
}
//------------------------------------------------------------------------------
xResult CarouselBasing(CarouselT* carousel)
{
	if (carousel->Status.Motion == CarouselMotionStateStopped
	&& carousel->Status.Calibration != CarouselCalibratinStatusCalibrating
	&& carousel->Status.Basing == CarouselBasingStopped)
	{
		CarouselRequestSetPositionT request;
		request.Angle = 10000;
		request.Power = 80.0;
		request.Timeout = 60000;
		request.Mode = CarouselMotorModeStopAtZeroMark;

		carousel->Status.BasingResult = CarouselBasingResultNoError;
		carousel->Status.Basing = CarouselBasingFindZeroMark;

		CarouselResetPosition(carousel);
		CarouselSetPosition(carousel, &request);

		return xResultAccept;
	}
	return xResultBusy;
}
//------------------------------------------------------------------------------
xResult CarouselSetPod(CarouselT* carousel, uint8_t number)
{
	if (number >= CAROUSEL_PODS_COUNT)
	{
		return xResultOutOfRange;
	}

	float request_angle = 360.0 / CAROUSEL_PODS_COUNT * number + carousel->Calibration.Offset;
	float total_angle = carousel->TotalAngle;

	int n = (int)(total_angle / 360.0);
	total_angle -= 360.0 * n;

	if (total_angle < 0)
	{
		total_angle = 360 + total_angle;
	}

	if (request_angle > 360.0)
	{
		request_angle -= 360.0;
	}

	float difference = request_angle - total_angle;

	if (difference > 180.0)
	{
		difference = difference - 360;
	}
	else if (difference < -180.0)
	{
		difference = difference + 360;
	}

	float angle = difference + carousel->TotalAngle;

	CarouselRequestSetPositionT request =
	{
		.Angle = angle,
		.Power = carousel->Motor.Options.Power,
		.Timeout = 60000,
		.Mode = CarouselMotorModeCommom
	};

	xResult result = CarouselSetPosition(carousel, &request);
	carousel->RequestPod = number;

	return result;
}
//------------------------------------------------------------------------------
uint8_t CarouselGetPodPosition(CarouselT* device)
{
	device->TotalAngle = device->Motor.EncoderPosition / device->Calibration.Position;
	float total_angle = device->TotalAngle - device->Calibration.Offset;

	int n = (int)(total_angle / 360.0);
	total_angle -= 360.0 * n;

	if (total_angle < 0)
	{
		total_angle += 360.0;
	}

	float position = (total_angle + CAROUSEL_POD_POSITION_ANGLE_STEP) / CAROUSEL_POD_POSITION_ANGLE_STEP;
	float result = roundf(position);

	if ((position > (result + CAROUSEL_POD_POSITION_ANGLE_STEP_DEVIATION_ERROR))
	|| (position < (result - CAROUSEL_POD_POSITION_ANGLE_STEP_DEVIATION_ERROR)))
	{
		result = 0;
	}

	if(result == 21)
	{
		result = 1;
	}

	device->TotalPod = result;

	return (uint8_t)result;
}
//------------------------------------------------------------------------------
void CarouselTimeSynchronization(CarouselT* carousel)
{
	extern void CarouselMotorTimeSynchronization(CarouselT* device);

	CarouselMotorTimeSynchronization(carousel);
}
//==============================================================================
xResult CarouselInit(CarouselT* carousel, void* parent, CarouselInterfaceT* interface)
{
	extern const xRxRequestT CarouselRequests[];

	if (carousel && interface)
	{
		carousel->Description = "CarouselT";
		carousel->Parent = parent;
		carousel->Interface = interface;

		carousel->Calibration.Position = CAROUSEL_DEFAULT_POSITION_CALIBRATION_VALUE;
		carousel->Calibration.Offset = CAROUSEL_DEFAULT_POSITION_OFFSET;

		carousel->Motor.Options.StartPower = CAROUSEL_DEFAULT_MOVE_STAR_POWER;
		carousel->Motor.Options.StopPower = CAROUSEL_DEFAULT_MOVE_STOP_POWER;
		carousel->Motor.Options.Acceleration = CAROUSEL_DEFAULT_MOVE_ACCELERATION;
		carousel->Motor.Options.Deceleration = CAROUSEL_DEFAULT_MOVE_DECCELERATION;
		carousel->Motor.Options.Power = CAROUSEL_DEFAULT_MOVE_POWER;

		carousel->Requests = (xRxRequestT*)CarouselRequests;

		return xResultAccept;
	}
	return xResultLinkError;
}
//==============================================================================
