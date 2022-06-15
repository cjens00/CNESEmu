#include "NESConsole.h"

NESConsole::NESConsole() : memory()
{
    apu = NESAPU();
    cpu = NESCPU();
    ppu = NESPPU();
    rom = NESBinary("../test/smb-test.nes");
    rom.Read(); // debug
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
