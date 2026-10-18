// SPDX-License-Identifier: MIT

#include "../core/display.hh"
#include "../core/game.hh"

#include <GLES3/gl32.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char **argv) {
  Core::Display dp = {};
  dp.props.title = "Game Template";
  dp.props.width = 800;
  dp.props.height = 600;

  if (!dp.create()) {
    dp.destroy();
    return 1;
  }

  if (!Core::Game::create(dp.props.width_px, dp.props.height_px)) {
    Core::Game::destroy();
    dp.destroy();
    return 1;
  }

  bool is_running = true;
  while (is_running) {
    SDL_Event events = {};

    while (SDL_PollEvent(&events)) {
      switch (events.type) {
        case SDL_EVENT_QUIT:
          is_running = false;

          break;
      }
    }

    if (!Core::Game::update()) {
      Core::Game::destroy();
      dp.destroy();
      return 1;
    }

    SDL_GL_SwapWindow(dp.window);
  }

  Core::Game::destroy();
  dp.destroy();
  return 0;
}
