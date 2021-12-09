#pragma once

namespace casanova::import_table {
  extern std::map<std::string_view, std::map<std::string_view, uintptr_t>> table;

  inline auto dump_table = []() -> void {
    for (auto& mod : table) {
      console::print(fmt::format(_t("Imports from module {}"), mod.first));

      for (auto& func : mod.second) {
        console::print(fmt::format(_t("Function {} at {:#08x}"), func.first, func.second));
      }
    }
  };
}