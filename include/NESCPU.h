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

class NESCPU
{
    uint16_t PC;
    uint8_t SP;
    uint8_t P;
    uint8_t A;
    uint8_t X;
    uint8_t Y;
public:
    enum memoryAccessMode
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
public:
    NESCPU();

    void DEC();

    void DEX();

    void DEY();

    void JMP();

    void LDA();

    void LDX();

    void LDY();

    void ADC();

    void SBC();

    /// ============

    uint16_t GetPC();

    uint8_t GetSP();

    uint8_t GetP();

    uint8_t GetA();

    uint8_t GetX();

    uint8_t GetY();

    void SetPC(uint16_t value);

    void SetSP(uint8_t value);

    void SetP(uint8_t value);

    void SetA(uint8_t value);

    void SetX(uint8_t value);

    void SetY(uint8_t value);

    /// ============
    void BRK();
    /// ============
};

NESCPU::NESCPU()
{

}

uint16_t NESCPU::GetPC()
{
    return PC;
}

uint8_t NESCPU::GetSP()
{
    return SP;
}

uint8_t NESCPU::GetP()
{
    return P;
}

uint8_t NESCPU::GetA()
{
    return A;
}

uint8_t NESCPU::GetX()
{
    return X;
}

uint8_t NESCPU::GetY()
{
    return Y;
}

void NESCPU::BRK()
{

}

void NESCPU::DEC()
{

}

void NESCPU::DEX()
{

}

void NESCPU::DEY()
{

}

void NESCPU::JMP()
{

}

void NESCPU::LDA()
{

}

void NESCPU::LDX()
{

}

void NESCPU::LDY()
{

}

void NESCPU::ADC()
{

}

void NESCPU::SBC()
{

}

void NESCPU::SetPC(uint16_t value)
{

}

void NESCPU::SetSP(uint8_t value)
{

}

void NESCPU::SetP(uint8_t value)
{

}

void NESCPU::SetA(uint8_t value)
{

}

void NESCPU::SetX(uint8_t value)
{

}

void NESCPU::SetY(uint8_t value)
{

}
