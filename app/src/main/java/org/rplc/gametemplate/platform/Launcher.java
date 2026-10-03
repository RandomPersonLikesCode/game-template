// SPDX-License-Identifier: MIT

package org.rplc.gametemplate.platform;

import android.os.Bundle;
import com.badlogic.gdx.backends.android.AndroidApplication;
import com.badlogic.gdx.backends.android.AndroidApplicationConfiguration;
import org.rplc.gametemplate.core.Main;

public class Launcher extends AndroidApplication {
  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);

    AndroidApplicationConfiguration config = new AndroidApplicationConfiguration();
    config.useGL30 = true;

    initialize(new Main(), config);
  }
}
