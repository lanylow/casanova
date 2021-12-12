#include <common.hpp>

void casanova::hacks::speedhack::update() {
  game_sdk::CCScheduler* scheduler = game_sdk::CCDirector::shared_director()->get_scheduler();
  game_sdk::Channel* channel = game_sdk::Channel::get_channel();

  if (!config::speedhack::enabled) {
    scheduler->set_time_scale(1.f);
    channel->set_pitch(1.f);
    casanova::hooks::set_speed(1.f);
  }
  else {
    if (config::speedhack::classic_mode) {
      scheduler->set_time_scale(1.f);
      casanova::hooks::set_speed((float)config::speedhack::multiplier);
    }
    else {
      casanova::hooks::set_speed(1.f);
      scheduler->set_time_scale((float)config::speedhack::multiplier);
    }
    
    if (config::speedhack::audio)
      channel->set_pitch((float)config::speedhack::multiplier);
    else
      channel->set_pitch(1.f);
  }
}