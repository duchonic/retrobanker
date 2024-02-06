/**
 * @file Layer.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <vector>
#include <SDL.h>
#include "EventReceiver.h"

class Layer
{
public:
    std::string HandleEvent(const SDL_Event *Event)
    {
        for (const auto Handler : Subscribers)
        {
            auto result = Handler->HandleEvent(Event);
            if (result != "none")
            {
                return result;
            }
        }
        return "none";
    }

    void SubscribeToEvents(EventReceiver *Receiver)
    {
        Subscribers.push_back(Receiver);
    }

private:
    std::vector<EventReceiver *> Subscribers;
};
