//==============================================================================
#ifndef __OV2640_REQUESTS_H
#define __OV2640_REQUESTS_H
//------------------------------------------------------------------------------
#ifdef __cplusplus
 extern "C" {
#endif 
//==============================================================================
#include "Adapters/OV2640_Adapter.h"
//==============================================================================
OV2640_Result OV2640_ControlInit(void* parent);

void OV2640_ControlHandler();
//==============================================================================
extern xTransferLayerControlT OV2640_RGB565_TransferLayerControl;
extern xTransferLayerControlT OV2640_JPEG_TransferLayerControl;
//------------------------------------------------------------------------------
extern void OV2640_RequestGetSnapshotRGB565(xRxT* rx, xDataBufferT* data_buffer);
extern void OV2640_RequestGetSnapshotJPEG(xRxT* rx, xDataBufferT* data_buffer);
extern void OV2640_RequestGetOptions(xRxT* rx, xDataBufferT* data_buffer);
extern void OV2640_RequestGetStatus(xRxT* rx, xDataBufferT* data_buffer);

extern void OV2640_RequestSetOptions(xRxT* rx, xDataBufferT* data_buffer, OV2640_DriverOptionsT* options);
extern void OV2640_RequestSetOutputFormat(xRxT* rx, xDataBufferT* data_buffer, OV2640_OutputFormats* output_format);
extern void OV2640_RequestSetResolution(xRxT* rx, xDataBufferT* data_buffer, OV2640_Resolutions* resolution);
extern void OV2640_RequestSetSaturation(xRxT* rx, xDataBufferT* data_buffer, OV2640_Saturations* saturation);
extern void OV2640_RequestSetContrast(xRxT* rx, xDataBufferT* data_buffer, OV2640_Contrasts* contrast);
extern void OV2640_RequestSetBrightness(xRxT* rx, xDataBufferT* data_buffer, OV2640_Brightnesses* brightness);
extern void OV2640_RequestSetLightMode(xRxT* rx, xDataBufferT* data_buffer, OV2640_LightModes* light_mode);
extern void OV2640_RequestSetSpecialEffect(xRxT* rx, xDataBufferT* data_buffer, OV2640_SpecialEffects* special_effect);
extern void OV2640_RequestSetQuantization(xRxT* rx, xDataBufferT* data_buffer, OV2640_Quantizations* quantization);
extern void OV2640_RequestSetAGC_Gain(xRxT* rx, xDataBufferT* data_buffer, uint8_t* gain);
extern void OV2640_RequestSetConfiguration(xRxT* rx, xDataBufferT* data_buffer, uint8_t* data, uint16_t data_size);
//==============================================================================
#ifdef __cplusplus
}
#endif
//------------------------------------------------------------------------------
#endif /* __OV2640_REQUESTS_H */

