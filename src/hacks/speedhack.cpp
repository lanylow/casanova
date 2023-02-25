#include <common.hpp>

void casanova::hacks::speedhack::update() {
  sdk::CCScheduler* scheduler = sdk::CCDirector::shared_director()->get_scheduler();
  sdk::Channel* channel = sdk::Channel::get_channel();
  float multiplier = static_cast<float>(config::speedhack::multiplier);

  if (!config::speedhack::enabled) {
    scheduler->set_time_scale(1.f);
    channel->set_pitch(1.f);
    casanova::hooks::set_speed(1.f);
  }
  else {
    if (config::speedhack::classic_mode) {
      scheduler->set_time_scale(1.f);
      casanova::hooks::set_speed(multiplier);
    }
    else {
      casanova::hooks::set_speed(1.f);
      scheduler->set_time_scale(multiplier);
    }
    
    if (config::speedhack::audio)
      channel->set_pitch(multiplier);
    else
      channel->set_pitch(1.f);
  }
}