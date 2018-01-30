#pragma once

#include "CubeStateMap.h"
#include <stdio.h>

void printStates(CubeState key, int value);
void writeStates(FILE *fp2);
void readStates(FILE *fp);