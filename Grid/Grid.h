//
// Created by Gabriela Brankova on 2020-07-29.
//

#ifndef GREEN_VS_RED_GRID_H
#define GREEN_VS_RED_GRID_H

#include <vector>
#include <iostream>

using Coordinates = std::pair<int, int>;
using TwoDimensionalGrid = std::vector<std::vector<bool>>;

// A simple abstraction for the dimensions of the grid
struct Dimensions {
    Dimensions(int _width = 0, int _height = 0) {
        width = _width;
        height = _height;
    }

    int width;
    int height;
};

/*
 * An abstraction that contains the 2D grid, its dimensions (width and height) and its current generation.
 * A Grid object can only be created by the GridReader class which is an abstraction used for reading the data
 * for a grid from the user. This restriction about who can created instances of the Grid class is accomplished
 * with a private constructor.
 *
 * */

class Grid {
public:

    friend class GridReader;

    void calculateNextGeneration();

    bool getCellValue(const Coordinates &cellCoordinates);

    bool areCoordinatesValid(const Coordinates &cellCoordinates);

private:

    Grid(const Dimensions &_gridDimensions, const TwoDimensionalGrid &_gridData);

    TwoDimensionalGrid gridData;

    Dimensions gridDimensions;

    int gridGeneration;
};

#endif //GREEN_VS_RED_GRID_H
