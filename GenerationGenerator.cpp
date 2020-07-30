//
// Created by Gabriela Brankova on 2020-07-30.
//

#include "GenerationGenerator.h"

GenerationGenerator::GenerationGenerator(std::vector<std::vector<bool>> _currentGridData) {
    gridData = _currentGridData;
}

bool GenerationGenerator::generateCell(Coordinates cellCoordinates) {
    int cellRow = cellCoordinates.first;
    int cellColumn = cellCoordinates.second;
    unsigned long maxRowIndex = gridData.size() - 1;
    unsigned long maxColumnIndex = gridData[1].size() - 1;
    std::map<std::string, int> neighbouringColours;
    neighbouringColours["unknown"] = 0;
    neighbouringColours["green"] = 0;
    neighbouringColours["red"] = 0;

    for (int rowOffset : {-1, 0, 1}) {
        for (int colOffset : {-1, 0, 1}) {
            if (rowOffset != 0 || colOffset != 0) {
                int newCellRow = cellRow + rowOffset;
                int newCellColumn = cellColumn + colOffset;
                if (newCellRow < 0           ||
                    newCellColumn < 0        ||
                    newCellRow > maxRowIndex ||
                    newCellColumn > maxColumnIndex) {
                    neighbouringColours["unknown"]++;
                } else {
                    if(gridData[newCellRow][newCellColumn]) {
                        neighbouringColours["green"]++;
                    } else {
                        neighbouringColours["red"]++;
                    }
                }
            }
        }
    }

    // TODO!!
    if(gridData[cellCoordinates.first][cellCoordinates.second]) {
        // The cell whose value is being generated is initially green
        int numGreenCells = neighbouringColours["green"];
        return numGreenCells == 2 || numGreenCells == 3 || numGreenCells == 6;
    } else {
        // The cell whose value is being generated is initially red
        int numGreenCells = neighbouringColours["green"];
        return numGreenCells == 3 || numGreenCells == 6;
    }
}
