#pragma once

#include <cstdint>
#include <string>
#include <fstream>
#include <filesystem>

enum NESBinaryFormat
{
    iNES = 0,
    NES20 = 1
};

class NESBinary
{
    std::string filePath;
    uint64_t fileSize;
    NESBinaryFormat format;

    /// iNES header (Big thanks to https://nesdev.org/wiki/INES):
    /// 0-3: Constant $4E $45 $53 $1A ("NES" followed by MS-DOS end-of-file)
    /// 4: Size of PRG ROM in 16 KB units
    /// 5: Size of CHR ROM in 8 KB units (Value 0 means the board uses CHR RAM)
    /// 6: Flags 6 - Mapper, mirroring, battery, trainer
    /// 7: Flags 7 - Mapper, VS/PlayChoice, NES 2.0
    /// 8: Flags 8 - PRG-RAM size (rarely used extension)
    /// 9: Flags 9 - TV system (rarely used extension)
    /// 10: Flags 10 - TV system, PRG-RAM presence (unofficial, rarely used extension)
    /// 11-15: Unused padding (should be filled with zero, but some rippers put their name across bytes 7-15)
    uint8_t *header; // 16 bytes

    uint8_t *trainer; // 0-512 bytes
    uint8_t *PRGROM; // 16384 * x bytes
    uint8_t *CHRROM; // 8192 * y bytes
    uint8_t *PlayChoiceINSTROM; // 0 || 8192 bytes
    uint8_t *PlayChoicePROM; // 16 bytes Data, 16 bytes CounterOut
    char8_t *optionalTitle; // 0-128 bytes
public:
    explicit NESBinary(const std::string &pathToBinary);

    bool Read();
};

/// iNES Header, Flags 6:
/// 0: 	Mirroring:
/// 		- 0: horizontal (vertical arrangement) (CIRAM A10 = PPU A11)
/// 		- 1: vertical (horizontal arrangement) (CIRAM A10 = PPU A10)
/// 1: 	1: Cartridge contains battery-backed PRG RAM ($6000-7FFF) or other persistent memory
/// 2: 	1: 512-byte trainer at $7000-$71FF (stored before PRG data)
/// 3: 	1: Ignore mirroring control or above mirroring bit; instead provide four-screen VRAM
/// 4: 	Lower nybble of mapper number
/// 5: 	Lower nybble of mapper number
/// 6: 	Lower nybble of mapper number
/// 7: 	Lower nybble of mapper number