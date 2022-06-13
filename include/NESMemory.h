/// ==================================================================================
/// Memory Map
/// ==================================================================================
/// Address range	Size	Device
/// $0000-$07FF 	$0800 	2KB internal RAM
/// $0800-$0FFF 	$0800 	Mirrors of $0000-$07FF
/// $1000-$17FF		$0800	Mirrors of $0000-$07FF
/// $1800-$1FFF		$0800	Mirrors of $0000-$07FF
/// $2000-$2007		$0008	NES PPU registers
/// $2008-$3FFF		$1FF8 	Mirrors of $2000-2007 (repeats every 8 bytes)
/// $4000-$4017		$0018	NES APU and I/O registers
/// $4018-$401F		$0008	Normally disabled APU and I/O functionality.
/// $4020-$FFFF		$BFE0 	Cartridge space: PRG ROM, PRG RAM, and mapper registers
///
/// The CPU expects interrupt vectors in a fixed place at the end of the cartridge space:
/// $FFFA-$FFFB = NMI vector
/// $FFFC-$FFFD = Reset vector
/// $FFFE-$FFFF = IRQ/BRK vector
/// ==================================================================================
#pragma once
#include <cstdint>

class NESMemory
{
    uint8_t *data;
public:
    NESMemory();
    ~NESMemory();
    void SetMemory(uint16_t address, uint8_t value);
};