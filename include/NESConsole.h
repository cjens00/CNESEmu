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
    NESBinary rom;
    ServiceSDL serviceSDL;
    bool initSuccess;
public:
    NESConsole();
    bool Initialized() const;
    void PowerOn();
    void PowerOff();
    void LoadROM();
    void UnloadROM();
};