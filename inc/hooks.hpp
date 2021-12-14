#pragma once

namespace casanova::hooks {
  void init();
  void init_rendering(game_sdk::CCEGLView* gl);
  void set_speed(float val);

  inline bool rendering_ready = false;
  inline uint32_t base_time = 0;
  inline uint64_t base_time_64 = 0;
  inline LARGE_INTEGER perf_count = { };
  inline float speed = 1.f;

  namespace trampolines {
    inline void(__thiscall* cceglview_swapbuffers)(void*);
    inline void(__thiscall* cceglview_pollevents)(void*);
    inline void(__thiscall* cceglview_togglefullscreen)(void*, bool);
    inline int(__stdcall* channelcontrol_setvolume)(game_sdk::Channel*, float);
    inline uint32_t(__stdcall* gettickcount)();
    inline uint64_t(__stdcall* gettickcount64)();
    inline int(__stdcall* queryperformancecounter)(LARGE_INTEGER*);
    inline int(__thiscall* menulayer_init)(void*);
    inline void*(__thiscall* playlayer_create)(void*);
    inline void(__thiscall* playlayer_onquit)(void*);
    inline void*(__thiscall* playlayer_shownewbest)(void*, char, float, int, char, char, char);
    inline void(__thiscall* editorpauselayer_onexiteditor)(void*, void*);
    inline void*(__thiscall* leveleditorlayer_create)(void*);
    inline void(__thiscall* leveleditorlayer_addspecial)(void*, void*);
    inline void(__thiscall* leveleditorlayer_removespecial)(void*, void*);
  }
}