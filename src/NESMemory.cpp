#include <NESMemory.h>

NESMemory::NESMemory()
{
    // The 16-bit address space and memory of the NES
    data = std::make_unique<uint8_t*>(new uint8_t[65536]);
}

NESMemory::~NESMemory()
{
}

void NESMemory::SetMemory(uint16_t address, uint8_t value)
{
}
