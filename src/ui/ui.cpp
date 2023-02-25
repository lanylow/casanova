#include <common.hpp>

void casanova::ui::render() {
  if (!opened)
    return;

  int i = 0;

  ImGui::PushFont(font);

  for (auto& category : base_features::table) {
    ImGui::SetNextWindowSize({ 200.f, 25.f + (category.second.size() * 25.f) });
    ImGui::SetNextWindowPos({ 5.f + i * 205.f, 5.f }, ImGuiCond_Once);

    ImGui::Begin(category.first.data(), nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar); {
      add_title_bar(category.first.data());

      for (auto& feature : category.second)
        add_feature_button(feature);
    } ImGui::End();

    i++;
  }

  ImGui::SetNextWindowSize({ 200.f, 25.f + (3 * 25.f) });
  ImGui::SetNextWindowPos({ 5.f + 5 * 205.f, 5.f }, ImGuiCond_Once);

  ImGui::Begin("fps_bypass_wnd", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar); {
    add_title_bar("Display");

    if (add_input_button("FPS Bypass", "fps_val", "%.0f FPS", config::display::fps_bypass, config::display::fps_value))
      hacks::display::update_fps_bypass();

    if (add_button("V-Sync", config::display::vsync))
      hacks::display::update_vsync();

    if (add_button("Fullscreen", config::display::fullscreen))
      config::display::fullscreen_update = true;
  } ImGui::End();

  ImGui::SetNextWindowSize({ 200.f, 25.f + (3 * 25.f) });
  ImGui::SetNextWindowPos({ 5.f + 5 * 205.f, 5.f + (4 * 25.f) + 5.f }, ImGuiCond_Once);

  ImGui::Begin("speedhack_wnd", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar); {
    add_title_bar("Speedhack");

    if (add_input_button("Enabled", "speedhack_mult", "%.1fx", config::speedhack::enabled, config::speedhack::multiplier) ||
        add_button("Speedhack Audio", config::speedhack::audio) ||
        add_button("Classic Mode", config::speedhack::classic_mode))
      hacks::speedhack::update();
  } ImGui::End();

  ImGui::SetNextWindowSize({ 200.f, 25.f + (1 * 25.f) });
  ImGui::SetNextWindowPos({ 5.f + 6 * 205.f, 5.f }, ImGuiCond_Once);

  ImGui::Begin("casanova", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar); {
    add_title_bar("Casanova");

    if (add_button("Discord Rich Presence", config::discord_presence)) {
      if (config::discord_presence)
        discord_manager::update_presence = true;
      else
        discord::clear();
    }
  } ImGui::End();

  ImGui::PopFont();
}