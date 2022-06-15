#pragma once

#include <bitset>
#include <cstdint>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "BitOperations.h"

enum NESBinaryFormat
{
    iNES = 0,
    NES20 = 1
};

struct HeaderFlags
{
    bool verticalMirror;
    bool hasPersistentMemory;
    bool hasTrainer;
    bool usesCHRRAM;
};

class NESBinary
{
    std::string filePath;
    unsigned long int fileSize;
    NESBinaryFormat format;

    /// iNES header (Big thanks to https://nesdev.org/wiki/INES):
    /// <br>0-3: Constant $4E $45 $53 $1A ("NES" followed by MS-DOS end-of-file)
    /// <br>4: Size of PRG ROM in 16 KB units
    /// <br>5: Size of CHR ROM in 8 KB units (Value 0 means the board uses CHR RAM)
    /// <br>6: Flags 6 - Mapper, mirroring, battery, trainer
    /// <br>7: Flags 7 - Mapper, VS/PlayChoice, NES 2.0
    /// <br>8: Flags 8 - PRG-RAM size (rarely used extension)
    /// <br>9: Flags 9 - TV system (rarely used extension)
    /// <br>10: Flags 10 - TV system, PRG-RAM presence (unofficial, rarely used extension)
    /// <br>11-15: Unused padding (should be filled with zero, but some rippers put their name across bytes 7-15)
    char8_t *header; // 16 bytes
    char8_t *trainer; // 0-512 bytes
    uint32_t szPRGROM;
    uint32_t szCHRROM;
    char8_t *PRGROM; // 16384*x bytes
    char8_t *CHRROM; // 8192*y bytes
    char8_t *playChoiceINSTROM; // 0 || 8192 bytes
    char8_t *playChoicePROM; // 16 bytes Data, 16 bytes CounterOut
    char8_t *optionalTitle; // 0-128 bytes

    /// ROM Option Flags
    bool bMirrorVertical;
    bool bHasPersistentMemory;
    bool bHasTrainer;
    bool bUsingCHRRAM;
    /// End Flags
public:
    NESBinary();
    explicit NESBinary(const std::string &pathToBinary);

    ~NESBinary();

    bool Read();
};

/// iNES Header, Flags 6:
/// <br>0: 	Mirroring:
/// <br>---- 0: horizontal (vertical arrangement) (CIRAM A10 = PPU A11)</li>
/// <br>---- 1: vertical (horizontal arrangement) (CIRAM A10 = PPU A10)</li>
/// <br>1: 	1: Cartridge contains battery-backed PRG RAM ($6000-7FFF) or other persistent memory
/// <br>2: 	1: 512-byte trainer at $7000-$71FF (stored before PRG data)
/// <br>3: 	1: Ignore mirroring control or above mirroring bit; instead provide four-screen VRAM
/// <br>4: 	Lower nybble of mapper number
/// <br>5: 	Lower nybble of mapper number
/// <br>6: 	Lower nybble of mapper number
/// <br>7: 	Lower nybble of mapper number

