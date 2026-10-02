// SPDX-License-Identifier: MIT
package org.rplc.game_template.core;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.GL30;

public class Main extends ApplicationAdapter {
  @Override
  public void create() {
    Gdx.gl30.glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  }

  @Override
  public void render() {
    Gdx.gl30.glClear(GL30.GL_COLOR_BUFFER_BIT);
  }
}
