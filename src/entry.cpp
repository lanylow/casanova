#include <common.hpp>

void casanova::init() {
  console::attach("casanova debug console");
  console::print("casanova is now initializing");
  import_table::dump_table();

  hooks::init();

  while (!ready)
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

  discord_manager::run();
}

bool __stdcall DllMain(void* instance, int reason, void* reserved) {
  switch (reason) {
    case DLL_PROCESS_ATTACH: {
      casanova::utilities::disable_thread_calls(instance);
      std::thread(casanova::init).detach();
      break;
    }

    case DLL_PROCESS_DETACH: {
      casanova::discord::shutdown();
      break;
    }
  }

  return true;
}