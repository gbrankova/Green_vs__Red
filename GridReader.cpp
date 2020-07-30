//
// Created by Gabriela Brankova on 2020-07-30.
//

#include "GridReader.h"

GridReader::GridReader() {}

Grid* GridReader::readGrid() {
    Dimensions gridDimensions= readDimensions();
    std::vector<std::vector<bool>> gridData = readGridData(gridDimensions.height);
    return new Grid(gridDimensions, gridData);
}

std::vector<std::vector<bool>> GridReader::readGridData(int height) {
    std::vector<std::vector<bool>> gridData;
    std::string rowDataStr;
    std::string cellData;
    std::cout << "Please enter Generation Zero of the 2D grid" << std::endl;
    for(int row = 0; row < height; row++){
        std::cout << "Row #" << row << ": ";
        std::vector<bool> rowData;
        std::getline(std::cin, rowDataStr);
        std::istringstream rowDataStream(rowDataStr);
        while(rowDataStream >> cellData) {
            rowData.push_back(cellData != "0");
        }
        gridData.push_back(rowData);
    }
    return gridData;
}

Dimensions GridReader::readDimensions() {
    std::string dimensions;
    unsigned long delimeterPos;
    std::string widthStr;
    std::string heightStr;
    int conversionResult = 0;
    int width = 1;
    int height = 0;

    while(conversionResult || width > height || height >= 1000) {
        std::cout << "Please enter the dimensions of the 2D grid (format: W, H where W - width, H - height, W <= H and H < 1000): ";
        std::string dimensions;
        std::getline(std::cin, dimensions);
        delimeterPos = dimensions.find(", ");
        widthStr = dimensions.substr(0, delimeterPos);
        heightStr = dimensions.substr(delimeterPos + 2);
        conversionResult = guardedStoi(widthStr, &width);
        conversionResult = conversionResult ? conversionResult : guardedStoi(heightStr, &height);
    }

    return Dimensions(width, height);
}

int GridReader::guardedStoi(std::string numStr, int *num) {
    try {
        *num = std::stoi(numStr);
        return 0;
    } catch (const std::invalid_argument& ia) {
        std::cout << "Invalid number: " << numStr << std::endl;
        std::cout << "Try again!" << std::endl;
        return -1;
    } catch (const std::out_of_range& oor) {
        std::cout << "Number out of range: " << numStr << std::endl;
        std::cout << "Try again!" << std::endl;
        return -1;
    } catch (const std::exception& e) {
        std::cout << "Unidentified error with number: " << numStr << std::endl;
        std::cout << "Try again!" << std::endl;
        return -1;
    }
}