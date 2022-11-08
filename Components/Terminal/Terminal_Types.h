//==============================================================================
#ifndef _TERMINAL_TYPES_H
#define _TERMINAL_TYPES_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Terminal_Config.h"
#include "Terminal_Info.h"
#include "Components_Config.h"
//==============================================================================
typedef enum
{
	TerminalEventIdle,
	
} TerminalEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	TerminalRequestIdle,
	
} TerminalRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	TerminalValueIdle,
	
} TerminalValueSelector;
//------------------------------------------------------------------------------
typedef void (*TerminalHandlerT)(void* Terminal);
typedef void (*TerminalEventListenerT)(void* Terminal, TerminalEventSelector event, uint32_t args, uint32_t count);

typedef xResult (*TerminalRequestListenerT)(void* device, TerminalRequestSelector event, uint32_t args, uint32_t count);

typedef uint32_t (*TerminalActionGetValueT)(void* device, TerminalValueSelector event, uint32_t args, uint32_t count);
typedef xResult (*TerminalActionSetValueT)(void* device, TerminalValueSelector event, uint32_t args, uint32_t count);

typedef struct
{
	TerminalHandlerT Handler;
	
	TerminalEventListenerT EventListener;
	TerminalRequestListenerT RequestListener;
	
	TerminalActionGetValueT GetValue;
	TerminalActionSetValueT SetValue;
	
} TerminalInterfaceT;
//==============================================================================
typedef enum
{
	DeviceEventIdle,
	
} DeviceEventSelector;
//------------------------------------------------------------------------------
typedef enum
{
	DeviceRequestIdle,
	
} DeviceRequestSelector;
//------------------------------------------------------------------------------
typedef enum
{
	DeviceValueDeviceInfo,
	
} DeviceValueSelector;
//------------------------------------------------------------------------------
typedef void (*DeviceHandlerT)(void* Terminal);
typedef void (*DeviceEventListenerT)(void* Terminal, DeviceEventSelector event, uint32_t args, uint32_t count);
typedef xResult (*DeviceRequestListenerT)(void* Terminal, DeviceRequestSelector event, uint32_t args, uint32_t count);

typedef uint32_t (*DeviceActionGetValueT)(void* Terminal, DeviceValueSelector event, uint32_t args, uint32_t count);
typedef xResult (*DeviceActionSetValueT)(void* Terminal, DeviceValueSelector event, uint32_t args, uint32_t count);

typedef struct
{
	DeviceHandlerT Handler;
	
	DeviceEventListenerT EventListener;
	DeviceRequestListenerT RequestListener;
	
	DeviceActionGetValueT GetValue;
	DeviceActionSetValueT SetValue;
	
} DeviceInterfaceT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* TYPES_H */
