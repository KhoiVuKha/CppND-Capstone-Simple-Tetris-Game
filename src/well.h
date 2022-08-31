#ifndef WELL_H
#define WELL_H

#include <SDL2/SDL.h>

#include "tetromino.h"

class Well {
   public:
    Well();
    void draw(SDL_Renderer *);
    enum { Width = 10, Height = 20 };
    bool isCollision(const Tetromino &t) const;
    void unite(const Tetromino &);

    int score {0};

   private:
    bool data[Width][Height];
};

#endif // End of WELL_H
