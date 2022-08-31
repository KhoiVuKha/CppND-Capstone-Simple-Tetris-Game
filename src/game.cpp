#include "game.h"

#include <iostream>
#include <stdexcept>

Game::Game() : tetromino_{static_cast<Tetromino::Type>(rand() % 7)}, moveTime_(SDL_GetTicks()) {
}

Game::~Game() {}

void Game::update() {
    if (SDL_GetTicks() > moveTime_) {
        moveTime_ += 1000;
        Tetromino t = tetromino_;
        t.move(0, 1);
        checkCollision(t);
    }
}

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

void Game::run(Controller const &controller, Renderer &renderer,
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
        renderer.render(tetromino_, well_);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render
        // cycle takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000) {
            renderer.updateWindowTitle(well_.score, frame_count);
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
