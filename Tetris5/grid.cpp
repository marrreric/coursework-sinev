#include "grid.h"
#include "double_linked_list.h"

Grid::Grid(int width, int height) : gridWidth(width), gridHeight(height) {
    cells = new DoubleLinkedList[height];
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            cells[row].Append(new Node(CellNode()));
        }
    }
}

Grid::~Grid() {
    delete[] cells;
}

void Grid::Draw(int cellSize, int offsetX, int offsetY) const {
    for (int row = 0; row < gridHeight; ++row) {
        Node* cell = cells[row].head;
        for (int col = 0; col < gridWidth; ++col) {
            if (!cell->data.isEmpty) {
                int x = col * cellSize + offsetX;
                int y = row * cellSize + offsetY;
                DrawRectangle(x, y, cellSize - 1, cellSize - 1, cell->data.color);
            }
            else {
                int x = col * cellSize + offsetX;
                int y = row * cellSize + offsetY;
                DrawRectangleLines(x, y, cellSize, cellSize, BLACK);
            }
            cell = cell->next;
        }
    }
}

bool Grid::IsCellOutside(int row, int column) const {
    return row < 0 || row >= gridHeight || column < 0 || column >= gridWidth;
}

bool Grid::IsCellEmpty(int row, int column) const {
    if (IsCellOutside(row, column)) {
        return false;
    }

    Node* cellNode = getColumnNode(cells[row], column);
    return cellNode && cellNode->data.isEmpty;
}

void Grid::PlaceBlock(const Position* blockCells, int numCells, Color color) {
    for (int i = 0; i < numCells; ++i) {
        int row = blockCells[i].row;
        int col = blockCells[i].column;

        if (!IsCellOutside(row, col)) {
            Node* cellNode = getColumnNode(cells[row], col);
            if (cellNode) {
                cellNode->data.isEmpty = false;
                cellNode->data.color = color;
            }
        }
    }
}

int Grid::ClearFullRows() const {
    int clearedRows = 0;
    for (int rowIdx = 0; rowIdx < gridHeight; ++rowIdx) {
        bool rowFull = true;

        Node* cell = cells[rowIdx].head;
        while (cell) {
            if (cell->data.isEmpty) {
                rowFull = false;
                break;
            }
            cell = cell->next;
        }

        if (rowFull) {
            // Удаляем текущую строку и перемещаем все строки выше вниз на одну позицию
            for (int moveRow = rowIdx; moveRow > 0; --moveRow) {
                Node* targetCell = cells[moveRow].head;
                Node* sourceCell = cells[moveRow - 1].head;

                for (int col = 0; col < gridWidth; ++col) {
                    targetCell->data = sourceCell->data;
                    targetCell = targetCell->next;
                    sourceCell = sourceCell->next;
                }
            }

            // Очищаем верхнюю строку
            Node* cell = cells[0].head;
            while (cell) {
                cell->data.isEmpty = true;
                cell->data.color = BLANK;
                cell = cell->next;
            }

            clearedRows++;
        }
    }
    return clearedRows;
}

void Grid::Clear() {
    for (int rowIdx = 0; rowIdx < gridHeight; ++rowIdx) {
        cells[rowIdx].Clear();
        for (int colIdx = 0; colIdx < gridWidth; ++colIdx) {
            cells[rowIdx].Append(new Node(CellNode()));
        }
    }
}

Node* Grid::getColumnNode(DoubleLinkedList& row, int column) const {
    return row.GetNodeAt(column);
}