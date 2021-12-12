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
  } ImGui::End();

  ImGui::SetNextWindowSize({ 200.f, 25.f + (3 * 25.f) });
  ImGui::SetNextWindowPos({ 5.f + 5 * 205.f, 5.f + (4 * 25.f) + 5.f }, ImGuiCond_Once);

  ImGui::Begin(_t("speedhack_wnd"), nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar); {
    add_title_bar(_t("Speedhack"));

    if (add_input_button(_t("Enabled"), _t("speedhack_mult"), _t("%.1fx"), config::speedhack::enabled, config::speedhack::multiplier))
      hacks::speedhack::update();
    if (add_button(_t("Speedhack Audio"), config::speedhack::audio))
      hacks::speedhack::update();
    add_button(_t("Classic Mode"), config::speedhack::classic_mode);
  } ImGui::End();

  ImGui::PopFont();
}