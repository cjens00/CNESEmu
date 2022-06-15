#include "ServiceSDL.h"

ServiceSDL::ServiceSDL() : window(nullptr, nullptr), renderer(nullptr, nullptr)
{}

ServiceSDL::~ServiceSDL()
{ SDL_Quit(); }

bool ServiceSDL::InitializeSDL()
{
    if (!SDLInit()) return false;
    if (!SDLInitWindow()) return false;
    if (!SDLInitRenderer()) return false;
    return true;
}

const std::unique_ptr<SDL_Window, SDLDestroyWindowType> &ServiceSDL::GetWindow() const
{ return window; }

const std::unique_ptr<SDL_Renderer, SDLDestroyRendererType> &ServiceSDL::GetRenderer() const
{ return renderer; }

bool ServiceSDL::SDLInit()
{
    return SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) == 0;
}

bool ServiceSDL::SDLInitWindow()
{
    auto temp = SDL_CreateWindow("CNESEmu",
                                 SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED,
                                 1920, 1200,
                                 SDL_WINDOW_SHOWN |
                                 SDL_WINDOW_ALLOW_HIGHDPI);
    if (!temp) return false;
    window = SDLWindowPtrUnq(temp, SDL_DestroyWindow);
    return true;
}

bool ServiceSDL::SDLInitRenderer()
{
    auto temp = SDL_CreateRenderer(window.get(), -1,
                                   SDL_RENDERER_ACCELERATED |
                                   SDL_RENDERER_PRESENTVSYNC);
    if (!temp) return false;
    renderer = SDLRendererPtrUnq(temp, SDL_DestroyRenderer);
    return true;
}

SDLSurfacePtrUnq ServiceSDL::SDLCreateSurfaceFromBitmap(const std::string &pathToBitmap)
{
    auto temp = SDL_LoadBMP(pathToBitmap.c_str());
    if (!temp)
    {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return {nullptr, nullptr};
    }
    return {temp, SDL_FreeSurface};
}

SDLTexturePtrUnq ServiceSDL::SDLCreateTextureFromSurface(SDLSurfacePtrUnq surface)
{
    auto temp = SDL_CreateTextureFromSurface(renderer.get(), surface.get());
    if (!temp)
    {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return {nullptr, nullptr};
    }
    return {temp, SDL_DestroyTexture};
}
