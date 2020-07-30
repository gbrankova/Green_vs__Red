//
// Created by Gabriela Brankova on 2020-07-29.
//

#ifndef GREEN_VS_RED_GRID_H
#define GREEN_VS_RED_GRID_H

#include <vector>
#include <iostream>
#include "GridDimensions.cpp"

using Coordinates = std::pair<int, int>;

class Grid {
public:
    friend class GridReader;

    bool getCellValue(Coordinates cellCoords);

    void getNextGeneration();

    void printGrid();

private:
    Grid(Dimensions _gridDimensions, std::vector<std::vector<bool>> _gridData);

    std::vector<std::vector<bool>> gridData;

    Dimensions gridDimensions;

    int generationNumber;
};

#endif //GREEN_VS_RED_GRID_H
