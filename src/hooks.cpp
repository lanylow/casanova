#include <common.hpp>

void __fastcall casanova::hooks::cceglview_swapbuffers(game_sdk::CCEGLView* ecx, void* edx) {
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

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void __fastcall casanova::hooks::cceglview_pollevents(game_sdk::CCEGLView* ecx, void* edx) {
  if (!rendering_ready)
    return casanova::hooks::trampolines::cceglview_pollevents(ecx);

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

  casanova::hooks::trampolines::cceglview_pollevents(ecx);
}

void __fastcall casanova::hooks::cceglview_togglefullscreen(game_sdk::CCEGLView* ecx, void* edx, bool toggle) {
  rendering_ready = false;

  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplWin32_Shutdown();
  ImGui::DestroyContext();

  casanova::hooks::trampolines::cceglview_togglefullscreen(ecx, toggle);

  init_rendering(ecx);
}

int __stdcall casanova::hooks::channelcontrol_setvolume(game_sdk::Channel* channel, float volume) {
  if (config::speedhack::enabled && config::speedhack::audio && config::speedhack::multiplier >= 0)
    channel->set_pitch((float)config::speedhack::multiplier);

  return trampolines::channelcontrol_setvolume(channel, volume);
}

void casanova::hooks::init() {
  MH_Initialize();

  MH_CreateHook((void*)(import_table::table[_t("libcocos2d")][_t("CCEGLView::swapBuffers")]), (void*)(&cceglview_swapbuffers), (void**)(&trampolines::cceglview_swapbuffers));
  MH_CreateHook((void*)(import_table::table[_t("libcocos2d")][_t("CCEGLView::pollEvents")]), (void*)(&cceglview_pollevents), (void**)(&trampolines::cceglview_pollevents));
  MH_CreateHook((void*)(import_table::table[_t("libcocos2d")][_t("CCEGLView::toggleFullScreen")]), (void*)(&cceglview_togglefullscreen), (void**)(&trampolines::cceglview_togglefullscreen));
  MH_CreateHook((void*)(import_table::table[_t("fmod")][_t("ChannelControl::setVolume")]), (void*)(&channelcontrol_setvolume), (void**)(&trampolines::channelcontrol_setvolume));

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

  rendering_ready = true;
}