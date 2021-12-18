#include <common.hpp>

std::string casanova::get_diff_name() {
  if (level.is_auto)
    return _t("auto");

  if (level.is_demon) {
    switch (level.demon_difficulty) {
      case game_sdk::GJDemonDifficulty::easy: return _t("easy_demon");
      case game_sdk::GJDemonDifficulty::medium: return _t("medium_demon");
      case game_sdk::GJDemonDifficulty::insane: return _t("insane_demon");
      case game_sdk::GJDemonDifficulty::extreme: return _t("extreme_demon");
      default:
      case game_sdk::GJDemonDifficulty::hard: return _t("hard_demon");
    }
  }

  switch (level.difficulty) {
    case game_sdk::GJDifficulty::easy: return _t("easy");
    case game_sdk::GJDifficulty::normal: return _t("normal");
    case game_sdk::GJDifficulty::hard: return _t("hard");
    case game_sdk::GJDifficulty::harder: return _t("harder");
    case game_sdk::GJDifficulty::insane: return _t("insane");
    case game_sdk::GJDifficulty::demon: return _t("hard_demon");
    default:
    case game_sdk::GJDifficulty::na:
      return "na";
  }
}

std::string casanova::text_from_key(std::string key) {
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

std::string casanova::format_level(std::string out) {
  std::string tmp = fmt::format(out,
    fmt::arg(_t("id"), level.level_id),
    fmt::arg(_t("name"), level.name),
    fmt::arg(_t("best"), game_level->normal_percent),
    fmt::arg(_t("diff"), text_from_key(get_diff_name())),
    fmt::arg(_t("author"), level.author),
    fmt::arg(_t("stars"), level.stars),
    fmt::arg(_t("objects"), game_level->object_count),
    fmt::arg(_t("attempts"), game_level->attempts),
    fmt::arg(_t("jumps"), game_level->jumps),
    fmt::arg(_t("clicks"), game_level->clicks),
    fmt::arg(_t("best_percent"), game_level->normal_percent));
  return tmp;
}

void casanova::update(std::string& details, std::string& large_text, std::string& small_text, std::string& state, std::string& small_image) {
  if (update_timestamp) {
    time(&current_timestamp);
    update_timestamp = false;
  }

  discord::update(details.c_str(), large_text.c_str(), small_text.c_str(), state.c_str(), small_image.c_str(), current_timestamp);
}

unsigned long __stdcall casanova::init() {
  console::attach(_t("casanova debug console"));
  console::print(_t("casanova is now initializing"));
  import_table::dump_table();

  hooks::init();

  while (!ready)
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

  while (true) {
    if (update_presence && config::discord_presence) {
      std::string details, state, small_text, small_image;

      switch (player_state) {
        case game_sdk::GJPlayerState::level: {
          game_sdk::parse_game_level(game_level, level);
          game_sdk::GJLevelType type = game_level->level_type;

          if (type == game_sdk::GJLevelType::editor) {
            details = format_level(_t("Playtesting a level"));
            state = _t("");
            small_text = _t("");
            small_image = _t("creator_point");
          }
          else {
            details = format_level(_t("Playing {name}"));
            state = format_level(_t("by {author} ({best}%)"));
            small_text = format_level(_t("{stars}* {diff} ({id})"));
            small_image = get_diff_name();
          }

          break;
        }

        case game_sdk::GJPlayerState::editor: {
          game_sdk::parse_game_level(game_level, level);

          details = format_level(_t("Editing a level"));
          state = format_level(_t("{objects} objects"));
          small_text = _t("");
          small_image = _t("creator_point");
          
          break;
        }

        case game_sdk::GJPlayerState::menu: {
          details = _t("Idle");
          state = _t("");
          small_text = _t("");
          small_image = _t("");

          break;
        }
      }

      update(details, large_text, small_text, state, small_image);

      update_presence = false;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}

bool __stdcall DllMain(void* instance, int reason, void* reserved) {
  switch (reason) {
    case DLL_PROCESS_ATTACH: {
      casanova::utilities::disable_thread_calls(instance);
      casanova::utilities::create_thread(casanova::init);
      break;
    }

    case DLL_PROCESS_DETACH: {
      casanova::discord::shutdown();
      break;
    }
  }

  return true;
}