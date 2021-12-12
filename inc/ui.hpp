#pragma once

namespace casanova::ui {
  inline bool opened = false;
  inline ImFont* font = nullptr;
  inline ImColor menu_accent = { 173, 98, 238, 255 };

  void render();

  void add_title_bar(const char* name);
  bool add_button(const char* label, bool& enabled, const char* tooltip, ImVec2 pos, ImVec2 size);
  bool add_button(const char* label, bool& enabled, const char* tooltip = nullptr);
  bool add_input_button(const char* checkbox_label, const char* input_label, const char* fmt, bool& enabled, double& value, const char* tooltip = nullptr);
  void add_feature_button(casanova::base_features::feature_def_t& feature);
}