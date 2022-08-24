#ifndef WELL_H
#define WELL_H

#include "tetris.h"
#include <SDL2/SDL.h>

class Well {
public:
  Well();
  void draw(SDL_Renderer *);
  enum { Width = 10, Height = 20 };
  bool isCollision(const Tetris &t) const;
  void unite(const Tetris &);
private:
  bool data[Width][Height];
};

#endif