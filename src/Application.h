/**
 * @file Application.h
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
#include "Window.h"

class Application
{
public:
    explicit inline Application(Window *Window) : mWindow{Window}
    {
    }

    SDL_Surface *GetWindowSurface()
    {
        return mWindow->GetSurface();
    }

    void Quit()
    {
        SDL_Event QuitEvent{SDL_QUIT};
        SDL_PushEvent(&QuitEvent);
    }

private:
    Window *mWindow;
};
