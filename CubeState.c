#include "CubeState.h"

CubeState solved() {
    return (CubeState){0, 1, 2, 3, 4, 5, 7,
                       0, 0, 0, 0, 0, 0, 0};
}

bool isSame(CubeState lhs, CubeState rhs) {

    return lhs.p0 == rhs.p0 && lhs.p1 == rhs.p1 &&
           lhs.p2 == rhs.p2 && lhs.p3 == rhs.p3 &&
           lhs.p4 == rhs.p4 && lhs.p5 == rhs.p5 &&
           lhs.p7 == rhs.p7 &&
           lhs.o0 == rhs.o0 && lhs.o1 == rhs.o1 &&
           lhs.o2 == rhs.o2 && lhs.o3 == rhs.o3 &&
           lhs.o4 == rhs.o4 && lhs.o5 == rhs.o5 &&
           lhs.o7 == rhs.o7;
}

unsigned long long serialize(CubeState state)
{
    unsigned long long value;
    memcpy(&value, &state, sizeof(state));
    return value;
}

CubeState deserialize(unsigned long long state_value)
{
    CubeState state;
    memcpy(&state, &state_value, sizeof(state));
    return state;
}
