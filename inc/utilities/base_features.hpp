#pragma once

namespace casanova::base_features {
  struct patch_def_t {
    uintptr_t offset;
    std::string_view on_enable;
    std::string_view on_disable;
  };

  struct ref_def_t {
    uintptr_t src;
    uintptr_t dest;
  };

  struct feature_def_t {
    std::string_view name;
    std::string_view desc;
    std::vector<patch_def_t> patches;
    std::vector<ref_def_t> references;
  };

  extern std::map<std::string_view, std::vector<feature_def_t>> table;
}