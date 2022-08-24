//==============================================================================
#include "Control.h"
//==============================================================================
ControlT Control;
//==============================================================================
ActionResults ControlInit(void* parent)
{
	Control.Description = "ControlT";
	Control.Parent = parent;
	
	SerialPortUART_ComponentInit(&Control);
	SerialPortUSB_ComponentInit(&Control);
	RGBCups_ComponentInit(&Control);
	//TCPServerWIZspi_ComponentInit(&Control);
	//RGBCups_ComponentInit(&Control);
	
	xRxRequestManagerInit(&Control.RequestManager,
											&Control,
											&Control,
											(xRxRequestT*)RxRequests);
	
	return ResultAccept;
}
//==============================================================================
