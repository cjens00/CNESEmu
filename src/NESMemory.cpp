#include <NESMemory.h>

NESMemory::NESMemory()
{
    // The 16-bit address space and memory of the NES
    data = new uint8_t[65536];
}

NESMemory::~NESMemory()
{
    delete[] data;
}

void NESMemory::SetMemory(uint16_t address, uint8_t value)
{
    *(data + address) = value;
}
