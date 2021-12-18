#pragma once

namespace casanova::discord {
  void init();
  void update(const char* details, const char* large_text, const char* small_text, const char* state, const char* small_image, std::time_t timestamp);
  void shutdown();
  void clear();
}