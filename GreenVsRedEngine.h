//
// Created by Gabriela Brankova on 2020-07-30.
//

#ifndef GREEN_VS_RED_GREENVSREDENGINE_H
#define GREEN_VS_RED_GREENVSREDENGINE_H

#include "Grid.h"

class GreenVsRedEngine {
public:
    GreenVsRedEngine();

    int play();

    ~GreenVsRedEngine();
private:
    std::vector<std::string> split(std::string data);

    void readGameParameters();

    int guardedStoi(std::string numStr, int *num);

    Grid* grid;
    Coordinates cellCordinates;
    int finalGeneration;
};

#endif //GREEN_VS_RED_GREENVSREDENGINE_H
