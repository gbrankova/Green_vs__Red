//
// Created by Gabriela Brankova on 2020-07-29.
//

#ifndef GREEN_VS_RED_GRID_H
#define GREEN_VS_RED_GRID_H

#include <vector>
#include "GridReader.h"

class Grid {
public:
    friend class GridReader;

    int getHeight();

    int getWidth();

    int getGenerationNumber();

    bool getCellValue(int w, int h);

    void getNextGeneration();
private:
    Grid(Dimensions _gridDimensions, std::vector<std::vector<bool> _gridData);

    std::vector<std::vector<bool>> gridData;
    Dimensions gridDimensions;
    int generationNumber;
};

Grid::Grid(Dimensions _gridDimensions, std::vector<std::vector<bool> _gridData) {
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

#endif //GREEN_VS_RED_GRID_H
