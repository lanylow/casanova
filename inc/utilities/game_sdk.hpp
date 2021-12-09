#pragma once

namespace casanova::game_sdk {
  class CCEGLView {
  public:
    void* get_window() {
      return utilities::thiscall_function<void*, void*>(_t("libcocos2d"), _t("CCEGLView::getWindow"), this);
    }
  };
}