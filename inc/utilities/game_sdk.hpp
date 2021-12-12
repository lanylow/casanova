#pragma once

namespace casanova::game_sdk {
  class CCEGLView {
  public:
    void* get_window() {
      return utilities::thiscall_function<void*, void*>(_t("libcocos2d"), _t("CCEGLView::getWindow"), this);
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