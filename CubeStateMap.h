#pragma once

#include "CubeState.h"
#include "StatesComputor.h"
#include <stdio.h>

void insertState(CubeState state, int move_no);
int getState(CubeState state);
unsigned long isStateInMap(CubeState state);
void clearMap();
void forEachElement(void(*fun)(CubeState key, int val));