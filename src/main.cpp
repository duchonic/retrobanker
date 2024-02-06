/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <SDL.h>

#include "Window.h"
#include "Layer.h"
#include "Button.h"
#include "Application.h"
#include <iostream>

int main()
{
    Window GameWindow;
    Application App(&GameWindow);
    Layer UI;
    Button StartButton{&App, 2, 20, 50, 18, "Start"};
    Button PauseButton{&App, 2, 40, 50, 18, "Pause"};
    UI.SubscribeToEvents(&StartButton);
    UI.SubscribeToEvents(&PauseButton);

    SDL_Event event;

    while (true)
    {
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                std::cout << "Quit event detected" << std::endl;
                break;
            }
            auto result = UI.HandleEvent(&event);
            if (result != "none")
            {
                if (result == "Start")
                {
                    std::cout << "Press Start to play" << std::endl;
                }
                else if (result == "Pause")
                {
                    std::cout << "Pause" << std::endl;
                }
            }
        }
        GameWindow.RenderFrame();
    }
}
