//
// Created by Gabriela Brankova on 2020-07-29.
//

#ifndef GREEN_VS_RED_GRIDREADER_H
#define GREEN_VS_RED_GRIDREADER_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "Grid.h"

class GridReader {
public:
    GridReader();

    Grid* readGrid();

private:
    Dimensions readDimensions();

    std::vector<std::vector<bool>> readGridData(int height);

    int guardedStoi(std::string numStr, int *num);
};

#endif //GREEN_VS_RED_GRIDREADER_H
