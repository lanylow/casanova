#include <common.hpp>

void casanova::hacks::display::update_fullscreen() {
  utilities::thiscall_function<void, game_sdk::CCEGLView*, bool>(_t("libcocos2d"), _t("CCEGLView::toggleFullScreen"), game_sdk::CCEGLView::shared_view(), config::display::fullscreen);
}

void casanova::hacks::display::update_vsync() {
  if (config::display::vsync) {
    config::display::fps_bypass = false;
    update_fps_bypass();
  }

  game_sdk::CCApplication::shared_application()->toggle_vertical_sync(config::display::vsync);
}

void casanova::hacks::display::update_fps_bypass() {
  game_sdk::CCApplication* application = game_sdk::CCApplication::shared_application();

  if (config::display::fps_bypass) {
    config::display::vsync = false;
    update_vsync();

    double multiplier = 1.0 / config::display::fps_value;
    *(double*)(*(uintptr_t*)(utilities::get_module(_t("libcocos2d.dll")) + 0x19EEA8) + 0x80) = multiplier;
    application->set_animation_interval(multiplier);
  }
  else {
    *(double*)(*(uintptr_t*)(utilities::get_module(_t("libcocos2d.dll")) + 0x19EEA8) + 0x80) = (double)0x3F91111111111111;
    application->set_animation_interval(0.01666666666666667);
  }
}