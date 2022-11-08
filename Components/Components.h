//==============================================================================
#ifndef _COMPONENTS_H
#define _COMPONENTS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Components_Types.h"
//==============================================================================
#include "Terminal/Terminal_Component.h"
#include "SerialPort/SerialPort_UART_Component.h"
//#include "TCPServer/TCPServer_Component.h"
#include "CupsController/CupsController_Component.h"
//#include "Camera/Camera_OV2640_Component.h"
//#include "Carousel/Carousel_Component.h"
//#include "Slider/Slider_Component.h"
#include "BrewGroup/BrewGroup_Component.h"
#include "FlowDirector/FlowDirector_Component.h"
//==============================================================================
int ComponentsInit(void* parent);
int ComponentsPresystemInit(void* parent);

extern void ComponentsTimeSynchronization();
extern void ComponentsHandler();
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif

