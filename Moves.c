#include "Moves.h"
#include "CubeState.h"

move_fn moves[] = {move_R, move_R2, move_Rp,
                   move_F, move_F2, move_Fp,
                   move_U, move_U2, move_Up};

char move_symbols[] = {'R', '1', 'r', 'F', '2',
                       'f', 'U', '3', 'u'};


CubeState move_R(CubeState state) {
    CubeState result;

    result.p0 = state.p4;
    result.p1 = state.p1;
    result.p2 = state.p2;
    result.p3 = state.p0;
    result.p4 = state.p7;
    result.p5 = state.p5;
    result.p7 = state.p3;

    result.o0 = (state.o4+2)%3;
    result.o1 = state.o1;
    result.o2 = state.o2;
    result.o3 = (state.o0+1)%3;
    result.o4 = (state.o7+1)%3;
    result.o5 = state.o5;
    result.o7 = (state.o3+2)%3;

    return result;
}

CubeState move_R2(CubeState state) {
    CubeState result;

    result.p0 = state.p7;
    result.p1 = state.p1;
    result.p2 = state.p2;
    result.p3 = state.p4;
    result.p4 = state.p3;
    result.p5 = state.p5;
    result.p7 = state.p0;

    result.o0 = state.o7;
    result.o1 = state.o1;
    result.o2 = state.o2;
    result.o3 = state.o4;
    result.o4 = state.o3;
    result.o5 = state.o5;
    result.o7 = state.o0;
    return result;
}

CubeState move_Rp(CubeState state) {
    CubeState result;

    result.p0 = state.p3;
    result.p1 = state.p1;
    result.p2 = state.p2;
    result.p3 = state.p7;
    result.p4 = state.p0;
    result.p5 = state.p5;
    result.p7 = state.p4;

    result.o0 = (state.o3+2)%3;
    result.o1 = state.o1;
    result.o2 = state.o2;
    result.o3 = (state.o7+1)%3;
    result.o4 = (state.o0+1)%3;
    result.o5 = state.o5;
    result.o7 = (state.o4+2)%3;

    return result;
}

CubeState move_F(CubeState state) {
    CubeState result;

    result.p0 = state.p1;
    result.p1 = state.p5;
    result.p2 = state.p2;
    result.p3 = state.p3;
    result.p4 = state.p0;
    result.p5 = state.p4;
    result.p7 = state.p7;

    result.o0 = (state.o1+1)%3;
    result.o1 = (state.o5+2)%3;
    result.o2 = state.o2;
    result.o3 = state.o3;
    result.o4 = (state.o0+2)%3;
    result.o5 = (state.o4+1)%3;
    result.o7 = state.o7;

    return result;
}

CubeState move_F2(CubeState state) {
    CubeState result;

    result.p0 = state.p5;
    result.p1 = state.p4;
    result.p2 = state.p2;
    result.p3 = state.p3;
    result.p4 = state.p1;
    result.p5 = state.p0;
    result.p7 = state.p7;

    result.o0 = state.o5;
    result.o1 = state.o4;
    result.o2 = state.o2;
    result.o3 = state.o3;
    result.o4 = state.o1;
    result.o5 = state.o0;
    result.o7 = state.o7;
    return result;
}

CubeState move_Fp(CubeState state) {
    CubeState result;

    result.p0 = state.p4;
    result.p1 = state.p0;
    result.p2 = state.p2;
    result.p3 = state.p3;
    result.p4 = state.p5;
    result.p5 = state.p1;
    result.p7 = state.p7;

    result.o0 = (state.o4+1)%3;
    result.o1 = (state.o0+2)%3;
    result.o2 = state.o2;
    result.o3 = state.o3;
    result.o4 = (state.o5+2)%3;
    result.o5 = (state.o1+1)%3;
    result.o7 = state.o7;

    return result;
}

CubeState move_U(CubeState state) {
    CubeState result;

    result.p0 = state.p3;
    result.p1 = state.p0;
    result.p2 = state.p1;
    result.p3 = state.p2;
    result.p4 = state.p4;
    result.p5 = state.p5;
    result.p7 = state.p7;

    result.o0 = state.o3;
    result.o1 = state.o0;
    result.o2 = state.o1;
    result.o3 = state.o2;
    result.o4 = state.o4;
    result.o5 = state.o5;
    result.o7 = state.o7;

    return result;
}

CubeState move_U2(CubeState state) {
    CubeState result;

    result.p0 = state.p2;
    result.p1 = state.p3;
    result.p2 = state.p0;
    result.p3 = state.p1;
    result.p4 = state.p4;
    result.p5 = state.p5;
    result.p7 = state.p7;

    result.o0 = state.o2;
    result.o1 = state.o3;
    result.o2 = state.o0;
    result.o3 = state.o1;
    result.o4 = state.o4;
    result.o5 = state.o5;
    result.o7 = state.o7;

    return result;
}

CubeState move_Up(CubeState state) {
    CubeState result;

    result.p0 = state.p1;
    result.p1 = state.p2;
    result.p2 = state.p3;
    result.p3 = state.p0;
    result.p4 = state.p4;
    result.p5 = state.p5;
    result.p7 = state.p7;

    result.o0 = state.o1;
    result.o1 = state.o2;
    result.o2 = state.o3;
    result.o3 = state.o0;
    result.o4 = state.o4;
    result.o5 = state.o5;
    result.o7 = state.o7;

    return result;
}
