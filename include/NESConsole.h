#pragma once

#include "NESCPU.h"
#include "NESPPU.h"
#include "NESAPU.h"
#include "NESMemory.h"
#include "NESBinary.h"
#include "ServiceSDL.h"

class NESConsole
{
    NESAPU apu;
    NESCPU cpu;
    NESPPU ppu;
    NESMemory memory;
    NESBinary cartridge;
    ServiceSDL serviceSDL;
public:
    NESConsole();
    void PowerOn();
};