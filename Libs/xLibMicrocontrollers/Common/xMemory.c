//==============================================================================
#include "xMemory.h"
//==============================================================================
uint32_t xMemoryCopy(void* destiny, void* data, uint32_t size)
{
	for (uint32_t i = 0; i < size; i++)
	{
		((uint8_t*)destiny)[i] = ((uint8_t*)data)[i];
	}
	
	return size;
}
//==============================================================================
