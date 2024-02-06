/**
 * @file Button.h
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
#include <iostream>

#include "src/EventReceiver.h"
#include "src/Application.h"

#include <SDL_ttf.h>

class Button : public EventReceiver
{
public:
    Button(Application *App, int x, int y, int w, int h, std::string id) : SDLWindowSurface{App->GetWindowSurface()},
                                                                           App{App},
                                                                           Rect{x, y, w, h},
                                                                           id{id}
    {
        TTF_Init();

        if (TTF_Init() == -1)
        {
            std::cout << "TTF_Init failed" << std::endl;
        }
        else
        {
            std::cout << "TTF_Init success" << std::endl;
        }

        Update();
    }

    std::string HandleEvent(const SDL_Event *Event) override
    {
        if (Event->type == SDL_MOUSEBUTTONDOWN &&
            Event->button.button == SDL_BUTTON_LEFT && isHovered)
        {
            std::cout << "Button id " << id << " clicked" << std::endl;
            return id;
        }
        else if (Event->type == SDL_MOUSEMOTION) [[likely]]
        {
            if (isHovered != IsWithinBounds(Event->motion.x, Event->motion.y))
            {
                isHovered = !isHovered;
                Update();
            }
        }
        return "none";
    }

private:
    bool IsWithinBounds(int x, int y)
    {
        // Too far left
        if (x < Rect.x)
        {
            return false;
        }

        // Too far right
        if (x > Rect.x + Rect.w)
        {
            return false;
        }

        // Too high
        if (y < Rect.y)
        {
            return false;
        }

        // Too low
        if (y > Rect.y + Rect.h)
        {
            return false;
        }

        // Inside rectangle
        return true;
    }

    void Update()
    {
        auto [r, g, b, a]{isHovered ? HoverColor : BGColor};

        SDL_Surface *textSurface = TTF_RenderUTF8_Blended(TTF_OpenFont("../assets/RobotoMono-Bold.ttf", 12), id.c_str(), {0, 0, 0});

        SDL_FillRect(SDLWindowSurface, &Rect, SDL_MapRGB(SDLWindowSurface->format, r, g, b));
        if (textSurface == nullptr)
        {
            std::cout << "TTF_RenderText_Solid failed" << std::endl;
        }
        else
        {
            std::cout << "TTF_RenderText_Solid success" << std::endl;
            SDL_Rect source = {0, 0, textSurface->w, textSurface->h};
            SDL_Rect dest{Rect};
            dest.x += 4;
            SDL_BlitSurface(textSurface, &source, SDLWindowSurface, &dest);
        }
    }

    bool isHovered{false};
    const SDL_Color BGColor{50, 255, 50, 255};
    const SDL_Color HoverColor{50, 50, 255, 255};
    const SDL_Rect Rect;
    Application *App{nullptr};
    SDL_Surface *SDLWindowSurface{nullptr};
    SDL_Surface *surfaceMessage{nullptr};

    std::string id;
};
