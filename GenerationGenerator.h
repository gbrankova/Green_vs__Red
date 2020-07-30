//
// Created by Gabriela Brankova on 2020-07-30.
//

#ifndef GREEN_VS_RED_GENERATIONGENERATOR_H
#define GREEN_VS_RED_GENERATIONGENERATOR_H

#include <vector>
#include <map>
#include "Grid.h"

class GenerationGenerator {
public:
    GenerationGenerator(std::vector<std::vector<bool>> _currentGridData);

    bool generateCell(Coordinates cellCoordinates);

private:
    std::vector<std::vector<bool>> gridData;
};

#endif //GREEN_VS_RED_GENERATIONGENERATOR_H
