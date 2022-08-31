#ifndef GAME_H
#define GAME_H

#include <SDL.h>

#include "controller.h"
#include "tetromino.h"
#include "well.h"

class Game {
   public:
    Game(const std::size_t screen_width, const std::size_t screen_height);
    ~Game();
    void run(Controller const &controller, std::size_t target_frame_duration);

   private:
    // Private methods
    Game(const Game &);
    Game &operator=(const Game &);
    bool update();
    void checkCollision(const Tetromino &);
    void updateWindowTitle(int score, int fps);

    // Private attributes
    SDL_Window *sdl_window_;
    SDL_Renderer *sdl_renderer_;
    Well well_;
    Tetromino tetromino_;
    uint32_t moveTime_;  // Move time in ms for every single movement
    const std::size_t screen_width_;
    const std::size_t screen_height_;
};

#endif  // End of GAME_H
