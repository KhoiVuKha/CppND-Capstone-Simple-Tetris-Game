#include <iostream>

#include "controller.h"
#include "renderer.h"
#include "game.h"

int main() {
    constexpr std::size_t kScreenWidth{360};
    constexpr std::size_t kScreenHeight{720};
    constexpr int kFramesPerSecond{60};
    constexpr int kMsPerFrame{1000 / kFramesPerSecond};

    Renderer renderer(kScreenWidth, kScreenHeight);
    Controller controller;
    Game game;
    game.run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    //std::cout << "Score: " << game.GetScore() << "\n";

    return 0;
}
