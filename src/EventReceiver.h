/**
 * @file EventReceiver.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <SDL.h>
#include <string>

class EventReceiver {
public:
  virtual std::string HandleEvent(const SDL_Event* Event) {
    return "none";
  }
};
