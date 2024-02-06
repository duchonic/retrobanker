#pragma once
#include <SDL.h>

class EventReceiver {
public:
  virtual std::string HandleEvent(const SDL_Event* Event) {
    return "none";
  }
};