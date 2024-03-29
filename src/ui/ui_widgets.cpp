#include <common.hpp>

void casanova::ui::add_title_bar(const char* name) {
  ImVec2 pos = ImGui::GetCursorScreenPos();
  ImGui::GetWindowDrawList()->AddRectFilled({ pos.x - 1, pos.y + 25 }, { pos.x + ImGui::GetWindowWidth() + 2, pos.y }, menu_accent);
  ImGui::SetCursorPosX(100 - (ImGui::CalcTextSize(name).x / 2));
  ImGui::Text("%s", name);
  ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 2.f);
}

bool casanova::ui::add_button(const char* label, bool& enabled, const char* tooltip, ImVec2 pos, ImVec2 size) {
  ImGuiWindow* window = ImGui::GetCurrentWindow();
  ImGuiStyle* style = &ImGui::GetStyle();
  ImGuiID id = window->GetID(label);
  ImRect bb(pos, { pos.x + size.x, pos.y + size.y });
  ImVec2 label_size = ImGui::CalcTextSize(label, nullptr, true);

  ImGui::ItemSize(size, style->FramePadding.y);
  ImGui::ItemAdd(bb, id);

  bool hovered, held;
  bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, ImGuiButtonFlags_None);

  ImGui::PushStyleColor(ImGuiCol_Text, enabled ? menu_accent.Value : ImColor{ 255, 255, 255, 255 }.Value);

  const ImU32 col = ImGui::GetColorU32((held && hovered) ? ImGuiCol_ButtonActive : hovered ? ImGuiCol_ButtonHovered : ImGuiCol_Button);
  ImGui::RenderNavHighlight(bb, id);
  ImGui::RenderFrame(bb.Min, bb.Max, col, true, style->FrameRounding);
  ImGui::RenderTextClipped({ bb.Min.x + style->FramePadding.x, bb.Min.y + style->FramePadding.y }, { bb.Max.x - style->FramePadding.x, bb.Max.y - style->FramePadding.y }, label, NULL, &label_size, style->ButtonTextAlign, &bb);

  ImGui::PopStyleColor();

  window->DrawList->AddRectFilled({ pos.x + size.x - 6.f, pos.y + 4.f }, { pos.x + size.x - 3.f, pos.y + 22.f }, enabled ? menu_accent : ImColor(83, 81, 80, 255));

  if (ImGui::IsItemHovered() && tooltip != nullptr)
    ImGui::SetTooltip("%s", tooltip);

  return pressed;
}

bool casanova::ui::add_button(const char* label, bool& enabled, const char* tooltip) {
  bool changed = add_button(label, enabled, tooltip, ImGui::GetCursorScreenPos(), { 200.f, 25.f });
  if (changed)
    enabled = !enabled;
  return changed;
}

bool casanova::ui::add_input_button(const char* checkbox_label, const char* input_label, const char* fmt, bool& enabled, double& value, const char* tooltip) {
  ImVec2 cursor_pos = ImGui::GetCursorScreenPos();
  double previous_val = value;
  bool previous_enabled = enabled;
  ImGui::SetNextItemWidth(100.f);
  ImGui::InputDouble(input_label, &value, 0.0, 0.0, fmt);
  if (add_button(checkbox_label, enabled, tooltip, { cursor_pos.x + 100.f, cursor_pos.y }, { 100.f, 25.f }))
    enabled = !enabled;
  ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 25.f);
  return enabled != previous_enabled || value != previous_val;
}

void casanova::ui::add_feature_button(casanova::base_features::feature_def_t& feature) {
  if (add_button(feature.name.data(), feature.enabled, feature.desc.data())) {
    casanova::utilities::run_feature(feature);
  }
}
