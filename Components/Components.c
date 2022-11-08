//==============================================================================
#include "Components.h"
//==============================================================================
inline void ComponentsHandler()
{
	BrewGroupComponentHandler();
	FlowDirectorComponentHandler();
	CupsControllerComponentHandler();
}
//------------------------------------------------------------------------------
inline void ComponentsTimeSynchronization()
{
	BrewGroupComponentTimeSynchronization();
	FlowDirectorComponentTimeSynchronization();
	CupsControllerComponentTimeSynchronization();
}
//------------------------------------------------------------------------------
int ComponentsPresystemInit(void* parent)
{
	return 0;
}
//------------------------------------------------------------------------------
int ComponentsInit(void* parent)
{
	BrewGroupComponentInit(parent);
	FlowDirectorComponentInit(parent);
	CupsControllerComponentInit(parent);
	
	return 0;
}
//==============================================================================
