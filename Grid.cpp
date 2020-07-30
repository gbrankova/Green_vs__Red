//
// Created by Gabriela Brankova on 2020-07-30.
//

#include "Grid.h"
#include "GenerationGenerator.h"

Grid::Grid(Dimensions _gridDimensions, std::vector<std::vector<bool>> _gridData) {
    gridDimensions = _gridDimensions;
    gridData = _gridData;
    generationNumber = 0;
}

bool Grid::getCellValue(Coordinates cellCoords) {
    return gridData[cellCoords.first][cellCoords.second];
}


void Grid::getNextGeneration() {
    GenerationGenerator generationGenerator = GenerationGenerator(gridData);
    for(int row = 0; row < gridDimensions.height; row++) {
        for(int col = 0; col < gridDimensions.width; col++) {
            gridData[row][col] = generationGenerator.generateCell({row, col});
        }
    }
    generationNumber++;
}

void Grid::printGrid() {
    for(int i = 0; i < gridDimensions.height; i++) {
        for(int j = 0; j < gridDimensions.width;  j++) {
            std::cout << gridData[i][j] << " ";
        }
        std::cout << std::endl;
    }
}