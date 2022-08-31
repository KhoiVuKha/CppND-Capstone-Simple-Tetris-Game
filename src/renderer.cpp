#include "renderer.h"

#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)
    : screen_width_(screen_width), screen_height_(screen_height) {
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

Renderer::~Renderer() {
    SDL_DestroyRenderer(sdl_renderer_);
    SDL_DestroyWindow(sdl_window_);
    SDL_Quit();
}

void Renderer::render(Tetromino &tetromino, Well &well) {
    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer_, 0, 0, 0, 0xff);
    SDL_RenderClear(sdl_renderer_);

    // Render well
    well.draw(sdl_renderer_);

    // Render tetromino
    tetromino.draw(sdl_renderer_);

    // Update Screen
    SDL_RenderPresent(sdl_renderer_);
}

void Renderer::updateWindowTitle(int score, int fps) {
    std::string title{"Tetris Score: " + std::to_string(score) +
                      " FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window_, title.c_str());
}