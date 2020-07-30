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

    void printGrid();
private:
    Grid(Dimensions _gridDimensions, std::vector<std::vector<bool>> _gridData);

    std::vector<std::vector<bool>> gridData;

    Dimensions gridDimensions;

    int generationNumber;
};

#endif //GREEN_VS_RED_GRID_H
