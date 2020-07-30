//
// Created by Gabriela Brankova on 2020-07-30.
//

#ifndef GREEN_VS_RED_GENERATIONGENERATOR_H
#define GREEN_VS_RED_GENERATIONGENERATOR_H

#include "Grid.h"

/* An abstraction used for calculating/generating the new generation of a Grid object.
 * Each instance of this class holds a copy of the the 2D grid field of a particular
 * Grid object. The copy is used for determining the new values of the cells. */

class GenerationGenerator {
public:
    explicit GenerationGenerator(const TwoDimensionalGrid &_currentGridData);

    bool generateCell(Coordinates cellCoordinates);

private:
    int countGreenNeighbours(Coordinates cellCoordinates);

    TwoDimensionalGrid gridData;
};

#endif //GREEN_VS_RED_GENERATIONGENERATOR_H
