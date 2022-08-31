#ifndef GAME_H
#define GAME_H

#include <SDL.h>

#include "tetris.h"
#include "well.h"

class Game {
   public:
    Game(const std::size_t screen_width, const std::size_t screen_height);
    ~Game();
    bool tick();

   private:
    // Private methods
    Game(const Game &);
    Game &operator=(const Game &);
    void check(const Tetris &);
    
    // Private attributes
    SDL_Window *sdl_window_;
    SDL_Renderer *sdl_renderer_;
    Well well_;
    Tetris tetris_;
    uint32_t moveTime_;
    const std::size_t screen_width_;
    const std::size_t screen_height_;
};

#endif
