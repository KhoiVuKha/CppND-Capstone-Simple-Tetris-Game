#ifndef GAME_H
#define GAME_H

#include <SDL.h>

#include "controller.h"
#include "renderer.h"
#include "tetromino.h"
#include "well.h"

class Game {
   public:
    Game();
    ~Game();
    void run(Controller const &controller, Renderer &renderer,
             std::size_t target_frame_duration);
    
    int getScore() const;

   private:
    // Private methods
    Game(const Game &);
    Game &operator=(const Game &);
    void update();
    void checkCollision(const Tetromino &);
    void updateWindowTitle(int score, int fps);

    // Private attributes
    Well well_;
    Tetromino tetromino_;
    uint32_t moveTime_;  // Move time in ms for every single movement
};

#endif  // End of GAME_H
