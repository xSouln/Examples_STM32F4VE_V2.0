//==============================================================================
#ifndef _CAROUSEL_H
#define _CAROUSEL_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//==============================================================================
#include "Carousel/Carousel_Types.h"
//==============================================================================
xResult CarouselInit(CarouselT* carousel, void* parent, CarouselInterfaceT* interface);

void CarouselHandler(CarouselT* carousel);
void CarouselTimeSynchronization(CarouselT* carousel);

xResult CarouselSetPosition(CarouselT* carousel, CarouselRequestSetPositionT* request);
xResult CarouselResetPosition(CarouselT* carousel);
xResult CarouselStop(CarouselT* carousel);
xResult CarouselSetOptions(CarouselT* carousel, CarouselMotorOptionsT* request);
xResult CarouselSetColibration(CarouselT* carousel, CarouselCalibrationT* request);
xResult CarouselCalibrateAsync(CarouselT* carousel);
xResult CarouselSetPod(CarouselT* carousel, uint8_t number);
xResult CarouselBasing(CarouselT* carousel);
uint8_t CarouselGetPodPosition(CarouselT* carousel);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif
