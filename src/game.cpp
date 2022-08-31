#include "game.h"

#include <iostream>
#include <stdexcept>

#include "controller.h"

Game::Game(const std::size_t screen_width, const std::size_t screen_height)
    : tetromino_{static_cast<Tetromino::Type>(rand() % 7)},
      moveTime_(SDL_GetTicks()),
      screen_width_(screen_width),
      screen_height_(screen_height) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create Window
    sdl_window_ = SDL_CreateWindow(
        "Tetris Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        screen_width, screen_height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if (nullptr == sdl_window_) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    sdl_renderer_ =
        SDL_CreateRenderer(sdl_window_, -1, SDL_RENDERER_ACCELERATED);
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

bool Game::update() {
    SDL_SetRenderDrawColor(sdl_renderer_, 0, 0, 0, 0xff);
    SDL_RenderClear(sdl_renderer_);
    well_.draw(sdl_renderer_);
    tetromino_.draw(sdl_renderer_);
    if (SDL_GetTicks() > moveTime_) {
        moveTime_ += 1000;
        Tetromino t = tetromino_;
        t.move(0, 1);
        checkCollision(t);
    }
    SDL_RenderPresent(sdl_renderer_);
    return true;
};

void Game::checkCollision(const Tetromino &t) {
    if (well_.isCollision(t)) {
        well_.unite(tetromino_);
        tetromino_ = Tetromino{static_cast<Tetromino::Type>(rand() % 7)};
        if (well_.isCollision(tetromino_)) {
            well_ = Well();
        }
    } else {
        tetromino_ = t;
    }
}

void Game::run(Controller const &controller,
               std::size_t target_frame_duration) {
    uint32_t title_timestamp = SDL_GetTicks();
    uint32_t frame_start;
    uint32_t frame_end;
    uint32_t frame_duration;
    int frame_count = 0;
    bool running = true;

    while (running) {
        frame_start = SDL_GetTicks();

        // Input, Update, Render - the main game loop.
        controller.HandleInput(running, tetromino_, well_);
        update();
        // sdl_renderer_.Render(snake, food);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render
        // cycle takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000) {
            updateWindowTitle(well_.score, frame_count);
            frame_count = 0;
            title_timestamp = frame_end;
        }

        // If the time for this frame is too small (i.e. frame_duration is
        // smaller than the target ms_per_frame), delay the loop to
        // achieve the correct frame rate.
        if (frame_duration < target_frame_duration) {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}

void Game::updateWindowTitle(int score, int fps) {
    std::string title{"Tetris Score: " + std::to_string(score) +
                      " FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window_, title.c_str());
}
