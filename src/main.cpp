//#ifdef WIN32
//#include "sdl/include/SDL_config_windows.h"
/// #include <process.h>
/// #include <signal.h>
//#endif
#include "sdl/include/SDL.h"
#include "NESBinary.h"
#include <iostream>

int TestSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << "\r\n";
        return 1;
    }
    auto temp_window = SDL_CreateWindow("Cam's NES Emulator",
                                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                        1920, 1200, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
    if (!temp_window)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << "\r\n";
        SDL_Quit();
        return 1;
    }
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> sdl_window(
            temp_window, SDL_DestroyWindow);

    auto temp_renderer = SDL_CreateRenderer(
            sdl_window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (temp_renderer == nullptr)
    {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << "\r\n";
        SDL_Quit();
        return 1;
    }

    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> sdl_renderer(
            temp_renderer, SDL_DestroyRenderer);

    std::string imagePath = "../test.bmp";
    SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
    if (bmp == nullptr)
    {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    auto temp_tex = SDL_CreateTextureFromSurface(sdl_renderer.get(), bmp);
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture(temp_tex, SDL_DestroyTexture);
    SDL_FreeSurface(bmp);
    if (texture == nullptr)
    {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    SDL_Event sdl_event;
    for (int i = 0; i < 1000; ++i)
    {
        //First clear the renderer
        SDL_RenderClear(sdl_renderer.get());
        //Draw the texture
        SDL_RenderCopy(sdl_renderer.get(), texture.get(), nullptr, nullptr);
        //Update the screen
        SDL_RenderPresent(sdl_renderer.get());
        SDL_PollEvent(&sdl_event);

        //Take a quick break after all that hard work
        SDL_Delay(30);
    }

    SDL_Quit();
    return 0;
}

int main(int argc, char *argv[])
{
    NESBinary bin("../test/smb-test.nes");
    bin.Read();
    int rv = TestSDL();
    return 0;
}