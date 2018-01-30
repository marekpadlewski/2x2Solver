#include "StatesComputor.h"
#include "CyclicBuffer.h"
#include "Moves.h"
#include "CubeStateMap.h"

void computeClosestPaths()
{
    //using Breadth-First Search algorithm

    cyclic_buffer Buffer;
    bufferInit(&Buffer, 1000000);

    CubeState start = solved();
    insertState(start, 0);
    bufferPushBack(&Buffer, start);

    while (Buffer.count != 0)
    {
        CubeState current = bufferPop(&Buffer);

        for (int i = 0 ; i < 9 ; i++)
        {
            CubeState neighbour = moves[i](current);

            if (isStateInMap(neighbour) == 0)
            {
                insertState(neighbour, getState(current) + 1);
                bufferPushBack(&Buffer, neighbour);
            }
        }
    }

    bufferFree(&Buffer);
}

int movesToSolved(CubeState *state)
{
    return getState(*state);
}
