// SPDX-License-Identifier: MIT

#include "./game.hh"

#include <GLES3/gl32.h>

bool Core::Game::create(int width, int height) {
  glViewport(0, 0, width, height);
  glClearColor(0.52f, 0.8f, 0.92f, 1.0f);

  return true;
}

bool Core::Game::update() {
  glClear(GL_COLOR_BUFFER_BIT);

  return true;
}

void Core::Game::destroy() {};
