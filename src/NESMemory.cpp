#include <NESMemory.h>

NESMemory::NESMemory()
{
    // The 16-bit address space and memory of the NES
    data = std::make_unique<char8_t*>(new char8_t[65536]);
}

NESMemory::~NESMemory()
{
}

void NESMemory::SetMemory(uint16_t address, char8_t value)
{
}
