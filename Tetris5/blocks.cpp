#include "blocks.h"

void GetBlockShape(int blockType, int rotationState, Position* positions, int& numPositions)
{
    numPositions = 4;

    switch (blockType) {
    case O_BLOCK:
        positions[0] = { 0, 0 }; positions[1] = { 0, 1 }; positions[2] = { 1, 0 }; positions[3] = { 1, 1 };
        break;
    case I_BLOCK:
        if (rotationState % 2 == 0) {
            positions[0] = { 0, -1 }; positions[1] = { 0, 0 }; positions[2] = { 0, 1 }; positions[3] = { 0, 2 };
        }
        else {
            positions[0] = { -1, 0 }; positions[1] = { 0, 0 }; positions[2] = { 1, 0 }; positions[3] = { 2, 0 };
        }
        break;
    case T_BLOCK:
        if (rotationState == 0) {
            positions[0] = { 0, -1 }; positions[1] = { 0, 0 }; positions[2] = { 0, 1 }; positions[3] = { 1, 0 };
        }
        else if (rotationState == 1) {
            positions[0] = { -1, 0 }; positions[1] = { 0, 0 }; positions[2] = { 1, 0 }; positions[3] = { 0, 1 };
        }
        else if (rotationState == 2) {
            positions[0] = { 0, -1 }; positions[1] = { 0, 0 }; positions[2] = { 0, 1 }; positions[3] = { -1, 0 };
        }
        else {
            positions[0] = { -1, 0 }; positions[1] = { 0, 0 }; positions[2] = { 1, 0 }; positions[3] = { 0, -1 };
        }
        break;
    case J_BLOCK:
        if (rotationState == 0) {
            positions[0] = { 0, -1 }; positions[1] = { 0, 0 }; positions[2] = { 0, 1 }; positions[3] = { 1, 1 };
        }
        else if (rotationState == 1) {
            positions[0] = { -1, 0 }; positions[1] = { 0, 0 }; positions[2] = { 1, 0 }; positions[3] = { 1, -1 };
        }
        else if (rotationState == 2) {
            positions[0] = { 0, -1 }; positions[1] = { 0, 0 }; positions[2] = { 0, 1 }; positions[3] = { -1, -1 };
        }
        else {
            positions[0] = { -1, 0 }; positions[1] = { 0, 0 }; positions[2] = { 1, 0 }; positions[3] = { -1, 1 };
        }
        break;
    case L_BLOCK:
        if (rotationState == 0) {
            positions[0] = { 0, -1 }; positions[1] = { 0, 0 }; positions[2] = { 0, 1 }; positions[3] = { 1, -1 };
        }
        else if (rotationState == 1) {
            positions[0] = { -1, 0 }; positions[1] = { 0, 0 }; positions[2] = { 1, 0 }; positions[3] = { 1, 1 };
        }
        else if (rotationState == 2) {
            positions[0] = { 0, -1 }; positions[1] = { 0, 0 }; positions[2] = { 0, 1 }; positions[3] = { -1, 1 };
        }
        else {
            positions[0] = { -1, 0 }; positions[1] = { 0, 0 }; positions[2] = { 1, 0 }; positions[3] = { -1, -1 };
        }
        break;
    case S_BLOCK:
        if (rotationState % 2 == 0) {
            positions[0] = { 0, -1 }; positions[1] = { 0, 0 }; positions[2] = { 1, 0 }; positions[3] = { 1, 1 };
        }
        else {
            positions[0] = { -1, 0 }; positions[1] = { 0, 0 }; positions[2] = { 0, -1 }; positions[3] = { 1, -1 };
        }
        break;
    case Z_BLOCK:
        if (rotationState % 2 == 0) {
            positions[0] = { 0, 0 }; positions[1] = { 0, 1 }; positions[2] = { 1, -1 }; positions[3] = { 1, 0 };
        }
        else {
            positions[0] = { -1, -1 }; positions[1] = { 0, -1 }; positions[2] = { 0, 0 }; positions[3] = { 1, 0 };
        }
        break;
    default:
        break;
    }
}