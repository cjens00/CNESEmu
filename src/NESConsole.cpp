#include "NESConsole.h"

NESConsole::NESConsole()
{
    apu = NESAPU();
    cpu = NESCPU();
    memory = NESMemory();
    ppu = NESPPU();
    rom = NESBinary("../test/smb-test.nes");
    initSuccess = serviceSDL.InitializeSDL();
}

bool NESConsole::Initialized() const
{
    return initSuccess;
}

void NESConsole::PowerOn()
{
}

void NESConsole::PowerOff()
{

}

void NESConsole::LoadROM()
{

}

void NESConsole::UnloadROM()
{

}
