#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "well.h"
#include "tetris.h"

class Game {
public:
  Game();
  ~Game();
  bool tick();
private:
  Game(const Game &);
  Game &operator=(const Game &);
  SDL_Window *window_;
  SDL_Renderer *renderer_;
  Well well_;
  Tetris tetris_;
  uint32_t moveTime_;
  void check(const Tetris &);
};

#endif
