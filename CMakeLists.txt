cmake_minimum_required(VERSION 3.22)
project(Cams_NES_Emulator)

set(CMAKE_CXX_STANDARD 23)
set(WindowsSDKDirectory "C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.22000.0\\um\\x64")
link_directories(${WindowsSDKDirectory})
if (WIN32)
    add_link_options(imagehlp.lib dinput8.lib dxguid.lib user32.lib gdi32.lib
            winmm.lib imm32.lib ole32.lib oleaut32.lib shell32.lib version.lib uuid.lib Setupapi.lib)
endif ()
#/NODEFAULTLIB:msvcrtd,msvcrt
add_executable(Cams_NES_Emulator
        src/main.cpp
        src/NESCPU.cpp src/NESMemory.cpp src/NESPPU.cpp
        src/NESAPU.cpp src/ROMLoader.cpp

        include/NESCPU.h include/NESMemory.h include/NESPPU.h
        include/NESAPU.h include/ROMLoader.h src/ServiceSDL.cpp
        include/ServiceSDL.h src/NESBinary.cpp include/NESBinary.h
        src/BitOperations.cpp include/BitOperations.h)
target_include_directories(Cams_NES_Emulator PRIVATE include external)
target_link_libraries(Cams_NES_Emulator PRIVATE
        ../external/sdl/lib/static/SDL2-staticd
        ../external/sdl/lib/static/SDL2maind
        ../external/sdl/lib/static/SDL2_test)