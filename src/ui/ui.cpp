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

  ImGui::Begin(_t("fps_bypass_wnd"), nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar); {
    add_title_bar(_t("Display"));

    if (add_input_button(_t("FPS Bypass"), _t("fps_val"), _t("%.0f FPS"), config::display::fps_bypass, config::display::fps_value))
      hacks::display::update_fps_bypass();

    if (add_button(_t("V-Sync"), config::display::vsync))
      hacks::display::update_vsync();

    if (add_button(_t("Fullscreen"), config::display::fullscreen))
      config::display::fullscreen_update = true;
  } ImGui::End();

  ImGui::SetNextWindowSize({ 200.f, 25.f + (3 * 25.f) });
  ImGui::SetNextWindowPos({ 5.f + 5 * 205.f, 5.f + (4 * 25.f) + 5.f }, ImGuiCond_Once);

  ImGui::Begin(_t("speedhack_wnd"), nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar); {
    add_title_bar(_t("Speedhack"));

    if (add_input_button(_t("Enabled"), _t("speedhack_mult"), _t("%.1fx"), config::speedhack::enabled, config::speedhack::multiplier) ||
        add_button(_t("Speedhack Audio"), config::speedhack::audio) ||
        add_button(_t("Classic Mode"), config::speedhack::classic_mode))
      hacks::speedhack::update();
  } ImGui::End();

  ImGui::PopFont();
}