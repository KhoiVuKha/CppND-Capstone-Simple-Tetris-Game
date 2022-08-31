#include "game.h"

#include <iostream>
#include <stdexcept>

Game::Game(const std::size_t screen_width, const std::size_t screen_height)
    : tetris_{static_cast<Tetris::Type>(rand() % 7)},
      moveTime_(SDL_GetTicks()),
      screen_width_(screen_width),
      screen_height_(screen_height) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create Window
    sdl_window_ = SDL_CreateWindow("Tetris Game", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, screen_width,
                                  screen_height, SDL_WINDOW_SHOWN | 
                                  SDL_WINDOW_BORDERLESS | 
                                  SDL_WINDOW_OPENGL);

    if (nullptr == sdl_window_) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    sdl_renderer_ = SDL_CreateRenderer(sdl_window_, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == sdl_renderer_) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
}

Game::~Game() {
    SDL_DestroyRenderer(sdl_renderer_);
    SDL_DestroyWindow(sdl_window_);
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
                        if (!well_.isCollision(t)) tetris_ = t;
                        break;
                    }
                    case SDLK_RIGHT: {
                        Tetris t = tetris_;
                        t.move(1, 0);
                        if (!well_.isCollision(t)) tetris_ = t;
                        break;
                    }
                    case SDLK_LEFT: {
                        Tetris t = tetris_;
                        t.move(-1, 0);
                        if (!well_.isCollision(t)) tetris_ = t;
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
    SDL_SetRenderDrawColor(sdl_renderer_, 0, 0, 0, 0xff);
    SDL_RenderClear(sdl_renderer_);
    well_.draw(sdl_renderer_);
    tetris_.draw(sdl_renderer_);
    if (SDL_GetTicks() > moveTime_) {
        moveTime_ += 1000;
        Tetris t = tetris_;
        t.move(0, 1);
        check(t);
    }
    SDL_RenderPresent(sdl_renderer_);
    return true;
};

void Game::check(const Tetris &t) {
    if (well_.isCollision(t)) {
        well_.unite(tetris_);
        tetris_ = Tetris{static_cast<Tetris::Type>(rand() % 7)};
        if (well_.isCollision(tetris_)) {
            well_ = Well();
        }
    } else {
        tetris_ = t;
    }
}
