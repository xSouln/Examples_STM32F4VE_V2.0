//==============================================================================
#include "FlowDirector/Controls/FlowDirector_Types.h"
#include "FlowDirector_Sensors.h"
#include <string.h>
#include <math.h>
//==============================================================================
void FlowDirectorMotorDisable(FlowDirectorT* device)
{
	device->Motor.Adapter.RequestListener(&device->Motor, FlowDirectorMotorRequestDisable, 0, 0);
	device->Motor.Status.IsEnable = false;
	device->Motor.Status.Motion = FlowDirectorMotionStateStopped;
}
//------------------------------------------------------------------------------
xResult FlowDirectorMotorEnable(FlowDirectorT* device)
{
	xResult result = device->Motor.Adapter.RequestListener(&device->Motor, FlowDirectorMotorRequestEnable, 0, 0);
	
	if (result == xResultAccept)
	{
		device->Motor.Status.IsEnable = true;
	}
	
	return result;
}
//------------------------------------------------------------------------------
void FlowDirectorMotorStop(FlowDirectorT* device)
{
	device->Motor.TotalAngle = device->Motor.RequestAngle;
	device->Motor.Adapter.RequestListener(&device->Motor, FlowDirectorMotorRequestSetAngle, 0, 0);
	
	device->Motor.Status.MotionResult = FlowDirectorMotionNoError;
	device->Motor.Status.Motion = FlowDirectorMotionStateStopped;
}
//------------------------------------------------------------------------------
xResult FlowDirectorMotorSetPosition(FlowDirectorT* device, FlowDirectorRequestSetPositionT* request)
{
	FlowDirectorSensorsHandler(device);
	
	if (device->Sensors.State.Overcurrent)
	{
		device->Motor.Status.MotionResult = FlowDirectorMotionOvercurrent;
		return xResultError;
	}
	
	if (device->Motor.TotalAngle != device->Motor.RequestAngle)
	{
		return xResultBusy;
	}
	
	uint32_t deceleration_time = 0;
	uint32_t acceleration_time = 0;
	uint32_t move_time = 0;
	float speed_offset = 0;
	float speed = device->Motor.Options.StartSpeed;
	float difference = fabs(request->Angle - device->Motor.TotalAngle);
	float acceleration_increment = device->Motor.Options.Acceleration / 1000;
	float deceleration_increment = device->Motor.Options.Deceleration / 1000;
	
	while ((speed - speed_offset) > device->Motor.Options.StopSpeed
	&& move_time < device->Motor.Options.TimeOut
	&& difference > 0)
	{
			speed_offset += deceleration_increment;
			deceleration_time++;

			move_time++;
			difference -= (speed - speed_offset) / 1000;
	}
	
	while (speed < request->Speed
	&& move_time < device->Motor.Options.TimeOut
	&& difference > 0)
	{
			if ((speed - speed_offset) > device->Motor.Options.StopSpeed)
			{
					speed_offset += deceleration_increment;
					difference -= speed / 1000;
					deceleration_time++;
			}
			else
			{
					speed += acceleration_increment;
					difference -= speed / 1000;
					acceleration_time++;
			}

			move_time++;
	}

	if (difference > 0)
	{
			move_time += (int)((difference / speed) * 1000);
	}

	if (move_time > device->Motor.Options.TimeOut)
	{
			move_time = device->Motor.Options.TimeOut;
	}
	
	if (device->Motor.Options.StartSpeed < request->Speed)
	{
	}
	
	device->Motor.RequestSpeed = request->Speed;
	device->Motor.TotalSpeed = device->Motor.Options.StartSpeed;
	
	device->Motor.Debug.AccelerationTime = 0;
	device->Motor.Debug.DecelerationTime = 0;
	
	device->Motor.Status.MotionResult = FlowDirectorMotionNoError;
	device->Motor.MoveTime = 0;
	device->Motor.HandlerAngle = device->Motor.TotalAngle;
	device->Motor.AccelerationIncrement = acceleration_increment;
	device->Motor.DecelerationIncrement = deceleration_increment;
	device->Motor.AccelerationEndTime = acceleration_time;
	device->Motor.DecelerationStartTime = move_time - deceleration_time;
	device->Motor.Direction = request->Angle > device->Motor.TotalAngle ? 1 : -1;
	device->Motor.RequestAngle = request->Angle;
	
	return xResultAccept;
}
//==============================================================================
void FlowDirectorMotorHandler(FlowDirectorT* device)
{
	device->Motor.Adapter.Handler(&device->Motor);
	
	if (device->Sensors.State.Overcurrent)
	{
		FlowDirectorMotorDisable(device);
		
		if (device->Motor.Status.MotionResult != FlowDirectorMotionOvercurrent)
		{
			device->Motor.Status.MotionResult = FlowDirectorMotionOvercurrent;
			device->Terminal->EventListener(device, FlowDirectorEventOvercurrent, 0, 0);
		}
		
		device->Motor.RequestAngle = device->Motor.TotalAngle;
	}
	
	if (device->Motor.TotalAngle != device->Motor.RequestAngle
	&& device->Motor.HandlerAngle != device->Motor.TotalAngle)
	{
		device->Motor.Status.TimeIsUpdate = false;
		
		if (device->Motor.MoveTime >= device->Motor.Options.TimeOut)
		{
			device->Motor.Status.MotionResult = FlowDirectorMotionTimeout;
			device->Motor.RequestAngle = device->Motor.TotalAngle;
			device->Terminal->EventListener(device, FlowDirectorEventTimeout, 0, 0);
			
			goto end;
		}
		
		device->Motor.TotalAngle = device->Motor.HandlerAngle;
		
		if (device->Motor.Direction == -1
		&& device->Motor.TotalAngle < device->Motor.RequestAngle)
		{
			device->Motor.TotalAngle = device->Motor.RequestAngle;
		}
		else if (device->Motor.Direction == 1
		&& device->Motor.TotalAngle > device->Motor.RequestAngle)
		{
			device->Motor.TotalAngle = device->Motor.RequestAngle;
		}
		
		device->Motor.Adapter.RequestListener(&device->Motor, FlowDirectorMotorRequestSetAngle, 0, 0);
	}
	
	end:;
	if (device->Motor.TotalAngle == device->Motor.RequestAngle)
	{
		device->Motor.Status.Motion = FlowDirectorMotionStateStopped;
	}
	else
	{
		device->Motor.Status.Motion = FlowDirectorMotionStateMoving;
	}
}
//------------------------------------------------------------------------------
void FlowDirectorMotorTimeSynchronization(FlowDirectorT* device)
{
	if (device->Motor.Status.Motion != FlowDirectorMotionStateStopped
	&& !device->Motor.Status.TimerSynchronization)
	{
		device->Motor.MoveTime++;
		device->Motor.Status.TimeIsUpdate = true;
		
		if (device->Motor.MoveTime > device->Motor.DecelerationStartTime
		&& device->Motor.TotalSpeed > device->Motor.Options.StopSpeed)
		{
			device->Motor.TotalSpeed -= device->Motor.DecelerationIncrement;
			device->Motor.Debug.DecelerationTime++;
		}
		else if (device->Motor.TotalSpeed < device->Motor.RequestSpeed)
		{
			device->Motor.TotalSpeed += device->Motor.AccelerationIncrement;
			device->Motor.Debug.AccelerationTime++;
		}
		
		device->Motor.HandlerAngle += device->Motor.TotalSpeed * device->Motor.Direction / 1000;
	}
}
//------------------------------------------------------------------------------
xResult FlowDirectorSetMotorOptions(FlowDirectorT* device, FlowDirectorMotorOptionsT* request)
{
	if (device->Motor.Status.Motion == FlowDirectorMotionStateStopped)
	{
		memcpy(&device->Motor.Options, request, sizeof(device->Motor.Options));
		return xResultAccept;
	}
	return xResultBusy;
}
//------------------------------------------------------------------------------
xResult FlowDirectorMotorInit(FlowDirectorT* device)
{
	if (device)
	{
		device->Motor.Description = "FlowDirectorMotorT";
		device->Motor.Parent = device;
		
		device->Motor.Options.StartSpeed = FLOW_DIRECTOR_MOTOR_DEFAULT_MOVE_STAR_SPEED;
		device->Motor.Options.StopSpeed = FLOW_DIRECTOR_MOTOR_DEFAULT_MOVE_STOP_SPEED;
		device->Motor.Options.Acceleration = FLOW_DIRECTOR_MOTOR_DEFAULT_MOVE_ACCELERATION;
		device->Motor.Options.Deceleration = FLOW_DIRECTOR_MOTOR_DEFAULT_MOVE_DECELERATION;
		device->Motor.Options.TimeOut = FLOW_DIRECTOR_MOTOR_DEFAULT_TIMEOUT;
		
		return xResultAccept;
	}
	return xResultError;
}
//==============================================================================
