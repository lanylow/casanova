#include <common.hpp>

#define CreateHook(address, name) \
  console::print(fmt::format(_t("Creating hook from {:#08x} to " #name " ({:#08x})"), address, (uintptr_t)(&name))); \
  MH_CreateHook((void*)(address), (void*)(&name), (void**)(&trampolines::##name))

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace casanova::hooks {
  void __fastcall cceglview_swapbuffers(game_sdk::CCEGLView* ecx, void* edx) {
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

  void __fastcall cceglview_pollevents(game_sdk::CCEGLView* ecx, void* edx) {
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

  void __fastcall cceglview_togglefullscreen(game_sdk::CCEGLView* ecx, void* edx, bool toggle) {
    rendering_ready = false;

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    trampolines::cceglview_togglefullscreen(ecx, toggle);

    init_rendering(ecx);
  }

  int __stdcall channelcontrol_setvolume(game_sdk::Channel* channel, float volume) {
    if (config::speedhack::enabled && config::speedhack::audio && config::speedhack::multiplier >= 0)
      channel->set_pitch((float)config::speedhack::multiplier);

    return trampolines::channelcontrol_setvolume(channel, volume);
  }

  uint32_t __stdcall gettickcount() {
    return (uint32_t)(base_time + ((trampolines::gettickcount() - base_time) * speed));
  }

  uint64_t __stdcall gettickcount64() {
    return (uint64_t)(base_time_64 + ((trampolines::gettickcount64() - base_time_64) * speed));
  }

  int __stdcall queryperformancecounter(LARGE_INTEGER* count) {
    LARGE_INTEGER temp;
    trampolines::queryperformancecounter(&temp);
    count->QuadPart = (int64_t)(perf_count.QuadPart + ((temp.QuadPart - perf_count.QuadPart) * speed));
    return 1;
  }

  void* __fastcall playlayer_create(game_sdk::GJGameLevel* ecx, void* edx) {
    if (player_state != game_sdk::GJPlayerState::editor)
      update_timestamp = true;

    game_level = ecx;
    player_state = game_sdk::GJPlayerState::level;
    update_presence = true;

    return trampolines::playlayer_create(ecx);
  }

  void __fastcall playlayer_onquit(void* ecx, void* edx) {
    player_state = game_sdk::GJPlayerState::menu;
    update_timestamp = true;
    update_presence = true;

    return trampolines::playlayer_onquit(ecx);
  }

  void* __fastcall playlayer_shownewbest(void* ecx, void* edx, char a2, float a3, int a4, char a5, char a6, char a7) {
    update_presence = true;

    return trampolines::playlayer_shownewbest(ecx, a2, a3, a4, a5, a6, a7);
  }

  void __fastcall editorpauselayer_onexiteditor(void* ecx, void* edx, void* a2) {
    player_state = game_sdk::GJPlayerState::menu;
    update_timestamp = true;
    update_presence = true;

    return trampolines::editorpauselayer_onexiteditor(ecx, a2);
  }

  void* __fastcall leveleditorlayer_create(game_sdk::GJGameLevel* ecx, void* edx) {
    if (player_state != game_sdk::GJPlayerState::level)
      update_timestamp = true;

    player_state = game_sdk::GJPlayerState::editor;
    update_presence = true;
    game_level = ecx;

    return trampolines::leveleditorlayer_create(ecx);
  }

  void fix_object_count(void* layer) {
    const uintptr_t offset = 0x3A0;

    game_level->object_count_rand = *(int*)((uintptr_t)layer + (offset - (4 * 2)));
    game_level->object_count_seed = *(int*)((uintptr_t)layer + (offset - 4));
    game_level->object_count = *(int*)((uintptr_t)layer + offset);
  }

  void __fastcall leveleditorlayer_addspecial(void* ecx, void* edx, void* object) {
    trampolines::leveleditorlayer_addspecial(ecx, object);

    int object_count = *(int*)((uintptr_t)ecx + 0x3A0);
    if (game_level->object_count >= object_count)
      return;

    fix_object_count(ecx);
    
    update_presence = true;
  }

  void __fastcall leveleditorlayer_removespecial(void* ecx, void* edx, void* object) {
    trampolines::leveleditorlayer_removespecial(ecx, object);

    int object_count = *(int*)((uintptr_t)ecx + 0x3A0);
    if (game_level->object_count < object_count)
      return;

    fix_object_count(ecx);

    update_presence = true;
  }

  int __fastcall menulayer_init(void* ecx, void* edx) {
    static auto once = []() {
      CreateHook(import_table::table[_t("libcocos2d")][_t("CCEGLView::swapBuffers")], cceglview_swapbuffers);
      CreateHook(import_table::table[_t("libcocos2d")][_t("CCEGLView::pollEvents")], cceglview_pollevents);
      CreateHook(import_table::table[_t("libcocos2d")][_t("CCEGLView::toggleFullScreen")], cceglview_togglefullscreen);
      CreateHook(import_table::table[_t("fmod")][_t("ChannelControl::setVolume")], channelcontrol_setvolume);
      CreateHook(import_table::table[_t("kernel32")][_t("GetTickCount")], gettickcount);
      CreateHook(import_table::table[_t("kernel32")][_t("GetTickCount64")], gettickcount64);
      CreateHook(import_table::table[_t("kernel32")][_t("QueryPerformanceCounter")], queryperformancecounter);
      CreateHook(utilities::get_module(_t("GeometryDash.exe")) + 0x1FB6D0, playlayer_create);
      CreateHook(utilities::get_module(_t("GeometryDash.exe")) + 0x20D810, playlayer_onquit);
      CreateHook(utilities::get_module(_t("GeometryDash.exe")) + 0x1FE3A0, playlayer_shownewbest);
      CreateHook(utilities::get_module(_t("GeometryDash.exe")) + 0x75660, editorpauselayer_onexiteditor);
      CreateHook(utilities::get_module(_t("GeometryDash.exe")) + 0x15ED60, leveleditorlayer_create);
      CreateHook(utilities::get_module(_t("GeometryDash.exe")) + 0x162650, leveleditorlayer_addspecial);
      CreateHook(utilities::get_module(_t("GeometryDash.exe")) + 0x162FF0, leveleditorlayer_removespecial);

      MH_EnableHook(MH_ALL_HOOKS);

      discord::init();

      char* username = (char*)utilities::resolve_multilevel(utilities::get_module(_t("GeometryDash.exe")), { 0x3222D8, 0x108 });
      large_text = std::string(username);
      update_presence = true;
      update_timestamp = true;
      current_timestamp = time(nullptr);
      ready = true;

      return true;
    } ();

    return trampolines::menulayer_init(ecx);
  }
}

void casanova::hooks::set_speed(float val) {
  base_time = trampolines::gettickcount();
  base_time_64 = trampolines::gettickcount64();
  trampolines::queryperformancecounter(&perf_count);
  speed = val;
}

void casanova::hooks::init() {
  base_time = utilities::stdcall_function<uint32_t>(_t("kernel32"), _t("GetTickCount"));
  base_time_64 = utilities::stdcall_function<uint64_t>(_t("kernel32"), _t("GetTickCount64"));
  utilities::stdcall_function<int, LARGE_INTEGER*>(_t("kernel32"), _t("QueryPerformanceCounter"), &perf_count);

  MH_Initialize();

  CreateHook(utilities::get_module(_t("GeometryDash.exe")) + 0x1907B0, menulayer_init);

  MH_EnableHook(MH_ALL_HOOKS);
}

void casanova::hooks::init_rendering(game_sdk::CCEGLView* gl) {
  ImGui::CreateContext();
  ImGui_ImplWin32_Init(WindowFromDC(*(HDC*)((uintptr_t)gl->get_window() + 0x244)));
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

  config::display::fullscreen = game_sdk::CCEGLView::shared_view()->get_is_fullscreen();
  config::display::vsync = game_sdk::CCApplication::shared_application()->get_vertical_sync_enabled();

  rendering_ready = true;
}