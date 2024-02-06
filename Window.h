/**
 * This file contains the Window class, which is responsible for creating and
*/

#pragma once
#include <SDL.h>

class Window {
  public:
    Window() {
      SDL_Init(SDL_INIT_VIDEO);
      SDLWindow = SDL_CreateWindow(
        "SDL2 Window",
        SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
        windowWidth,
        windowHeight,
        0
      );

      SDLWindowSurface = SDL_GetWindowSurface(SDLWindow);

      SDL_FillRect(
        SDLWindowSurface,
        nullptr,
        SDL_MapRGB(SDLWindowSurface->format, 
            backgroudRed, backgroudGreen, backgroudBlue)
      );
    }

    void RenderFrame() {
      SDL_UpdateWindowSurface(SDLWindow);
    }

    SDL_Surface* GetSurface() {
      return SDLWindowSurface;
    }

  private:
    SDL_Window* SDLWindow{nullptr};
    SDL_Surface* SDLWindowSurface{nullptr};

    int windowHeight {400};
    int windowWidth {300};

    int backgroudRed {40};
    int backgroudGreen {40};
    int backgroudBlue {40};
};