#pragma once

namespace casanova::utilities {
  inline auto disable_thread_calls = [](void* instance) -> void { 
    _f(DisableThreadLibraryCalls)((HMODULE)instance); 
  };

  inline auto create_thread = [](void* func) -> void {
    _f(CreateThread)(nullptr, 0, (LPTHREAD_START_ROUTINE)func, nullptr, 0, nullptr);
  };

  inline auto get_module = [](std::string_view name) -> uintptr_t {
    return (uintptr_t)(_f(GetModuleHandleA)(name.data()));
  };

  inline auto get_function = [](std::string_view mod, std::string_view name) -> uintptr_t {
    return (uintptr_t)(_f(GetProcAddress)((HMODULE)get_module(mod), name.data()));
  };
}