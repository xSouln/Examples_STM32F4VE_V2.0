//==============================================================================
#ifndef CAROUSEL_ADAPTER_H
#define CAROUSEL_ADAPTER_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Adapters/Carousel_Config.h" // override default macroses
#include "MotorDriver/MotorDriver.h"
//==============================================================================
#ifndef Carousel_Result
#define Carousel_Result int8_t
#endif
//------------------------------------------------------------------------------
#ifndef Carousel_ResultAccept
#define Carousel_ResultAccept 0
#endif
//------------------------------------------------------------------------------
#ifndef Carousel_ResultError
#define Carousel_ResultError -1
#endif
//------------------------------------------------------------------------------
#ifndef Carousel_ResultBusy
#define Carousel_ResultBusy -2
#endif
//------------------------------------------------------------------------------
#ifndef Carousel_ResultNullPointer
#define Carousel_ResultNullPointer -3
#endif
//------------------------------------------------------------------------------
#ifndef Carousel_ResultInvalidParameter
#define Carousel_ResultInvalidParameter -4
#endif
//==============================================================================
typedef struct
{
	char* Description;
	void* Parent;
	
	MotorDriverT Driver;
	
} CarouselT;
//==============================================================================
Carousel_Result Carousel_Init(CarouselT* adapter, void* parent);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* CAROUSEL_ADAPTER_H */

