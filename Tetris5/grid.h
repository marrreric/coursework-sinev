#pragma once

#include "cellnode.h"

#include "position.h"
#include <raylib.h>
#include "double_linked_list.h"

class Grid {
public:
    Grid(int width = 10, int height = 20);
    ~Grid();

    void Draw(int cellSize, int offsetX, int offsetY) const;
    bool IsCellOutside(int row, int column) const;
    bool IsCellEmpty(int row, int column) const;
    void PlaceBlock(const Position* blockCells, int numCells, Color color);
    int ClearFullRows() const;
    void Clear();

    int GetGridWidth() const { return gridWidth; }
    int GetGridHeight() const { return gridHeight; }

private:
    DoubleLinkedList* cells;
    int gridWidth;
    int gridHeight;

    Node* getColumnNode(DoubleLinkedList& row, int column) const;
};