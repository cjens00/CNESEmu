#pragma once
#include <iostream>
#include <memory>
#include <sdl/include/SDL.h>

/// Typedefs for std::unique_ptr objects
typedef decltype(&SDL_DestroyWindow) SDLDestroyWindowType;
typedef decltype(&SDL_DestroyRenderer) SDLDestroyRendererType;
typedef decltype(&SDL_DestroyTexture) SDLDestroyTextureType;
typedef decltype(&SDL_DestroyCond) SDLDestroyCondType;
typedef decltype(&SDL_DestroySemaphore) SDLDestroySemaphoreType;
typedef decltype(&SDL_DestroyMutex) SDLDestroyMutexType;

class ServiceSDL
{
    std::unique_ptr<SDL_Window, SDLDestroyWindowType> window;
    std::unique_ptr<SDL_Renderer, SDLDestroyRendererType> renderer;
public:
    ServiceSDL();

    int InitializeSDL();

    const std::unique_ptr<SDL_Window, SDLDestroyWindowType> &GetWindow() const;

    const std::unique_ptr<SDL_Renderer, SDLDestroyRendererType> &GetRenderer() const;

};
