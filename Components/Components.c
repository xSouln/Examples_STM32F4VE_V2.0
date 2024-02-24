//==============================================================================
//includes:

#include "Components.h"
#include "main.h"
#include "Peripherals/xTimer/xTimer.h"
#include "Common/xList.h"
#include "CAN_Local-Types.h"

#include "Abstractions/xDevice/Communication/xDevice-RxTransactions.h"
#include "Abstractions/xDevice/Communication/xService-RxTransactions.h"
//==============================================================================
//defines:


//==============================================================================
//variables:

UniqueDeviceID_T* UniqueDeviceID = (void*)0x1FFF7A10;

static uint32_t ledToggleTimeStamp;
//------------------------------------------------------------------------------
#if FREERTOS_ENABLE == 1

int RTOS_FreeHeapSize;
int RTOS_ComponentsTaskStackWaterMark;

//static TaskHandle_t taskHandle;
#endif

//==============================================================================
//functions:


//==============================================================================
//default functions:

xResult ComponentsRequestListener(ObjectBaseT* object, int selector, uint32_t description, void* arg)
{
	return xResultNotSupported;
}
//------------------------------------------------------------------------------
void ComponentsEventListener(ObjectBaseT* object, int selector, uint32_t description, void* arg)
{

}
//------------------------------------------------------------------------------
/**
 * @brief main handler
 */
void ComponentsHandler()
{
	UsartPortsComponentHandler();
	TerminalComponentHandler();

  AHT10_ComponentHandler();

#if NET_ENABLE == 1
	NetComponentHandler();
#endif

#if DEVICE1_COMPONENT_ENABLE == 1 || HOST_DEVICE_COMPONENT_ENABLE == 1
	CAN_PortsComponentHandler();
#endif

#if DEVICE1_COMPONENT_ENABLE == 1
	LocalTransferLayerComponentHandler();
	RequestControlComponentHandler();

	Device1ComponentHandler();
#endif

#if HOST_DEVICE_COMPONENT_ENABLE == 1
	HostTransferLayerComponentHandler();
#endif

	uint32_t time = xSystemGetTime();
	if (time - ledToggleTimeStamp > 999)
	{
		ledToggleTimeStamp = time;

#ifdef LED1_Port
		LED1_Port->Output.LED1 ^= 1;

#ifdef LED2_Port
		LED2_Port->Output.LED2 ^= LED1_Port->Output.LED1;
#endif
#endif

#if defined(LED2_Port) && !defined(LED1_Port)
		LED1_Port->Output.LED2 ^= 1;
#endif

	}

#if FREERTOS_ENABLE == 1
	RTOS_FreeHeapSize = xPortGetFreeHeapSize();
	RTOS_ComponentsTaskStackWaterMark = uxTaskGetStackHighWaterMark(NULL);
#endif
}
//------------------------------------------------------------------------------
/**
 * @brief time synchronization of time-dependent processes
 */
inline void ComponentsTimeSynchronization()
{
	TerminalComponentTimeSynchronization();
	UsartPortsComponentTimeSynchronization();

	AHT10_ComponentTimeSynchronization();

#if DEVICE1_COMPONENT_ENABLE == 1
	Device1ComponentTimeSynchronization();

#endif
}
//------------------------------------------------------------------------------
void SynchronizationTimer_IRQ_Handler(xTimerT* timer, xTimerHandleT* handle)
{
	handle->Status.UpdateInterrupt = false;

	ComponentsTimeSynchronization();

}
//==============================================================================
//initialization:

#if TERMINAL_COMPONENT_ENABLE == 1 && DEVICE1_COMPONENT_ENABLE == 1
static const xTerminalObjectT privateDeviceTerminalObject =
{
	.Requests = xDeviceRxRequests,
	.Object = (void*)&Device1
};

//------------------------------------------------------------------------------
static const xTerminalObjectT privateServiceControlTerminalObject =
{
	.Requests = xServiceRxRequests,
	.Object = (void*)&Device1
};
#endif

/**
 * @brief initializing the component
 * @param parent binding to the parent object
 * @return xResult
 */
xResult ComponentsInit(void* parent)
{
	xSystemInit(parent);

	TerminalComponentInit(parent);
	UsartPortsComponentInit(parent);

#if NET_ENABLE == 1
	NetComponentInit(parent);

#if MQTT_ENABLE == 1
	MqttClientComponentInit(parent);
#endif

#endif

#if DEVICE1_COMPONENT_ENABLE == 1 || HOST_DEVICE_COMPONENT_ENABLE == 1
	CAN_PortsComponentInit(parent);
#endif

#if DEVICE1_COMPONENT_ENABLE == 1
	LocalTransferLayerComponentInit(parent);
	RequestControlComponentInit(parent);
	Device1ComponentInit(parent);

#endif

#if HOST_DEVICE_COMPONENT_ENABLE == 1
	HostTransferLayerComponentInit(parent);
	HostDeviceComponentInit(parent);
#endif

#ifdef SynchronizationTimer
	xTimerCoreBind(SynchronizationTimerNumber, SynchronizationTimer_IRQ_Handler, SynchronizationTimer, 0);
	SynchronizationTimer->DMAOrInterrupts.UpdateInterruptEnable = true;
	SynchronizationTimer->Control1.CounterEnable = true;
#endif

#if TERMINAL_COMPONENT_ENABLE == 1 && DEVICE1_COMPONENT_ENABLE == 1
	TerminalAddObject((void*)&privateDeviceTerminalObject);
	TerminalAddObject((void*)&privateServiceControlTerminalObject);
#endif

#if COMPONENTS_OWN_TASK_IS_ENABLED == 1
	xTaskCreate(privateTask, // Function that implements the task.
				"CAN local task", // Text name for the task.
				TASK_STACK_SIZE, // Number of indexes in the xStack array.
				NULL, // Parameter passed into the task.
				osPriorityHigh, // Priority at which the task is created.
				&taskHandle);
#endif

#if FREERTOS_ENABLE == 1
	RTOS_FreeHeapSize = xPortGetFreeHeapSize();
	RTOS_ComponentsTaskStackWaterMark = uxTaskGetStackHighWaterMark(NULL);
#endif

	return xResultAccept;
}
//==============================================================================
