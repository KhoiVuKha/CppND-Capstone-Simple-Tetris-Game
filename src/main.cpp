#include <iostream>

#include "game.h"

int main() {
    constexpr std::size_t kScreenWidth{360};
    constexpr std::size_t kScreenHeight{720};
    constexpr int kFramesPerSecond{60};
	constexpr int kMsPerFrame{1000 / kFramesPerSecond};
    
    Game game(kScreenWidth, kScreenHeight);
    while (game.updateTheGame(kMsPerFrame));

    return 0;
}
