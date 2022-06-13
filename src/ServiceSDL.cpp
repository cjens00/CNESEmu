#include "ServiceSDL.h"

ServiceSDL::ServiceSDL() : window(nullptr, nullptr), renderer(nullptr, nullptr)
{
}

int ServiceSDL::InitializeSDL()
{
    int ec = SDL_Init(SDL_INIT_VIDEO);
    if (ec != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << "\r\n";
        return 1;
    }
    return 0;
}

const std::unique_ptr<SDL_Window, SDLDestroyWindowType> &ServiceSDL::GetWindow() const
{
    return window;
}

const std::unique_ptr<SDL_Renderer, SDLDestroyRendererType> &ServiceSDL::GetRenderer() const
{
    return renderer;
}