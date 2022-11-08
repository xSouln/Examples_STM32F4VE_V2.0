//==============================================================================
#ifndef _SLIDER_H
#define _SLIDER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Slider/Slider_Types.h"
//==============================================================================
xResult SliderInit(SliderT* Slider, void* parent, SliderInterfaceT* interface);

void SliderHandler(SliderT* Slider);

xResult SliderSetPosition(SliderT* device, SliderMoveRequestT* request);
xResult SliderOpen(SliderT* Slider);
xResult SliderClose(SliderT* Slider);
void SliderStop(SliderT* Slider);

xResult SliderSetOptions(SliderT* Slider, SliderMotorOptionsT* request);
xResult SliderDropPod(SliderT* device, uint32_t open_time);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
