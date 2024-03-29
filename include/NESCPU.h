/// ==================================================================================
/// Registers [information taken from https://www.nesdev.org/wiki/CPU_registers]
/// ==================================================================================
/// Program Counter (PC)
/// The 2-byte program counter PC supports 65536 direct (unbanked) memory locations,
/// however not all values are sent to the cartridge. It can be accessed either by
/// allowing CPU's internal fetch logic increment the address bus,
/// an interrupt (NMI, Reset, IRQ/BRQ), and using the RTS/JMP/JSR/Branch instructions.
///
/// Stack Pointer (SP)
/// S is byte-wide and can be accessed using interrupts, pulls, pushes, and transfers.
///
/// Status (P)
/// P has 6 bits used by the ALU but is byte-wide. PHP, PLP, arithmetic,
/// testing, and branch instructions can access this register.
/// ========= Flags =========
/// [NVssDIZC]
/// N - Negative
/// V - Overflow
/// s - No CPU effect
/// s - No CPU effect
/// D - Decimal (Not used in NES)
/// I - Interrupt Disable
/// Z - Zero
/// C - Carry
///
/// Accumulator (A)
/// A is byte-wide and along with the arithmetic logic unit (ALU), supports using
/// the status register for carrying, overflow detection, and so on.
///
/// Index X (X)
/// Index Y (Y)
/// X and Y are byte-wide and used for several addressing modes. They can be used as
/// loop counters easily, using INC/DEC and branch instructions. Not being the
/// accumulator, they have limited addressing modes themselves when loading and saving.

#pragma once

#include <cstdint>

/// Accumulator:    Intermediate value register for ALU operations
/// Index Register: Contents added to or subtracted from an immediate address
///                 to form the effective address of the actual data (operand)
/// Status Register: Describes the outcome of an operation using bit flags

/// 6502 Instructions:
/// ADC AND ASL BCC BCS BEQ BIT BMI BNE BPL BRK BVC BVS CLC
/// CLD CLI CLV CMP CPX CPY DEC DEX DEY EOR INC INX INY JMP
/// JSR LDA LDX LDY LSR NOP ORA PHA PHP PLA PLP ROL ROR RTI
/// RTS SBC SEC SED SEI STA STX STY TAX TAY TSX TXA TXS TYA

enum MemoryAccessMode
{
    Implicit = 0,
    Accumulator = 1,
    Immediate = 2,
    ZeroPage = 3,
    Absolute = 4,
    Relative = 5,
    Indirect = 6,

    ZeroPageIndexedX = 7,
    ZeroPageIndexedY = 8,
    AbsoluteIndexedX = 9,
    AbsoluteIndexedY = 10,
    IndirectIndexedX = 11,
    IndirectIndexedY = 12
};

class NESCPU
{
    uint16_t PC;
    uint8_t SP;
    uint8_t P;
    uint8_t A;
    uint8_t X;
    uint8_t Y;
    uint32_t cyclesThisInterval;
    uint64_t totalCycles;
    uint8_t refreshRate;
    uint32_t targetClockRate;
    uint32_t cyclesPerInterval;
public:
public:
    NESCPU();
};
