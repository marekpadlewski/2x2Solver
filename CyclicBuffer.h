#pragma once

#include "CubeState.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cyclic_buffer
{
    CubeState *buffer;     // data buffer
    CubeState *buffer_end; // end of data buffer
    unsigned long long count;     // number of items in the buffer
    CubeState *end;       // pointer to end
    CubeState *front;      // pointer to front

} cyclic_buffer;

void resizeBuffer(cyclic_buffer *cb);
void bufferInit(cyclic_buffer *cb, unsigned long long capacity);
void bufferFree(cyclic_buffer *cb);
void bufferPushBack(cyclic_buffer *cb, CubeState state);
CubeState bufferPop(cyclic_buffer *cb);
