#pragma once

namespace casanova::discord_manager {
  void update(std::string& details, std::string& large_text, std::string& small_text, std::string& state, std::string& small_image);
  std::string text_from_key(std::string key);
  std::string format_level(std::string out);
  std::string get_diff_name();
  void run();

  inline bool update_presence, update_timestamp;
  inline std::time_t current_timestamp;
  inline std::string large_text;
  inline sdk::GJGameLevel* game_level = nullptr;
  inline sdk::GDLevel level;
  inline sdk::GJPlayerState player_state = sdk::GJPlayerState::menu;
}