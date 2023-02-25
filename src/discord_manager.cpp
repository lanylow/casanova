#include <common.hpp>

std::string casanova::discord_manager::get_diff_name() {
  if (level.is_auto)
    return "auto";

  if (level.is_demon) {
    switch (level.demon_difficulty) {
    case sdk::GJDemonDifficulty::easy: return "easy_demon";
    case sdk::GJDemonDifficulty::medium: return "medium_demon";
    case sdk::GJDemonDifficulty::insane: return "insane_demon";
    case sdk::GJDemonDifficulty::extreme: return "extreme_demon";
    default:
    case sdk::GJDemonDifficulty::hard: return "hard_demon";
    }
  }

  switch (level.difficulty) {
  case sdk::GJDifficulty::easy: return "easy";
  case sdk::GJDifficulty::normal: return "normal";
  case sdk::GJDifficulty::hard: return "hard";
  case sdk::GJDifficulty::harder: return "harder";
  case sdk::GJDifficulty::insane: return "insane";
  case sdk::GJDifficulty::demon: return "hard_demon";
  default:
  case sdk::GJDifficulty::na: return "na";
  }
}

std::string casanova::discord_manager::text_from_key(std::string key) {
  key.at(0) = std::toupper(key.at(0));
  int i = 1;

  std::for_each(key.begin() + 1, key.end(), [&i, &key](char& c) {
    if (key.at(i - 1) == ' ')
    c = std::toupper(c);
    else if (c == '_')
      c = ' ';
    i++;
  });

  return key;
}

std::string casanova::discord_manager::format_level(std::string out) {
  return fmt::format(out,
    fmt::arg("id", level.level_id),
    fmt::arg("name", level.name),
    fmt::arg("best", game_level->normal_percent),
    fmt::arg("diff", text_from_key(get_diff_name())),
    fmt::arg("author", level.author),
    fmt::arg("stars", level.stars),
    fmt::arg("objects", game_level->object_count),
    fmt::arg("attempts", game_level->attempts),
    fmt::arg("jumps", game_level->jumps),
    fmt::arg("clicks", game_level->clicks),
    fmt::arg("best_percent", game_level->normal_percent));
}

void casanova::discord_manager::update(std::string& details, std::string& large_text, std::string& small_text, std::string& state, std::string& small_image) {
  if (update_timestamp) {
    time(&current_timestamp);
    update_timestamp = false;
  }

  discord::update(details.c_str(), large_text.c_str(), small_text.c_str(), state.c_str(), small_image.c_str(), current_timestamp);
}

void casanova::discord_manager::run() {
  while (true) {
    if (update_presence && config::discord_presence) {
      std::string details, state, small_text, small_image;

      switch (player_state) {
      case sdk::GJPlayerState::level: {
        sdk::parse_game_level(game_level, level);
        sdk::GJLevelType type = game_level->level_type;

        if (type == sdk::GJLevelType::editor) {
          details = format_level("Playtesting a level");
          state = "";
          small_text = "";
          small_image = "creator_point";
        }
        else {
          details = format_level("Playing {name}");
          state = format_level("by {author} ({best}%)");
          small_text = format_level("{stars}* {diff} ({id})");
          small_image = get_diff_name();
        }

        break;
      }

      case sdk::GJPlayerState::editor: {
        sdk::parse_game_level(game_level, level);

        details = format_level("Editing a level");
        state = format_level("{objects} objects");
        small_text = "";
        small_image = "creator_point";

        break;
      }

      case sdk::GJPlayerState::menu: {
        details = "Idle";
        state = "";
        small_text = "";
        small_image = "";

        break;
      }
      }

      update(details, large_text, small_text, state, small_image);

      update_presence = false;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}