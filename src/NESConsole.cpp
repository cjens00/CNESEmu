#include "NESConsole.h"

NESConsole::NESConsole() : memory()
{
    apu = NESAPU();
    cpu = NESCPU();
    ppu = NESPPU();
    rom = NESBinary();
    serviceSDL.InitializeSDL();
    serviceSDL.SetOnUpdateCallback(
            /// Called at refresh rate interval (e.g. 60 Hz)
            [&]()
            {
                /// Begin NESConsole operations
                // Until(Instruction limit reached):
                // cpu -> execute(rom.GetNextBatch())
                // apu -> execute(apu-bound instructions)
                // ppu -> execute(ppu-bound instructions)
                /// End NESConsole operations
                // Give control back to SDL for this interval
                return;
            });
}

void NESConsole::LoadROM(const std::string &filePath)
{
    rom = NESBinary(filePath);
    rom.Read();
}

void NESConsole::UnloadROM()
{

}

void NESConsole::Start()
{
    // Point the CPU to the first instruction
    // Exec ROM instructions
}


void NESConsole::Stop()
{

}

void NESConsole::Pause()
{

}

void NESConsole::Quit()
{

}