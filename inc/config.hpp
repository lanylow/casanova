#pragma once

namespace config {
  namespace speedhack {
    inline bool enabled = false;
    inline double multiplier = 1.0;
    inline bool audio = false;
    inline bool classic_mode = false;
  }

  namespace display {
    inline bool fps_bypass = false;
    inline double fps_value = 60;
    inline bool vsync = false;
    inline bool fullscreen = false;
    inline bool fullscreen_update = false;
  }
}