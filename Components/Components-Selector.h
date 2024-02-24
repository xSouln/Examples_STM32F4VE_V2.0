//==============================================================================
#ifndef _COMPONENTS_SELECTOR_H_
#define _COMPONENTS_SELECTOR_H_

//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif 
//==============================================================================
//includes:

#include "Components-Config.h"

#include "Peripherals/xTimer/xTimer.h"
#include "Peripherals/xUSART/xUSART.h"
#include "Peripherals/CAN/xCAN.h"
//==============================================================================
/// @defgroup SelectedComponents SelectedComponents
/// @brief подключенные компоненты
/// @{

#if TERMINAL_COMPONENT_ENABLE == 1
#include "Components/Terminal/Terminal-Component.h"
#endif

#if USART_PORTS_COMPONENT_ENABLE == 1
#include "Components/USART-Ports/USART-Ports-Component.h"
#endif
//#include "Net/Net-Component.h"
//#include "MqttClient/MqttClient-Component.h"

#include "CAN-Ports/CAN_Ports-Component.h"

//#include "Components/TransferLayer/Host/HostTransferLayer-Component.h"
#include "Components/TransferLayer/Local/LocalTransferLayer-Component.h"
//#include "Components/RequestControl/Host/HostRequestControl-Component.h"
//#include "Components/RequestControl/Local/RequestControl-Component.h"

//#include "Components/Devices/Host/HostDevice-Component.h"
#include "Components/Devices/Device-1/Device1-Component.h"

#if AHT10_COMPONENT_ENABLE == 1
#include "AHT10/AHT10-Component.h"
#endif

/// @}
//==============================================================================
//defines:


//==============================================================================
//macros:


//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif //_COMPONENTS_SELECTOR_H_

