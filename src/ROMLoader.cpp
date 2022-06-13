#include "ROMLoader.h"

ROMLoader::ROMLoader()
{
    ;
}

std::unique_ptr<uint8_t*> ROMLoader::Load(const std::string& filepath)
{
    // Determine if NES 2.0 or iNES format
    // Read into buffer
    // Map to memory
    // Return unique pointer for the memory
    return std::make_unique<uint8_t*>(new uint8_t[1]);
}
