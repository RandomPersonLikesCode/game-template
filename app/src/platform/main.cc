// SPDX-License-Identifier: MIT

#include "../core/display.hh"
#include "sokol_gfx.h"

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

  sg_desc desc = {};
  desc.environment.defaults.depth_format = SG_PIXELFORMAT_DEPTH;

  sg_setup(&desc);

  sg_pass pass = {};
  pass.swapchain.width = dp.props.width_px;
  pass.swapchain.height = dp.props.height_px;
  pass.swapchain.depth_format = SG_PIXELFORMAT_DEPTH;

  pass.action.colors[0].load_action = SG_LOADACTION_CLEAR;
  pass.action.colors[0].clear_value = {0.0f, 0.0f, 1.0f, 0.0f};

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

    sg_begin_pass(&pass);
    sg_end_pass();

    sg_commit();
    SDL_GL_SwapWindow(dp.window);
  }

  sg_shutdown();
  dp.destroy();
  return 0;
}
