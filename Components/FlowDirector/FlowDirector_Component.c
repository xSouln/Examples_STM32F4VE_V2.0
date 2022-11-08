//==============================================================================
#include "FlowDirector_Component.h"
#include "FlowDirector/Adapters/Servo/FlowDirector_ServoAdapter.h"
#include "FlowDirector/Adapters/Sensors/FlowDirector_SensorsAdapter.h"
//==============================================================================
FlowDirectorT FlowDirector;

FlowDirectorRequestSetPositionT FlowDirectorRequestSetPosition =
{
	.Speed = 100.0
};
//==============================================================================
inline void FlowDirectorComponentHandler()
{
	FlowDirectorHandler(&FlowDirector);
	
	if (FlowDirector.Motor.Status.Motion == FlowDirectorMotionStateStopped
	&& (FlowDirectorRequestSetPosition.Angle != FlowDirector.Motor.TotalAngle))
	{
		FlowDirectorMotorSetPosition(&FlowDirector, &FlowDirectorRequestSetPosition);
	}
}
//------------------------------------------------------------------------------
inline void FlowDirectorComponentTimeSynchronization()
{
	FlowDirectorTimeSynchronization(&FlowDirector);
}
//==============================================================================
static void FlowDirectorEventListener(FlowDirectorT* FlowDirector, FlowDirectorEventSelector event, uint32_t args, uint32_t count)
{
	switch ((uint8_t)event)
	{
		
		default : return;
	}
}
//------------------------------------------------------------------------------
static xResult FlowDirectorRequestListener(FlowDirectorT* FlowDirector, FlowDirectorRequestSelector event, uint32_t args, uint32_t count)
{
	switch ((uint8_t)event)
	{
		case FlowDirectorRequestDelay:
			HAL_Delay(args);
			break;
		
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
FlowDirectorTerminalT FlowDirectorTerminal =
{
	.EventListener = (FlowDirectorEventListenerT)FlowDirectorEventListener,
	.RequestListener = (FlowDirectorRequestListenerT)FlowDirectorEventListener,
};
//------------------------------------------------------------------------------
FlowDirectorServoAdapterT FlowDirectorServoAdapter =
{
	.PWM_Timer = (REG_TIM_T*)FLOW_DIR_MOTOR_TIMER_PWM1,
	.PWM_Channel = FLOW_DIR_MOTOR_TIMER_PWM1_CHANNEL,
};
//------------------------------------------------------------------------------
FlowDirectorSensorsAdapterT FlowDirectorSensorsAdapter =
{
	.OvercurrentSensorPort = BREW_GROUP_MOTOR_OVERCURRENT_SENSOR_GPIO_Port,
	.OvercurrentSensorPin = BREW_GROUP_MOTOR_OVERCURRENT_SENSOR_Pin,
	.OvercurrentSensorOnStateLogicLevel = 0,
};
//==============================================================================
xResult FlowDirectorComponentInit(void* parent)
{
	FlowDirectorInit(&FlowDirector, parent, &FlowDirectorTerminal);
	
	FlowDirectorSensorsAdapterInit(&FlowDirector.Sensors, &FlowDirectorSensorsAdapter);
	FlowDirectorSensorsInit(&FlowDirector);
	
	FlowDirectorServoAdapterInit(&FlowDirector.Motor, &FlowDirectorServoAdapter);
	FlowDirectorMotorInit(&FlowDirector);
	
  return 0;
}
//==============================================================================
