#include <common.hpp>

bool casanova::sdk::parse_game_level(GJGameLevel* game_level, GDLevel& level) {
  int id = game_level->level_id;
  GJLevelType type = game_level->level_type;

  if (id == level.level_id && type != GJLevelType::editor)
    return true;

  level.level_id = id;
  level.stars = game_level->stars;
  level.name = game_level->level_name;
  level.is_demon = static_cast<bool>(game_level->demon);
  level.is_auto = game_level->auto_level;

  if (type == GJLevelType::local) {
    level.author = "RobTop";
    level.difficulty = static_cast<GJDifficulty>(game_level->difficulty);

    if (level.difficulty == GJDifficulty::demon)
      level.demon_difficulty = GJDemonDifficulty::easy;
  }
  else {
    level.author = game_level->user_name;
    level.difficulty = static_cast<GJDifficulty>(game_level->ratings_sum / 10);

    if (level.is_demon) {
      switch (game_level->demon_difficulty) {
      case 3: level.demon_difficulty = GJDemonDifficulty::easy; break;
      case 4: level.demon_difficulty = GJDemonDifficulty::medium; break;
      case 5: level.demon_difficulty = GJDemonDifficulty::insane; break;
      case 6: level.demon_difficulty = GJDemonDifficulty::extreme; break;
      case 0:
      case 1:
      case 2: level.demon_difficulty = GJDemonDifficulty::hard; break;
      }
    }
  }

  return true;
}