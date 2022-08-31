#include <iostream>

#include "game.h"

int main() {
    constexpr std::size_t kScreenWidth{360};
    constexpr std::size_t kScreenHeight{720};
    Game game(kScreenWidth, kScreenHeight);

    while (game.tick());

    return 0;
}
