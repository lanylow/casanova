#pragma once

namespace casanova::utilities {
  inline auto disable_thread_calls = [](void* instance) -> void { 
    DisableThreadLibraryCalls(reinterpret_cast<HMODULE>(instance)); 
  };

  inline auto create_thread = [](void* func) -> void {
    CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(func), nullptr, 0, nullptr);
  };

  inline auto get_module = [](std::string_view name) -> uintptr_t {
    return reinterpret_cast<uintptr_t>(GetModuleHandleA(name.data()));
  };

  inline auto get_function = [](std::string_view mod, std::string_view name) -> uintptr_t {
    return reinterpret_cast<uintptr_t>(GetProcAddress(reinterpret_cast<HMODULE>(get_module(mod)), name.data()));
  };

  template <typename t, typename... targs>
  inline auto thiscall_function = [](std::string_view mod, std::string_view name, targs... args) -> t {
    return reinterpret_cast<t(__thiscall*)(targs...)>(import_table::table[mod][name])(std::forward<targs>(args)...);
  };

  template <typename t, typename... targs>
  inline auto stdcall_function = [](std::string_view mod, std::string_view name, targs... args) -> t {
    return reinterpret_cast<t(__stdcall*)(targs...)>(import_table::table[mod][name])(std::forward<targs>(args)...);
  };

  template <typename t, typename... targs>
  inline auto call_function = [](std::string_view mod, std::string_view name, targs... args) -> t {
    return reinterpret_cast<t(*)(targs...)>(import_table::table[mod][name])(std::forward<targs>(args)...);
  };

  inline auto resolve_multilevel = [](uintptr_t start, std::vector<uintptr_t> offsets) -> uintptr_t {
    auto i = offsets.begin();
    uintptr_t* cur = reinterpret_cast<uintptr_t*>(start + *i);
    std::advance(i, 1);

    while (i != offsets.end()) {
      cur = reinterpret_cast<uintptr_t*>(*cur + *i);
      std::advance(i, 1);
    }

    return reinterpret_cast<uintptr_t>(cur);
  };

  inline auto pattern_to_bytes = [](const char* pattern) -> std::vector<uint8_t> {
    std::vector<uint8_t> bytes = { };

    auto start = const_cast<char*>(pattern);
    auto end = start + strlen(pattern);

    for (auto current = start; current < end; ++current)
      bytes.push_back(static_cast<uint8_t>(strtoul(current, &current, 16)));

    return bytes;
  };

  inline auto patch_memory = [](uintptr_t address, std::vector<uint8_t> bytes) {
    unsigned long old;
    VirtualProtect(reinterpret_cast<void*>(address), bytes.size(), PAGE_EXECUTE_READWRITE, &old);

    for (size_t i = 0; i < bytes.size(); i++)
      *reinterpret_cast<uint8_t*>(address + i) = bytes[i];

    VirtualProtect(reinterpret_cast<void*>(address), bytes.size(), old, &old);
  };

  inline auto reference_memory = [](uintptr_t base, uintptr_t src, uintptr_t dest) -> void {
    unsigned long old;
    VirtualProtect(reinterpret_cast<void*>(base + src), 4, PAGE_EXECUTE_READWRITE, &old);
    *reinterpret_cast<uintptr_t*>(base + src) = base + dest;
    VirtualProtect(reinterpret_cast<void*>(base + src), 4, old, &old);
  };

  inline auto run_feature = [](base_features::feature_def_t& feature) -> void {
    for (auto& patch : feature.patches)
      patch_memory(get_module(patch.library) + patch.offset,
        feature.enabled ? pattern_to_bytes(patch.on_enable.data()) : pattern_to_bytes(patch.on_disable.data()));

    for (auto& ref : feature.references)
      if (ref.on_enable == feature.enabled)
        reference_memory(get_module(ref.library), ref.src, ref.dest);
  };
}