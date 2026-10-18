// SPDX-License-Identifier: MIT

#include "./event_handler.hh"

#include <SDL3/SDL.h>

void Platform::EventHandler::handle_events() {
  switch (events.type) {
    case SDL_EVENT_QUIT:
      is_running = false;
  }
}
