#include <iostream>
#include "GameEngine/GreenVsRedEngine.h"

int main() {
    GreenVsRedEngine game = GreenVsRedEngine();
    int result = game.play();
    std::cout << "The result is: " << result << std::endl;

    return 0;
}