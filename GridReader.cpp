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
    std::string rowData;
    std::string cellData;
    for(int row = 0; row < height; row++){
        std::getline(std::cin, rowData);
        std::istringstream rowDataStream(rowData);
        for(int column = 0; column < rowData.length(); column++) {
            rowDataStream >> cellData;
            gridData[row][column] = cellData == "0";
        }
    }
    return gridData;
}

Dimensions GridReader::readDimensions() {
    std::string dimensions;
    unsigned long delimeterPos;
    std::string widthStr;
    std::string heightStr;
    int conversionResult = 0;
    int width = 0;
    int height = 0;

    while(conversionResult || width > height || height >= 1000) {
        std::string dimensions;
        std::getline(std::cin, dimensions);
        delimeterPos = dimensions.find(", ");
        widthStr = dimensions.substr(0, delimeterPos);
        heightStr = dimensions.substr(delimeterPos + 2);
        conversionResult = _stoi(widthStr, &width);
        conversionResult = conversionResult ? conversionResult : _stoi(heightStr, &height);
    }

    return Dimensions(width, height);
}

int GridReader::_stoi(std::string numStr, int* num) {
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