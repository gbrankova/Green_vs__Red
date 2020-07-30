#include <iostream>
#include "GreenVsRedEngine.h"

int main() {
    GreenVsRedEngine game = GreenVsRedEngine();
    int result = game.play();
    std::cout << "The result is: " << result << std::endl;

    std::cout << "Hello wordl!" << std::endl;
    return 0;
}