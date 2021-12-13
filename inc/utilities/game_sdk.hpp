#pragma once

namespace casanova::game_sdk {
  class CCEGLView {
  public:
    static CCEGLView* shared_view() {
      return utilities::call_function<CCEGLView*>(_t("libcocos2d"), _t("CCEGLView::sharedOpenGLView"));
    }

    void* get_window() {
      return utilities::thiscall_function<void*, void*>(_t("libcocos2d"), _t("CCEGLView::getWindow"), this);
    }

    bool get_is_fullscreen() {
      return utilities::thiscall_function<bool, game_sdk::CCEGLView*>(_t("libcocos2d"), _t("CCEGLView::getIsFullscreen"), this);
    }

    void toggle_fullscreen(bool enable) {
      utilities::thiscall_function<void, game_sdk::CCEGLView*, bool>(_t("libcocos2d"), _t("CCEGLView::toggleFullScreen"), this, enable);
    }
  };

  class CCScheduler {
  public:
    void set_time_scale(float time_scale) {
      utilities::thiscall_function<void, void*, float>(_t("libcocos2d"), _t("CCScheduler::setTimeScale"), this, time_scale);
    }
  };

  class CCDirector {
  public:
    static CCDirector* shared_director() {
      return utilities::call_function<CCDirector*>(_t("libcocos2d"), _t("CCDirector::sharedDirector"));
    }

    CCScheduler* get_scheduler() {
      return utilities::thiscall_function<CCScheduler*, void*>(_t("libcocos2d"), _t("CCDirector::getScheduler"), this);
    }
  };

  class CCApplication {
  public:
    static CCApplication* shared_application() {
      return utilities::call_function<CCApplication*>(_t("libcocos2d"), _t("CCApplication::sharedApplication"));
    }

    void toggle_vertical_sync(bool enable) {
      return utilities::thiscall_function<void, CCApplication*, bool>(_t("libcocos2d"), _t("CCApplication::toggleVerticalSync"), this, enable);
    }

    bool get_vertical_sync_enabled() {
      return utilities::thiscall_function<bool, CCApplication*>(_t("libcocos2d"), _t("CCApplication::getVerticalSyncEnabled"), this);
    }

    void set_animation_interval(double interval) {
      return utilities::thiscall_function<void, CCApplication*, double>(_t("libcocos2d"), _t("CCApplication::setAnimationInterval"), this, interval);
    }
  };

  class Channel {
  public:
    static Channel* get_channel() {
      return (Channel*)(*(uintptr_t*)(*(uintptr_t*)(casanova::utilities::get_module(_t("GeometryDash.exe")) + 0x3222A8) + 0x134));
    }

    void set_pitch(float pitch) {
      utilities::stdcall_function<void, void*, float>(_t("fmod"), _t("ChannelControl::setPitch"), this, pitch);
    }
  };
}