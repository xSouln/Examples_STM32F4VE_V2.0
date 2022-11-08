//==============================================================================
#include "BrewGroup_Component.h"
#include "BrewGroup/Adapters/Sensors/BrewGroup_SensorsAdapter.h"
#include "BrewGroup/Adapters/DCMotor/BrewGroup_DCMotorAdapter.h"
#include "BrewGroup/Adapters/Thermostat/BrewGroup_ThermostatAdapter.h"
#include "BrewGroup/Adapters/WaterPump/BrewGroup_WaterPumpAdapter.h"
#include "BrewGroup/Adapters/FlowMeter/BrewGroup_FlowMeterAdapter.h"
//==============================================================================
BrewGroupT BrewGroup;
static uint32_t led_update_time;
//==============================================================================
inline void BrewGroupComponentHandler()
{
	BrewGroupHandler(&BrewGroup);
	
	if (!led_update_time)
	{
		led_update_time = 1000;
		
		LED_1_GPIO_Port->ODR ^= LED_1_Pin;
	}
}
//------------------------------------------------------------------------------
inline void BrewGroupComponentTimeSynchronization()
{
	BrewGroupTimeSynchronization(&BrewGroup);
	
	if (led_update_time)
	{
		led_update_time--;
	}
}
//==============================================================================
static void BrewGroupEventListener(BrewGroupT* BrewGroup, BrewGroupEventSelector selector, uint32_t args, uint32_t count)
{
	switch ((uint8_t)selector)
	{
		
		default : return;
	}
}
//------------------------------------------------------------------------------
static xResult BrewGroupRequestListener(BrewGroupT* BrewGroup, BrewGroupRequestSelector selector, uint32_t args, uint32_t count)
{
	switch ((uint8_t)selector)
	{
		case BrewGroupRequestDelay:
			HAL_Delay(args);
			break;
		
		default : return xResultRequestIsNotFound;
	}
	
	return xResultAccept;
}
//------------------------------------------------------------------------------
BrewGroupTerminalT BrewGroupTerminal =
{
	.EventListener = (BrewGroupEventListenerT)BrewGroupEventListener,
	.RequestListener = (BrewGroupRequestListenerT)BrewGroupRequestListener,
};
//------------------------------------------------------------------------------
BrewGroupDCMotorAdapterT BrewGroupDCMotorAdapter =
{
	.PWM_ForwardTimer = (REG_TIM_T*)BREW_GROUP_MOTOR_TIMER_PWM1,
	.PWM_BackwardTimer = (REG_TIM_T*)BREW_GROUP_MOTOR_TIMER_PWM2,
	
	.PWM_ForwardChannel = BREW_GROUP_MOTOR_TIMER_PWM1_CHANNEL,
	.PWM_BackwardChannel = BREW_GROUP_MOTOR_TIMER_PWM2_CHANNEL,
};
//------------------------------------------------------------------------------
BrewGroupTermostatAdapterT BrewGroupTermostatAdapter =
{
	.Adc = &hadc2,
	.AdcUpdateTime = 10,
	
	.HeaterPort = BREW_GROUP_WATER_HEATER_GPIO_Port,
	.HeaterPin = BREW_GROUP_WATER_HEATER_Pin,
	.HeaterOnStateLogicLevel = 1,
};
//------------------------------------------------------------------------------
BrewGroupWaterPumpAdapterT BrewGroupWaterPumpAdapter =
{
	.ControlPort = BREW_GROUP_WATER_PUMP_GPIO_Port,
	.ControlPin = BREW_GROUP_WATER_PUMP_Pin,
	.ControlOnStateLogicLevel = 1
};
//------------------------------------------------------------------------------
BrewGroupFlowMeterAdapterT BrewGroupFlowMeterAdapter =
{
	.Timer = &BREW_GROUP_FLOW_METER_HTIMER,
	.UpdateTime = 10
};
//------------------------------------------------------------------------------
BrewGroupSensorsAdapterT BrewGroupSensorsAdapter =
{
	.SensorOvercurrentPort = BREW_GROUP_MOTOR_OVERCURRENT_SENSOR_GPIO_Port,
	.SensorOvercurrentPin = BREW_GROUP_MOTOR_OVERCURRENT_SENSOR_Pin,
};
//==============================================================================
xResult BrewGroupComponentInit(void* parent)
{
	BrewGroupInit(&BrewGroup, parent, &BrewGroupTerminal);
	
	BrewGroupTermostatAdapterInit(&BrewGroup.Termostat, &BrewGroupTermostatAdapter);
	TermostatInit(&BrewGroup.Termostat, &BrewGroup);
	
	BrewGroupWaterPumpAdapterInit(&BrewGroup.WaterPump, &BrewGroupWaterPumpAdapter);
	WaterPumpInit(&BrewGroup.WaterPump, &BrewGroup);
	
	BrewGroupFlowMeterAdapterInit(&BrewGroup.FlowMeter, &BrewGroupFlowMeterAdapter);
	FlowMeterInit(&BrewGroup.FlowMeter, &BrewGroup);
	
	BrewGroupSensorsAdapterInit(&BrewGroup.Sensors, &BrewGroupSensorsAdapter);
	BrewGroupSensorsInit(&BrewGroup);
	
	BrewGroupDCMotorAdapterInit(&BrewGroup.Motor, &BrewGroupDCMotorAdapter);
	BrewGroupMotorInit(&BrewGroup);
	
	FlowMeterEnable(&BrewGroup.FlowMeter);
	TermostatStartMeasurement(&BrewGroup.Termostat);
	
  return 0;
}
//==============================================================================
