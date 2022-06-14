#pragma once

#include <iostream>
#include <memory>
#include <sdl/include/SDL.h>

/// =========================================================================
/// Typedefs for std::unique_ptr objects
typedef decltype(&SDL_DestroyWindow) SDLDestroyWindowType;
typedef decltype(&SDL_DestroyRenderer) SDLDestroyRendererType;
typedef decltype(&SDL_DestroyTexture) SDLDestroyTextureType;
typedef decltype(&SDL_DestroyCond) SDLDestroyCondType;
typedef decltype(&SDL_DestroySemaphore) SDLDestroySemaphoreType;
typedef decltype(&SDL_DestroyMutex) SDLDestroyMutexType;
typedef decltype(&SDL_FreeSurface) SDLFreeSurfaceType;

typedef std::unique_ptr<SDL_Window, SDLDestroyWindowType> SDLWindowPtrUnq;
typedef std::unique_ptr<SDL_Renderer, SDLDestroyRendererType> SDLRendererPtrUnq;

typedef std::unique_ptr<SDL_Surface, SDLFreeSurfaceType> SDLSurfacePtrUnq;
typedef std::unique_ptr<SDL_Texture, SDLDestroyTextureType> SDLTexturePtrUnq;
/// =========================================================================

class ServiceSDL
{
    SDLWindowPtrUnq window;
    SDLRendererPtrUnq renderer;
public:
    ServiceSDL();

    bool InitializeSDL();

    const SDLWindowPtrUnq &GetWindow() const;

    const SDLRendererPtrUnq &GetRenderer() const;

private:
    bool SDLInit();

    bool SDLInitWindow();

    bool SDLInitRenderer();

    SDLSurfacePtrUnq SDLCreateSurfaceFromBitmap(const std::string &pathToBitmap);

    SDLTexturePtrUnq SDLCreateTextureFromSurface(SDLSurfacePtrUnq surface);
};
