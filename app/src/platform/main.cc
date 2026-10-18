// SPDX-License-Identifier: MIT

#include "../core/game.hh"
#include "./display.hh"
#include "./event_handler.hh"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  Platform::Display dp = {};
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

  Platform::EventHandler event_handler = {};

  while (event_handler.is_running) {
    while (SDL_PollEvent(&event_handler.events)) {
      event_handler.handle_events();
    }

    if (!Core::Game::update()) {
      event_handler.is_running = false;
      return 1;
    }

    SDL_GL_SwapWindow(dp.window);
  }

  Core::Game::destroy();
  dp.destroy();
  return 0;
}
