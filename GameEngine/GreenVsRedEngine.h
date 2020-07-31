//
// Created by Gabriela Brankova on 2020-07-30.
//

#ifndef GREEN_VS_RED_GREENVSREDENGINE_H
#define GREEN_VS_RED_GREENVSREDENGINE_H

#include "../Grid/Grid.h"

/*
 * The class that drives the whole game. It contains a particular Grid object, the coordinates
 * of the cell in the grid we are examining for being green and the final generation up to
 * which the game is being played.
 *
 * */

class GreenVsRedEngine {
public:

    GreenVsRedEngine();

    int play();

    ~GreenVsRedEngine();

private:

    void readGameParameters();

    std::vector<std::string> split(std::string data);

    Grid *grid;

    Coordinates cellCoordinates;

    int finalGeneration;
};

#endif //GREEN_VS_RED_GREENVSREDENGINE_H
