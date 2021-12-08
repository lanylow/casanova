#include <common.hpp>

void casanova::init() {

}

bool __stdcall DllMain(void* instance, int reason, void* reserved) {
  if (reason != DLL_PROCESS_ATTACH)
    return false;

  DisableThreadLibraryCalls((HMODULE)instance);
  std::thread(casanova::init).detach();

  return true;
}