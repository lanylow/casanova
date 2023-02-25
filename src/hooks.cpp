#include <common.hpp>

#define HOOK(address, name) \
  console::print(fmt::format("Creating hook from {:#08x} to " #name " ({:#08x})", address, reinterpret_cast<uintptr_t>(&name))); \
  MH_CreateHook(reinterpret_cast<void*>(address), reinterpret_cast<void*>(&name), reinterpret_cast<void**>(&trampolines::##name))

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void __fastcall casanova::hooks::cceglview_swapbuffers(sdk::CCEGLView* ecx, void* edx) {
  if (!rendering_ready)
    init_rendering(ecx);

  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplWin32_NewFrame();
  ImGui::NewFrame();

  ui::render();

  ImGui::EndFrame();
  ImGui::Render();

  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  trampolines::cceglview_swapbuffers(ecx);
}

void __fastcall casanova::hooks::cceglview_pollevents(sdk::CCEGLView* ecx, void* edx) {
  if (!rendering_ready)
    return trampolines::cceglview_pollevents(ecx);

  if (config::display::fullscreen_update) {
    hacks::display::update_fullscreen();
    config::display::fullscreen_update = false;
  }

  MSG message;
  ImGuiIO& io = ImGui::GetIO();
  bool block = false;

  while (PeekMessageA(&message, nullptr, 0, 0, PM_REMOVE)) {
    TranslateMessage(&message);

    if (io.WantCaptureMouse) {
      switch (message.message) {
      case WM_LBUTTONDBLCLK:
      case WM_LBUTTONDOWN:
      case WM_LBUTTONUP:
      case WM_MBUTTONDBLCLK:
      case WM_MBUTTONDOWN:
      case WM_MBUTTONUP:
      case WM_MOUSEACTIVATE:
      case WM_MOUSEHOVER:
      case WM_MOUSEHWHEEL:
      case WM_MOUSELEAVE:
      case WM_MOUSEMOVE:
      case WM_MOUSEWHEEL:
      case WM_NCLBUTTONDBLCLK:
      case WM_NCLBUTTONDOWN:
      case WM_NCLBUTTONUP:
      case WM_NCMBUTTONDBLCLK:
      case WM_NCMBUTTONDOWN:
      case WM_NCMBUTTONUP:
      case WM_NCMOUSEHOVER:
      case WM_NCMOUSELEAVE:
      case WM_NCMOUSEMOVE:
      case WM_NCRBUTTONDBLCLK:
      case WM_NCRBUTTONDOWN:
      case WM_NCRBUTTONUP:
      case WM_NCXBUTTONDBLCLK:
      case WM_NCXBUTTONDOWN:
      case WM_NCXBUTTONUP:
      case WM_RBUTTONDBLCLK:
      case WM_RBUTTONDOWN:
      case WM_RBUTTONUP:
      case WM_XBUTTONDBLCLK:
      case WM_XBUTTONDOWN:
      case WM_XBUTTONUP:
        block = true;
      }
    }

    if (io.WantCaptureKeyboard) {
      switch (message.message) {
      case WM_HOTKEY:
      case WM_KEYDOWN:
      case WM_KEYUP:
      case WM_KILLFOCUS:
      case WM_SETFOCUS:
      case WM_SYSKEYDOWN:
      case WM_SYSKEYUP:
        block = true;
      }
    }
    else if (message.message == WM_KEYDOWN && message.wParam == VK_TAB) {
      ui::opened = !ui::opened;
    }


    if (!block)
      DispatchMessageA(&message);

    ImGui_ImplWin32_WndProcHandler(message.hwnd, message.message, message.wParam, message.lParam);
  }

  trampolines::cceglview_pollevents(ecx);
}

void __fastcall casanova::hooks::cceglview_togglefullscreen(sdk::CCEGLView* ecx, void* edx, bool toggle) {
  rendering_ready = false;

  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplWin32_Shutdown();
  ImGui::DestroyContext();

  trampolines::cceglview_togglefullscreen(ecx, toggle);

  init_rendering(ecx);
}

int __stdcall casanova::hooks::channelcontrol_setvolume(sdk::Channel* channel, float volume) {
  if (config::speedhack::enabled && config::speedhack::audio && config::speedhack::multiplier >= 0)
    channel->set_pitch(static_cast<float>(config::speedhack::multiplier));

  return trampolines::channelcontrol_setvolume(channel, volume);
}

uint32_t __stdcall casanova::hooks::gettickcount() {
  return static_cast<uint32_t>(base_time + ((trampolines::gettickcount() - base_time) * speed));
}

uint64_t __stdcall casanova::hooks::gettickcount64() {
  return static_cast<uint64_t>(base_time_64 + ((trampolines::gettickcount64() - base_time_64) * speed));
}

int __stdcall casanova::hooks::queryperformancecounter(LARGE_INTEGER* count) {
  LARGE_INTEGER temp;
  trampolines::queryperformancecounter(&temp);
  count->QuadPart = static_cast<int64_t>(perf_count.QuadPart + ((temp.QuadPart - perf_count.QuadPart) * speed));
  return 1;
}

void* __fastcall casanova::hooks::playlayer_create(sdk::GJGameLevel* ecx, void* edx) {
  if (discord_manager::player_state != sdk::GJPlayerState::editor)
    discord_manager::update_timestamp = true;

  discord_manager::game_level = ecx;
  discord_manager::player_state = sdk::GJPlayerState::level;
  discord_manager::update_presence = true;

  return trampolines::playlayer_create(ecx);
}

void __fastcall casanova::hooks::playlayer_onquit(void* ecx, void* edx) {
  discord_manager::player_state = sdk::GJPlayerState::menu;
  discord_manager::update_timestamp = true;
  discord_manager::update_presence = true;

  return trampolines::playlayer_onquit(ecx);
}

void* __fastcall casanova::hooks::playlayer_shownewbest(void* ecx, void* edx, char a2, float a3, int a4, char a5, char a6, char a7) {
  discord_manager::update_presence = true;

  return trampolines::playlayer_shownewbest(ecx, a2, a3, a4, a5, a6, a7);
}

void __fastcall casanova::hooks::editorpauselayer_onexiteditor(void* ecx, void* edx, void* a2) {
  discord_manager::player_state = sdk::GJPlayerState::menu;
  discord_manager::update_timestamp = true;
  discord_manager::update_presence = true;

  return trampolines::editorpauselayer_onexiteditor(ecx, a2);
}

void* __fastcall casanova::hooks::leveleditorlayer_create(sdk::GJGameLevel* ecx, void* edx) {
  if (discord_manager::player_state != sdk::GJPlayerState::level)
    discord_manager::update_timestamp = true;

  discord_manager::player_state = sdk::GJPlayerState::editor;
  discord_manager::update_presence = true;
  discord_manager::game_level = ecx;

  return trampolines::leveleditorlayer_create(ecx);
}

void __fastcall casanova::hooks::leveleditorlayer_addspecial(void* ecx, void* edx, void* object) {
  trampolines::leveleditorlayer_addspecial(ecx, object);

  int object_count = *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(ecx) + 0x3A0);
  if (discord_manager::game_level->object_count >= object_count)
    return;

  fix_object_count(ecx);
    
  discord_manager::update_presence = true;
}

void __fastcall casanova::hooks::leveleditorlayer_removespecial(void* ecx, void* edx, void* object) {
  trampolines::leveleditorlayer_removespecial(ecx, object);

  int object_count = *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(ecx) + 0x3A0);
  if (discord_manager::game_level->object_count < object_count)
    return;

  fix_object_count(ecx);

  discord_manager::update_presence = true;
}

int __fastcall casanova::hooks::menulayer_init(void* ecx, void* edx) {
  static auto once = []() {
    HOOK(import_table::table["libcocos2d"]["CCEGLView::swapBuffers"], cceglview_swapbuffers);
    HOOK(import_table::table["libcocos2d"]["CCEGLView::pollEvents"], cceglview_pollevents);
    HOOK(import_table::table["libcocos2d"]["CCEGLView::toggleFullScreen"], cceglview_togglefullscreen);
    HOOK(import_table::table["fmod"]["ChannelControl::setVolume"], channelcontrol_setvolume);
    HOOK(import_table::table["kernel32"]["GetTickCount"], gettickcount);
    HOOK(import_table::table["kernel32"]["GetTickCount64"], gettickcount64);
    HOOK(import_table::table["kernel32"]["QueryPerformanceCounter"], queryperformancecounter);
    HOOK(utilities::get_module("GeometryDash.exe") + 0x1FB6D0, playlayer_create);
    HOOK(utilities::get_module("GeometryDash.exe") + 0x20D810, playlayer_onquit);
    HOOK(utilities::get_module("GeometryDash.exe") + 0x1FE3A0, playlayer_shownewbest);
    HOOK(utilities::get_module("GeometryDash.exe") + 0x75660, editorpauselayer_onexiteditor);
    HOOK(utilities::get_module("GeometryDash.exe") + 0x15ED60, leveleditorlayer_create);
    HOOK(utilities::get_module("GeometryDash.exe") + 0x162650, leveleditorlayer_addspecial);
    HOOK(utilities::get_module("GeometryDash.exe") + 0x162FF0, leveleditorlayer_removespecial);

    MH_EnableHook(MH_ALL_HOOKS);

    discord::init();

    discord_manager::large_text = reinterpret_cast<char*>(utilities::resolve_multilevel(utilities::get_module("GeometryDash.exe"), { 0x3222D8, 0x108 }));
    discord_manager::update_presence = true;
    discord_manager::update_timestamp = true;
    discord_manager::current_timestamp = time(nullptr);
    casanova::ready = true;

    return true;
  } ();

  return trampolines::menulayer_init(ecx);
}

void casanova::hooks::set_speed(float val) {
  base_time = trampolines::gettickcount();
  base_time_64 = trampolines::gettickcount64();
  trampolines::queryperformancecounter(&perf_count);
  speed = val;
}

void casanova::hooks::init() {
  base_time = utilities::stdcall_function<uint32_t>("kernel32", "GetTickCount");
  base_time_64 = utilities::stdcall_function<uint64_t>("kernel32", "GetTickCount64");
  utilities::stdcall_function<int, LARGE_INTEGER*>("kernel32", "QueryPerformanceCounter", &perf_count);

  MH_Initialize();

  HOOK(utilities::get_module("GeometryDash.exe") + 0x1907B0, menulayer_init);

  MH_EnableHook(MH_ALL_HOOKS);
}

void casanova::hooks::init_rendering(sdk::CCEGLView* gl) {
  ImGui::CreateContext();
  ImGui_ImplWin32_Init(WindowFromDC(*reinterpret_cast<HDC*>(reinterpret_cast<uintptr_t>(gl->get_window()) + 0x244)));
  ImGui_ImplOpenGL3_Init();

  ImGuiIO& io = ImGui::GetIO();
  ui::font = io.Fonts->AddFontFromMemoryTTF(font::data, sizeof(font::data), 22.f);

  ImGuiStyle* style = &ImGui::GetStyle();

  style->WindowRounding = 0.f;
  style->FrameRounding = 0.f;
  style->WindowPadding = { 0.f, 0.f };
  style->FramePadding = { 0.f, 0.f };
  style->WindowBorderSize = 0.f;
  style->Alpha = 1.f;
  style->ButtonTextAlign = { 0.050f, 0.5f };
  style->ItemSpacing = { 0.f, 0.f };

  style->Colors[ImGuiCol_WindowBg] = ImColor(41, 42, 42, 255);
  style->Colors[ImGuiCol_FrameBg] = ImColor(41, 42, 42, 255);

  style->Colors[ImGuiCol_Button] = ImColor(41, 42, 42, 255);
  style->Colors[ImGuiCol_ButtonHovered] = ImColor(23, 23, 24, 255);
  style->Colors[ImGuiCol_ButtonActive] = ImColor(10, 10, 10, 255);

  config::display::fullscreen = sdk::CCEGLView::shared_view()->get_is_fullscreen();
  config::display::vsync = sdk::CCApplication::shared_application()->get_vertical_sync_enabled();

  rendering_ready = true;
}

void casanova::hooks::fix_object_count(void* layer) {
  discord_manager::game_level->object_count_rand = *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(layer) + (0x3A0 - (4 * 2)));
  discord_manager::game_level->object_count_seed = *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(layer) + (0x3A0 - 4));
  discord_manager::game_level->object_count = *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(layer) + 0x3A0);
}