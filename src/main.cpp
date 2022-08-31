#include <iostream>

#include "controller.h"
#include "game.h"

int main() {
    constexpr std::size_t kScreenWidth{360};
    constexpr std::size_t kScreenHeight{720};
    constexpr int kFramesPerSecond{60};
	constexpr int kMsPerFrame{1000 / kFramesPerSecond};
    
    Controller controller;
    Game game(kScreenWidth, kScreenHeight);
    game.run(controller, kMsPerFrame);

    return 0;
}
