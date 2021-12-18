#include <common.hpp>

void casanova::discord::init() {
  DiscordEventHandlers event_handlers;
  std::memset(&event_handlers, 0, sizeof(event_handlers));
  Discord_Initialize(_t("820941087467896834"), &event_handlers, 1, _t("322170"));
}

void casanova::discord::update(const char* details, const char* large_text, const char* small_text, const char* state, const char* small_image, std::time_t timestamp) {
  DiscordRichPresence presence;
  std::memset(&presence, 0, sizeof(presence));

  if (std::strlen(state) != 0)
    presence.state = state;

  presence.details = details;
  presence.startTimestamp = timestamp;
  presence.largeImageKey = _t("logo");
  presence.largeImageText = large_text;

  if (std::strcmp(small_image, _t("none")) != 0) {
    presence.smallImageKey = small_image;
    presence.smallImageText = small_text;
  }

  Discord_UpdatePresence(&presence);
}

void casanova::discord::shutdown() {
  Discord_Shutdown();
}

void casanova::discord::clear() {
  Discord_ClearPresence();
}