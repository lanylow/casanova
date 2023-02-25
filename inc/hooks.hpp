#pragma once

namespace casanova::hooks {
  void init();
  void init_rendering(sdk::CCEGLView* gl);
  void set_speed(float val);
  void fix_object_count(void* layer);

  void __fastcall cceglview_swapbuffers(sdk::CCEGLView* ecx, void* edx);
  void __fastcall cceglview_pollevents(sdk::CCEGLView* ecx, void* edx);
  void __fastcall cceglview_togglefullscreen(sdk::CCEGLView* ecx, void* edx, bool toggle);
  int __stdcall channelcontrol_setvolume(sdk::Channel* channel, float volume);
  uint32_t __stdcall gettickcount();
  uint64_t __stdcall gettickcount64();
  int __stdcall queryperformancecounter(LARGE_INTEGER* count);
  void* __fastcall playlayer_create(sdk::GJGameLevel* ecx, void* edx);
  void __fastcall playlayer_onquit(void* ecx, void* edx);
  void* __fastcall playlayer_shownewbest(void* ecx, void* edx, char a2, float a3, int a4, char a5, char a6, char a7);
  void __fastcall editorpauselayer_onexiteditor(void* ecx, void* edx, void* a2);
  void* __fastcall leveleditorlayer_create(sdk::GJGameLevel* ecx, void* edx);
  void __fastcall leveleditorlayer_addspecial(void* ecx, void* edx, void* object);
  void __fastcall leveleditorlayer_removespecial(void* ecx, void* edx, void* object);
  int __fastcall menulayer_init(void* ecx, void* edx);

  namespace trampolines {
    inline void(__thiscall* cceglview_swapbuffers)(void*);
    inline void(__thiscall* cceglview_pollevents)(void*);
    inline void(__thiscall* cceglview_togglefullscreen)(void*, bool);
    inline int(__stdcall* channelcontrol_setvolume)(sdk::Channel*, float);
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

  inline bool rendering_ready = false;
  inline uint32_t base_time = 0;
  inline uint64_t base_time_64 = 0;
  inline LARGE_INTEGER perf_count = { };
  inline float speed = 1.f;
}