#pragma once
#include <raylib.h> 

struct CellNode {
    bool isEmpty;
    Color color;

    CellNode() : isEmpty(true), color(BLACK) {}
};