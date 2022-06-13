#include "BitOperations.h"

bool BitOperations::ReadBit(unsigned char byte, int bit)
{
    return (byte >> bit) & 1;
}