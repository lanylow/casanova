#include <common.hpp>

void casanova::hacks::display::update_fullscreen() {
  sdk::CCEGLView::shared_view()->toggle_fullscreen(config::display::fullscreen);
}

void casanova::hacks::display::update_vsync() {
  if (config::display::vsync) {
    config::display::fps_bypass = false;
    update_fps_bypass();
  }

  sdk::CCApplication::shared_application()->toggle_vertical_sync(config::display::vsync);
}

void casanova::hacks::display::update_fps_bypass() {
  sdk::CCApplication* application = sdk::CCApplication::shared_application();

  if (config::display::fps_bypass) {
    config::display::vsync = false;
    update_vsync();

    double multiplier = 1.0 / config::display::fps_value;
    *reinterpret_cast<double*>(*reinterpret_cast<uintptr_t*>(utilities::get_module("libcocos2d.dll") + 0x19EEA8) + 0x80) = multiplier;
    application->set_animation_interval(multiplier);
  }
  else {
    *reinterpret_cast<double*>(*reinterpret_cast<uintptr_t*>(utilities::get_module("libcocos2d.dll") + 0x19EEA8) + 0x80) = (double)0x3F91111111111111;
    application->set_animation_interval(0.01666666666666667);
  }
}