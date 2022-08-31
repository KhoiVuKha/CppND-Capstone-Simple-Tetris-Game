#ifndef GAME_H
#define GAME_H

#include <SDL.h>

#include "tetris.h"
#include "well.h"

class Game {
   public:
    Game(const std::size_t screen_width, const std::size_t screen_height);
    ~Game();
    bool updateTheGame(std::size_t target_frame_duration);

   private:
    // Private methods
    Game(const Game &);
    Game &operator=(const Game &);
    void checkCollision(const Tetris &);
    void runWindowTitle(std::size_t target_frame_duration);
    void updateWindowTitle(int score, int fps);
    
    // Private attributes
    SDL_Window *sdl_window_;
    SDL_Renderer *sdl_renderer_;
    Well well_;
    Tetris tetris_;
    uint32_t moveTime_;
    const std::size_t screen_width_;
    const std::size_t screen_height_;
    int title_timestamp_;
    int frame_start_;
    int frame_end_;
    int frame_duration_;
    int frame_count_;
};

#endif
