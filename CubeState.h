#pragma once

#include "stdbool.h"
#include <string.h>

typedef struct {
    unsigned p0 : 3;
    unsigned p1 : 3;
    unsigned p2 : 3;
    unsigned p3 : 3;
    unsigned p4 : 3;
    unsigned p5 : 3;
    unsigned p7 : 3;

    unsigned o0 : 2;
    unsigned o1 : 2;
    unsigned o2 : 2;
    unsigned o3 : 2;
    unsigned o4 : 2;
    unsigned o5 : 2;
    unsigned o7 : 2;
} CubeState;

CubeState solved();
bool isSame(CubeState lhs, CubeState rhs);
unsigned long long serialize(CubeState state);
CubeState deserialize(unsigned long long state_value);
