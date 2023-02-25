#pragma once

namespace casanova::sdk {
  enum class GJLevelType {
    local = 1,
    editor,
    saved
  };

  enum class GJPlayerState {
    level,
    editor,
    menu
  };

  enum class GJDifficulty {
    na,
    easy,
    normal,
    hard,
    harder,
    insane,
    demon
  };

  enum class GJDemonDifficulty {
    none,
    easy,
    medium,
    hard,
    insane,
    extreme
  };

  class CCEGLView {
  public:
    static CCEGLView* shared_view() { return utilities::call_function<CCEGLView*>("libcocos2d", "CCEGLView::sharedOpenGLView"); }
    void* get_window() { return utilities::thiscall_function<void*, void*>("libcocos2d", "CCEGLView::getWindow", this); }
    bool get_is_fullscreen() { return utilities::thiscall_function<bool, sdk::CCEGLView*>("libcocos2d", "CCEGLView::getIsFullscreen", this); }
    void toggle_fullscreen(bool enable) { utilities::thiscall_function<void, sdk::CCEGLView*, bool>("libcocos2d", "CCEGLView::toggleFullScreen", this, enable); }
  };

  class CCScheduler {
  public:
    void set_time_scale(float time_scale) { utilities::thiscall_function<void, void*, float>("libcocos2d", "CCScheduler::setTimeScale", this, time_scale); }
  };

  class CCDirector {
  public:
    static CCDirector* shared_director() { return utilities::call_function<CCDirector*>("libcocos2d", "CCDirector::sharedDirector"); }
    CCScheduler* get_scheduler() { return utilities::thiscall_function<CCScheduler*, void*>("libcocos2d", "CCDirector::getScheduler", this); }
  };

  class CCApplication {
  public:
    static CCApplication* shared_application() { return utilities::call_function<CCApplication*>("libcocos2d", "CCApplication::sharedApplication"); }
    void toggle_vertical_sync(bool enable) { return utilities::thiscall_function<void, CCApplication*, bool>("libcocos2d", "CCApplication::toggleVerticalSync", this, enable); }
    bool get_vertical_sync_enabled() { return utilities::thiscall_function<bool, CCApplication*>("libcocos2d", "CCApplication::getVerticalSyncEnabled", this); }
    void set_animation_interval(double interval) { return utilities::thiscall_function<void, CCApplication*, double>("libcocos2d", "CCApplication::setAnimationInterval", this, interval); }
  };

  class Channel {
  public:
    static Channel* get_channel() { return reinterpret_cast<Channel*>(*reinterpret_cast<uintptr_t*>(*reinterpret_cast<uintptr_t*>(casanova::utilities::get_module("GeometryDash.exe") + 0x3222A8) + 0x134)); }
    void set_pitch(float pitch) { utilities::stdcall_function<void, void*, float>("fmod", "ChannelControl::setPitch", this, pitch); }
  };

  class CCPoint {
  public:
    float x, y;
  };

  class GJGameLevel {
  public:
    pad(0xEC);
    void* last_build_save;
    int level_id_rand;
    int level_id_seed;
    int level_id;
    std::string level_name;
    std::string level_desc;
    std::string level_string;
    std::string user_name;
    std::string record_string;
    std::string upload_date;
    std::string update_date;
    int user_id_rand;
    int user_id_seed;
    int used_id;
    int account_id_rand;
    int account_id_seed;
    int account_id;
    int difficulty;
    int audio_track;
    int song_id;
    int level_rev;
    bool unlisted;
    int object_count_rand;
    int object_count_seed;
    int object_count;
    int average_difficulty;
    int ratings;
    int ratings_sum;
    int downloads;
    bool is_editable;
    bool gauntlet_level;
    pad(0x01);
    int working_time;
    int working_time_2;
    bool low_detail_mode;
    bool low_detail_mode_toggled;
    int is_verified_rand;
    int is_verified_seed;
    bool is_verified;
    bool is_uploaded;
    bool has_been_modified;
    int level_version;
    int game_version;
    int attempts_rand;
    int attempts_seed;
    int attempts;
    int jumps_rand;
    int jumps_seed;
    int jumps;
    int clicks_rand;
    int clicks_seed;
    int clicks;
    int attempt_time_rand;
    int attempt_time_seed;
    int attempt_time;
    int chk;
    pad(0x02);
    int normal_percent;
    int normal_percent_seed;
    int normal_percent_rand;
    int orb_completion_rand;
    int orb_completion_seed;
    int orb_completion;
    int new_normal_percent_rand;
    int new_normal_percent_seed;
    int new_normal_percent;
    int practice_percent;
    int likes;
    int dislikes;
    int level_length;
    int features;
    bool is_epic;
    bool level_favorited;
    int level_folder;
    int daily_id_rand;
    int daily_id_seed;
    int daily_id;
    int demon_rand;
    int demon_seed;
    int demon;
    int demon_difficulty;
    int stars_rand;
    int stars_seed;
    int stars;
    bool auto_level;
    int coins;
    int coins_verified_rand;
    int coins_verified_seed;
    int coins_verified;
    int password_rand;
    int password_seed;
    int original_level_rand;
    int original_level_seed;
    int original_level;
    bool two_player_mode;
    int failed_password_attempts;
    int first_coin_verified_rand;
    int first_coin_verified_seed;
    int first_coin_verified;
    int second_coin_verified_rand;
    int second_coin_verified_seed;
    int second_coin_verified;
    int third_coin_verified_rand;
    int third_coin_verified_seed;
    int third_coin_verified;
    int stars_requested;
    pad(0x38);
    bool dont_save;
    bool level_downloaded;
    int required_coins;
    bool is_unlocked;
    CCPoint last_camera_pos;
    float last_editor_zoom;
    int last_build_tab;
    int last_build_page;
    int last_build_group_id;
    GJLevelType level_type;
    int m_id;
    std::string temp_name;
    std::string capacity_string;
    bool high_objects_enabled;
    std::string personal_best;
  };

  class GDUser {
  public:
    int id = -1;
    int acc_id = -1;
    std::string name;
    int rank = -1;
  };

  class GDLevel {
  public:
    int level_id = -1;
    std::string name;
    std::string author = "-";
    int author_id = -1;
    int stars = 0;
    GJDifficulty difficulty = GJDifficulty::na;
    GJDemonDifficulty demon_difficulty = GJDemonDifficulty::none;
    bool is_auto = false;
    bool is_demon = false;
  };

  bool parse_game_level(GJGameLevel* game_level, GDLevel& level);
}