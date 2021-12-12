#pragma once

namespace casanova::hooks {
  void init();

  void init_rendering(game_sdk::CCEGLView* gl);
  inline bool rendering_ready = false;

  inline void __fastcall cceglview_swapbuffers(game_sdk::CCEGLView* ecx, void* edx);
  inline void __fastcall cceglview_pollevents(game_sdk::CCEGLView* ecx, void* edx);
  inline void __fastcall cceglview_togglefullscreen(game_sdk::CCEGLView* ecx, void* edx, bool toggle);
  inline int __stdcall channelcontrol_setvolume(game_sdk::Channel* channel, float volume);

  namespace trampolines {
    inline void(__thiscall* cceglview_swapbuffers)(void*);
    inline void(__thiscall* cceglview_pollevents)(void*);
    inline void(__thiscall* cceglview_togglefullscreen)(void*, bool);
    inline int(__stdcall* channelcontrol_setvolume)(game_sdk::Channel* channel, float volume);
  }
}