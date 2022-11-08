//==============================================================================
#ifndef _CAMERA_H
#define _CAMERA_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Camera/Camera_Types.h"
#include "Camera/Controls/Camera_AdapterBase.h"
//==============================================================================
xResult CameraInit(CameraT* camera, void* parent, CameraInterfaceT* interface);
//------------------------------------------------------------------------------
void CameraHandler(CameraT* camera);
xResult CameraGetSnapshot(CameraT* camera);
//------------------------------------------------------------------------------
xResult CameraSetConfiguration(CameraT* camera, uint8_t* data, uint16_t data_size);
xResult CameraSetOptions(CameraT* camera, CameraOptionsT* options);
xResult CameraSetContrast(CameraT* camera, CameraContrastT value);
xResult CameraSetBrightness(CameraT* camera, CameraBrightnessT value);
xResult CameraSetGain(CameraT* camera, CameraGainT value);
xResult CameraSetLightMode(CameraT* camera, CameraLightModeT value);
xResult CameraSetOutputFormat(CameraT* camera, CameraOutputFormatT value);
xResult CameraSetQuantization(CameraT* camera, CameraQuantizationT value);
xResult CameraSetResolution(CameraT* camera, CameraResolutionT value);
xResult CameraSetSaturation(CameraT* camera, CameraSaturationT value);
xResult CameraSetSpecialEffect(CameraT* camera, CameraSpecialEffectT value);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* _CAMERA_H */

