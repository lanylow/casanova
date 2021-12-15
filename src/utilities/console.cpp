#include <common.hpp>

bool casanova::console::attach(const char* title) {
#ifdef _CONSOLE
  if (!_f(AllocConsole)())
    return false;

  _f(AttachConsole)(ATTACH_PARENT_PROCESS);

  if (freopen_s(&stream, _t("conout$"), _t("w"), stdout) != 0)
    return false;

  if (!_f(SetConsoleTitleA)(title))
    return false;

  return true;
#endif
}

void casanova::console::detach() {
#ifdef _CONSOLE
  _f(FreeConsole)();
  if (const auto console_hwnd = _f(GetConsoleWindow)(); console_hwnd != nullptr)
    _f(PostMessageA)(console_hwnd, WM_CLOSE, 0U, 0L);
#endif
}

void casanova::console::print(std::string_view text) {
#ifdef _CONSOLE
  auto time = fmt::format(_t("[{:%X}] "), fmt::localtime(std::time(nullptr)));
  _f(SetConsoleTextAttribute)(_f(GetStdHandle)(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  fmt::print(time);
  _f(SetConsoleTextAttribute)(_f(GetStdHandle)(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
  fmt::print("{}\n", text);
#endif
}