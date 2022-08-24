#include "game.h"
#include <stdexcept>
#include <iostream>

Game::Game(): tetris_{static_cast<Tetris::Type>(rand() % 7)}, moveTime_(SDL_GetTicks()) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    throw std::runtime_error("SDL_Init(SDL_INIT_VIDEO)");
  }

  SDL_CreateWindowAndRenderer(720 / 2, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS, &window_, &renderer_);
  SDL_SetWindowPosition(window_, 65, 126);
}

Game::~Game() {
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

bool Game::tick() {
  SDL_Event e;
  if (SDL_WaitEventTimeout(&e, 250)) {
    switch (e.type) {
      case SDL_KEYDOWN: {
          switch (e.key.keysym.sym) {
            case SDLK_DOWN: {
                Tetris t = tetris_;
                t.move(0, 1);
                if (!well_.isCollision(t))
                  tetris_ = t;
                break;
            }
            case SDLK_RIGHT: {
                Tetris t = tetris_;
                t.move(1, 0);
                if (!well_.isCollision(t))
                  tetris_ = t;
                break;
              }
            case SDLK_LEFT: {
                Tetris t = tetris_;
                t.move(-1, 0);
                if (!well_.isCollision(t))
                  tetris_ = t;
                break;
              }
            case SDLK_SPACE: {
                Tetris t = tetris_;
                t.rotate();
                if (!well_.isCollision(t)) {
                  tetris_ = t;
                }
                break;
              }  
          }
          break;
      }
      case SDL_QUIT: {
        return false;
      }
    }
  }
  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0xff);
  SDL_RenderClear(renderer_);
  well_.draw(renderer_);
  tetris_.draw(renderer_);
  if (SDL_GetTicks() > moveTime_) {
    moveTime_ += 1000;
    Tetris t = tetris_;
    t.move(0, 1);
    check(t);
  }
  SDL_RenderPresent(renderer_);
  return true;
};

void Game::check(const Tetris &t) {
  if (well_.isCollision(t)) {
    well_.unite(tetris_);
    tetris_ = Tetris {static_cast<Tetris::Type>(rand() % 7)};
    if (well_.isCollision(tetris_)) {
      well_ = Well();
    }
  } else {
    tetris_ = t;
  }
}
