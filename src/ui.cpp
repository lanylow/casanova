#include <common.hpp>

void add_title_bar(const char* name) {
  ImVec2 pos = ImGui::GetCursorScreenPos();
  ImGui::GetWindowDrawList()->AddRectFilled({ pos.x - 1, pos.y + 25 }, { pos.x + ImGui::GetWindowWidth() + 2, pos.y }, ImColor(238, 119, 98, 255));
  ImGui::PushFont(casanova::ui::font);
  ImGui::SetCursorPosX(100 - (ImGui::CalcTextSize(name).x / 2));
  ImGui::Text("%s", name);
  ImGui::PopFont();
}

void add_button(casanova::base_features::feature_def_t& feature) {
  ImGuiWindow* window = ImGui::GetCurrentWindow();
  ImGuiStyle* style = &ImGui::GetStyle();
  ImGuiID id = window->GetID(feature.name.data());
  ImVec2 pos = window->DC.CursorPos;
  ImRect bb(pos, { pos.x + 200.f, pos.y + 25.f });
  ImVec2 label_size = ImGui::CalcTextSize(feature.name.data(), nullptr, true);

  ImGui::ItemSize({ 200.f, 25.f }, style->FramePadding.y);
  ImGui::ItemAdd(bb, id);

  bool hovered, held;
  bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, ImGuiButtonFlags_None);

  if (pressed)
    feature.enabled = !feature.enabled;

  if (feature.enabled)
    ImGui::PushStyleColor(ImGuiCol_Text, ImColor(238, 119, 98, 255).Value);
  else
    ImGui::PushStyleColor(ImGuiCol_Text, ImColor(255, 255, 255, 255).Value);

  const ImU32 col = ImGui::GetColorU32((held && hovered) ? ImGuiCol_ButtonActive : hovered ? ImGuiCol_ButtonHovered : ImGuiCol_Button);
  ImGui::RenderNavHighlight(bb, id);
  ImGui::RenderFrame(bb.Min, bb.Max, col, true, style->FrameRounding);
  ImGui::RenderTextClipped({ bb.Min.x + style->FramePadding.x, bb.Min.y + style->FramePadding.y }, {bb.Max.x - style->FramePadding.x, bb.Max.y - style->FramePadding.y}, feature.name.data(), NULL, &label_size, style->ButtonTextAlign, &bb);

  ImGui::PopStyleColor();

  window->DrawList->AddRectFilled({ pos.x + ImGui::GetWindowWidth() - 7.f, pos.y + 2.f }, { pos.x + ImGui::GetWindowWidth() - 3.f, pos.y + 23.f }, feature.enabled ? ImColor(238, 119, 98, 255) : ImColor(83, 81, 80, 255));
}

void casanova::ui::render() {
  if (!opened)
    return;

  int i = 0;

  for (auto& category : base_features::table) {
    ImGui::SetNextWindowSize({ 200.f, 25.f + (category.second.size() * 25.f) + 7.f });
    ImGui::SetNextWindowPos({ 10.f + i * 210.f, 10.f }, ImGuiCond_Once);

    ImGui::Begin(category.first.data(), nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar); {
      add_title_bar(category.first.data());

      for (auto& feature : category.second)
        add_button(feature);
    } ImGui::End();

    i++;
  }
}