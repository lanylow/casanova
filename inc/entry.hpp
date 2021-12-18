#pragma once

#include "utilities/game_sdk.hpp"

namespace casanova {
  inline bool update_presence, update_timestamp, ready;
  inline std::time_t current_timestamp;
  inline std::string large_text;
  inline game_sdk::GJGameLevel* game_level = nullptr;
  inline game_sdk::GDLevel level;
  inline game_sdk::GJPlayerState player_state = game_sdk::GJPlayerState::menu;

  void update(std::string& details, std::string& large_text, std::string& small_text, std::string& state, std::string& small_image);
  std::string text_from_key(std::string key);
  std::string format_level(std::string out);
  std::string get_diff_name();
  unsigned long __stdcall init();
}