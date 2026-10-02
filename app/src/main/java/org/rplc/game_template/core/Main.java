// SPDX-License-Identifier: MIT
package org.rplc.game_template.core;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.GL32;
import com.badlogic.gdx.graphics.glutils.ShapeRenderer;

public class Main extends ApplicationAdapter {
  private ShapeRenderer shapes;

  @Override
  public void create() {
    Gdx.gl.glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    shapes = new ShapeRenderer();
  }

  @Override
  public void render() {
    Gdx.gl.glClear(GL32.GL_COLOR_BUFFER_BIT);

    shapes.begin(ShapeRenderer.ShapeType.Filled);
    shapes.setColor(Color.RED);

    shapes.circle(400, 400, 50, 16);

    shapes.end();
  }
}
