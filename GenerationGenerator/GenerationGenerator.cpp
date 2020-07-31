#include "GenerationGenerator.h"

GenerationGenerator::GenerationGenerator(const TwoDimensionalGrid &_currentGridData) {
    gridData = _currentGridData;
}

bool GenerationGenerator::generateCell(const Coordinates &cellCoordinates) {
    int greenNeighboursCount = countGreenNeighbours(cellCoordinates);

    if (gridData[cellCoordinates.first][cellCoordinates.second]) {
        // The cell whose value is being generated is initially green
        return greenNeighboursCount == 2 || greenNeighboursCount == 3 || greenNeighboursCount == 6;
    } else {
        // The cell whose value is being generated is initially red
        return greenNeighboursCount == 3 || greenNeighboursCount == 6;
    }
}

int GenerationGenerator::countGreenNeighbours(const Coordinates &cellCoordinates) {
    unsigned long maxRowIndex = gridData.size() - 1;
    unsigned long maxColumnIndex = gridData[1].size() - 1;
    int greenNeighboursCount = 0;

    for (int rowOffset : {-1, 0, 1}) {
        for (int colOffset : {-1, 0, 1}) {
            if (rowOffset != 0 || colOffset != 0) {
                int newCellRow = cellCoordinates.first + rowOffset;
                int newCellColumn = cellCoordinates.second + colOffset;
                if (newCellRow >= 0 &&
                    newCellColumn >= 0 &&
                    newCellRow <= maxRowIndex &&
                    newCellColumn <= maxColumnIndex &&
                    gridData[newCellRow][newCellColumn]) {
                    greenNeighboursCount++;
                }
            }
        }
    }
    return greenNeighboursCount;
}