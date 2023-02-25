#include <common.hpp>

bool casanova::console::attach(const char* title) {
#ifdef _CONSOLE
  if (!AllocConsole())
    return false;

  AttachConsole(ATTACH_PARENT_PROCESS);

  if (freopen_s(&stream, "conout$", "w", stdout) != 0)
    return false;

  if (!SetConsoleTitleA(title))
    return false;

  return true;
#endif
}

void casanova::console::detach() {
#ifdef _CONSOLE
  FreeConsole();
  if (const auto console_hwnd = GetConsoleWindow(); console_hwnd != nullptr)
    PostMessageA(console_hwnd, WM_CLOSE, 0U, 0L);
#endif
}

void casanova::console::print(std::string_view text) {
#ifdef _CONSOLE
  auto time = fmt::format("[{:%X}] ", fmt::localtime(std::time(nullptr)));
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  fmt::print(time);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
  fmt::print("{}\n", text);
#endif
}