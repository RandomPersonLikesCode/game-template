// SPDX-License-Identifier: MIT

#include <SDL3/SDL.h>

namespace Platform {
  struct EventHandler {
    SDL_Event events;
    bool is_running = true;

    void handle_events();
  };
} // namespace Platform
