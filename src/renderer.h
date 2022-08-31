#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "tetromino.h"
#include "well.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  void render(Tetromino &tetromino, Well &well);
  void updateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window_;
  SDL_Renderer *sdl_renderer_;

  const std::size_t screen_width_;
  const std::size_t screen_height_;
};

#endif // End of RENDERER_H