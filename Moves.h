#pragma once

#include "CubeState.h"

CubeState move_R(CubeState state);
CubeState move_R2(CubeState state);
CubeState move_Rp(CubeState state);
CubeState move_F(CubeState state);
CubeState move_F2(CubeState state);
CubeState move_Fp(CubeState state);
CubeState move_U(CubeState state);
CubeState move_U2(CubeState state);
CubeState move_Up(CubeState state);

typedef CubeState (*move_fn)(CubeState);

extern move_fn moves[];
extern char move_symbols[];
