#include "controller.h"

#include <iostream>

#include "SDL.h"
#include "tetromino.h"

void Controller::HandleInput(bool &running, Tetromino &tetromino, const Well &well) const {
    SDL_Event e;
    Tetromino t = tetromino;

    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_DOWN: {
                    t.move(0, 1);
                    if (!well.isCollision(t)) tetromino = t;
                    break;
                }
                case SDLK_RIGHT: {
                    t.move(1, 0);
                    if (!well.isCollision(t)) tetromino = t;
                    break;
                }
                case SDLK_LEFT: {
                    t.move(-1, 0);
                    if (!well.isCollision(t)) tetromino = t;
                    break;
                }
                case SDLK_SPACE: {
                    t.rotate();
                    if (!well.isCollision(t)) {
                        tetromino = t;
                    }
                    break;
                }
            }
        }
    }
}