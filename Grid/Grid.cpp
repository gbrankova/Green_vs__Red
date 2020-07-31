#include "Grid.h"
#include "../GenerationGenerator/GenerationGenerator.h"

Grid::Grid(const Dimensions &_gridDimensions, const TwoDimensionalGrid &_gridData) {
    gridDimensions = _gridDimensions;
    gridData = _gridData;
    gridGeneration = 0;
}

bool Grid::getCellValue(const Coordinates &cellCoordinates) {
    return gridData[cellCoordinates.first][cellCoordinates.second];
}


void Grid::calculateNextGeneration() {
    GenerationGenerator generationGenerator = GenerationGenerator(gridData);
    for (int row = 0; row < gridDimensions.height; row++) {
        for (int col = 0; col < gridDimensions.width; col++) {
            gridData[row][col] = generationGenerator.generateCell({row, col});
        }
    }
    gridGeneration++;
}

bool Grid::areCoordinatesValid(const Coordinates &cellCoordinates) {
    return cellCoordinates.first >= 0 && cellCoordinates.first < gridDimensions.height &&
           cellCoordinates.second >= 0 && cellCoordinates.second < gridDimensions.width;
}