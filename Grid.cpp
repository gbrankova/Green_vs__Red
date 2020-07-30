//
// Created by Gabriela Brankova on 2020-07-30.
//

#include "Grid.h"

Grid::Grid(Dimensions _gridDimensions, std::vector<std::vector<bool>> _gridData) {
    gridDimensions = _gridDimensions;
    gridData = _gridData;
    generationNumber = 0;
}

int Grid::getHeight() { return gridDimensions.height; }

int Grid::getWidth() { return gridDimensions.width; }

int Grid::getGenerationNumber() { return generationNumber; }

bool Grid::getCellValue(int w, int h) {
    return gridData[w][h];
}

void Grid::getNextGeneration() {
    GenerationGenarator generationGenerator = GenerationGenerator(gridData)
    for(int i = 0; i < gridDimensions.width; i++) {
        for(int j = 0; j < gridDimensions.height; j++) {
            gridData[i][j] = generationGenerator.generateCell(i , j);
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