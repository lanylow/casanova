#include <common.hpp>

unsigned long __stdcall casanova::init() {
#ifdef _CONSOLE
  console::attach(_t("casanova debug console"));
  console::print(_t("casanova is now initializing"));
  import_table::dump_table();
#endif

  hooks::init();

  return 0;
}

bool __stdcall DllMain(void* instance, int reason, void* reserved) {
  if (reason != DLL_PROCESS_ATTACH)
    return false;

  casanova::utilities::disable_thread_calls(instance);
  casanova::utilities::create_thread(casanova::init);

  return true;
}