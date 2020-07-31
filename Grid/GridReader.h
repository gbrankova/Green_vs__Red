#ifndef GREEN_VS_RED_GRIDREADER_H
#define GREEN_VS_RED_GRIDREADER_H

#include <string>
#include <sstream>
#include "Grid.h"

/*
 * A class that is used for reading the input data regarding the dimensions and content of the grid.
 * All member function are static and belong to the class because they are not related to a particular object.
 * They could be invoked even without an existing instance of the GridReader class.
 *
 * */

class GridReader {
public:

    static Grid *readGrid();

private:

    static Dimensions readDimensions();

    static TwoDimensionalGrid readGridData(int height);

    static std::pair<std::string, std::string> splitDimensions(const std::string &dimensions);
};

#endif //GREEN_VS_RED_GRIDREADER_H
