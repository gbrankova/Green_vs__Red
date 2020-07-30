//
// Created by Gabriela Brankova on 2020-07-30.
//

#include <iostream>

int guardedStoi(const std::string &numStr, int *num) {
    try {
        *num = std::stoi(numStr);
        return 0;
    } catch (const std::invalid_argument &ia) {
        std::cout << "Invalid number: " << numStr << std::endl;
        std::cout << "Try again!" << std::endl;
        return -1;
    } catch (const std::out_of_range &oor) {
        std::cout << "Number out of range: " << numStr << std::endl;
        std::cout << "Try again!" << std::endl;
        return -1;
    } catch (const std::exception &e) {
        std::cout << "Unidentified error with number: " << numStr << std::endl;
        std::cout << "Try again!" << std::endl;
        return -1;
    }
}