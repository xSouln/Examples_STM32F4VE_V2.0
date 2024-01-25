//==============================================================================
//header:

#ifndef _CORE_MQTT_CONFIG_H_
#define _CORE_MQTT_CONFIG_H_
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
//includes:


//==============================================================================
//defines:

#define MQTT_RECV_POLLING_TIMEOUT_MS 0

typedef struct NetworkContext
{
	void* Context;

} NetworkContextT;
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif //_CORE_MQTT_CONFIG_H_
