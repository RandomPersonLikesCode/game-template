// SPDX-License-Identifier: MIT
package org.rplc.game_template.core;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL32;

public class Main extends ApplicationAdapter {
  @Override
  public void create() {
    Gdx.gl.glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  }

  @Override
  public void render() {
    Gdx.gl.glClear(GL32.GL_COLOR_BUFFER_BIT);
  }
}
