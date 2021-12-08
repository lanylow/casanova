#pragma once

namespace console {
  bool attach(const char* title);
  void detach();
  void print(std::string_view text);

  inline FILE* stream;
}