//
// Created by Gabriela Brankova on 2020-07-30.
//

#include "GridReader.h"

int guardedStoi(const std::string &numStr, int *num);

Grid *GridReader::readGrid() {
    Dimensions gridDimensions = readDimensions();
    TwoDimensionalGrid gridData = readGridData(gridDimensions.height);
    return new Grid(gridDimensions, gridData);
}

std::vector<std::vector<bool>> GridReader::readGridData(int height) {
    TwoDimensionalGrid gridData;
    std::string rowDataStr;
    std::string cellData;
    std::cout << "Please enter Generation Zero of the 2D grid: " << std::endl;
    for (int row = 0; row < height; row++) {
        std::cout << "Row #" << row << ": ";
        std::vector<bool> rowData;
        std::getline(std::cin, rowDataStr);
        std::istringstream rowDataStream(rowDataStr);
        while (rowDataStream >> cellData) {
            rowData.push_back(cellData != "0");
        }
        gridData.push_back(rowData);
    }
    return gridData;
}

Dimensions GridReader::readDimensions() {
    std::string dimensions;
    std::pair<std::string, std::string> dimensionsStr;
    int conversionResult = 0;
    int width = 1;
    int height = 0;

    while (conversionResult || width > height || height >= 1000) {
        std::cout << "Please enter the dimensions of the 2D grid "
                     "(format: W, H where W - width, H - height, W <= H and H < 1000): ";
        std::getline(std::cin, dimensions);
        dimensionsStr = splitDimensions(dimensions);
        conversionResult = guardedStoi(dimensionsStr.first, &width);
        conversionResult = conversionResult ? conversionResult : guardedStoi(dimensionsStr.second, &height);
    }

    return {width, height};
}

std::pair<std::string, std::string> GridReader::splitDimensions(std::string dimensions) {
    unsigned long delimiterPos = dimensions.find(", ");
    return {dimensions.substr(0, delimiterPos), dimensions.substr(delimiterPos + 2)};
}