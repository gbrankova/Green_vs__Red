//
// Created by Gabriela Brankova on 2020-07-30.
//

#include "GreenVsRedEngine.h"
#include "GridReader.h"

GreenVsRedEngine::GreenVsRedEngine() {
    GridReader reader = GridReader();
    grid = reader.readGrid();
    cellCordinates = {-1, -1};
    finalGeneration = 0;
}

int GreenVsRedEngine::play() {
    readGameParameters();

    int resultCount = grid->getCellValue(cellCordinates);
    grid->printGrid();
    for(int i = 0; i < finalGeneration; i++) {
        grid->getNextGeneration();
        grid->printGrid();
        std::cout << std::endl;
        resultCount += grid->getCellValue(cellCordinates);
    }
    return resultCount;
}

void GreenVsRedEngine::readGameParameters() {
    std::string inputData;
    std::vector<std::string> data;
    int conversionResult = -1;

    // isValid??
    while(conversionResult) {
        std::cout << "Please enter R, C, G where R and C are the row and the column "
                     "where the cell is located and G is the generation up to which the game is played: ";
        std::getline(std::cin, inputData);
        data = split(inputData);
        if(data.size() == 3) {
            conversionResult = guardedStoi(data[0], &cellCordinates.second);
            conversionResult = conversionResult ? conversionResult : guardedStoi(data[1], &cellCordinates.first);
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

int GreenVsRedEngine::guardedStoi(std::string numStr, int *num) {
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