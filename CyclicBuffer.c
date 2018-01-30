#include <assert.h>
#include "CyclicBuffer.h"

void bufferInit(cyclic_buffer *cb, unsigned long long capacity)
{
    cb->buffer = calloc(capacity, sizeof(CubeState));
    cb->buffer_end = cb->buffer + capacity;
    cb->count = 0;
    cb->end = cb->buffer;
    cb->front = cb->buffer;
}

void bufferFree(cyclic_buffer *cb)
{
    free(cb->buffer);
}

static void checkAllocation (CubeState *x)
{
    if (x == NULL)
    {
        fprintf(stderr, "Couldn't allocate memory");
        exit(1);
    }
}

void resizeBuffer(cyclic_buffer *cb)
{
    unsigned long long capacity_before_realloc = cb->buffer_end - cb->buffer;
    unsigned long long new_capacity = capacity_before_realloc*2;
    unsigned long long frontDistance = cb->front - cb->buffer;
    unsigned long long endDistance = cb->end - cb->buffer;

    cb->buffer = realloc(cb->buffer, new_capacity * sizeof(CubeState));
    checkAllocation(cb->buffer);

    cb->buffer_end = cb->buffer + new_capacity;
    cb->front = cb->buffer + frontDistance;
    cb->end = cb->buffer + endDistance;

    CubeState *endOfData = cb->buffer + capacity_before_realloc;
    memcpy(endOfData, cb->buffer, sizeof(CubeState) * (endDistance));
    cb->end = endOfData + endDistance;
}

void bufferPushBack(cyclic_buffer *cb, CubeState state)
{
    assert(cb->end <= cb->buffer_end);

    if (cb->end == cb->front && cb->count > 0)
        resizeBuffer(cb);

    *cb->end = state;
    cb->end = cb->end + 1;
    if(cb->end == cb->buffer_end)
        cb->end = cb->buffer;
    cb->count++;
}

CubeState bufferPop(cyclic_buffer *cb)
{
    assert(cb->front <= cb->buffer_end);
    assert(cb->count > 0);
    CubeState state = *cb->front;
    cb->front = cb->front + 1;
    if(cb->front == cb->buffer_end)
        cb->front = cb->buffer;
    cb->count--;

    return state;
}