#pragma once
#include <string>
#include <memory>

// NES ROM Formats
// Type 1: iNES ROM
// Type 2: NES 2.0 ROM

class ROMLoader
{
public:
    ROMLoader();
    std::unique_ptr<uint8_t *> Load(const std::string& filepath);
};