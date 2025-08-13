#pragma once
#include "position.h"

const int O_BLOCK = 0;
const int I_BLOCK = 1;
const int T_BLOCK = 2;
const int J_BLOCK = 3;
const int L_BLOCK = 4;
const int S_BLOCK = 5;
const int Z_BLOCK = 6;


const int NUM_BLOCK_TYPES = 7;

void GetBlockShape(int blockType, int rotationState, Position* positions, int& numPositions);
