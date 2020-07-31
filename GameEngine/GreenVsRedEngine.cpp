//
// Created by Gabriela Brankova on 2020-07-30.
//

#include "GreenVsRedEngine.h"
#include "../Grid/GridReader.h"

int guardedStoi(const std::string &numStr, int *num);

GreenVsRedEngine::GreenVsRedEngine() {
    grid = GridReader::readGrid();
    cellCoordinates = {-1, -1};
    finalGeneration = 0;
}

int GreenVsRedEngine::play() {
    readGameParameters();

    int resultCount = grid->getCellValue(cellCoordinates);
    for (int i = 0; i < finalGeneration; i++) {
        grid->calculateNextGeneration();
        resultCount += grid->getCellValue(cellCoordinates);
    }
    return resultCount;
}

void GreenVsRedEngine::readGameParameters() {
    std::string inputData;
    std::vector<std::string> data;
    int conversionResult = -1;

    /*
     * If game parameters (the coordinates of the cell and the generation number)
     * are not valid the user is prompted to enter them again.
     *
     * */
    while (conversionResult || !grid->areCoordinatesValid(cellCoordinates)) {
        std::cout << "Please enter R, C, G where R and C are the row and the column "
                     "where the cell is located and G is the generation up to which the game is played: ";
        std::getline(std::cin, inputData);
        data = split(inputData);
        if (data.size() == 3) {
            conversionResult = guardedStoi(data[0], &cellCoordinates.second);
            conversionResult = conversionResult ? conversionResult : guardedStoi(data[1], &cellCoordinates.first);
            conversionResult = conversionResult ? conversionResult : guardedStoi(data[2], &finalGeneration);
        }
    }
}

std::vector<std::string> GreenVsRedEngine::split(std::string data) {
    std::vector<std::string> splitData;
    std::string token;

    unsigned long indexOfDelimiter = data.find_first_of(", ");

    while (indexOfDelimiter != std::string::npos) {
        token = data.substr(0, indexOfDelimiter);
        if (!token.empty()) {
            splitData.push_back(token);
        }
        data = data.substr(indexOfDelimiter + 2);
        indexOfDelimiter = data.find_first_of(", ");
    }

    if (!data.empty()) {
        splitData.push_back(data);
    }
    return splitData;
}

GreenVsRedEngine::~GreenVsRedEngine() {
    delete grid;
}