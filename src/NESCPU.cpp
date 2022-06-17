#include "NESCPU.h"


NESCPU::NESCPU()
{
    PC = {};
    SP = {};
    P = {};
    A = {};
    X = {};
    Y = {};
    targetClockRate = 1789773;
    refreshRate = 60;
    cyclesPerInterval = targetClockRate / refreshRate;
    cyclesThisInterval = 0;
    totalCycles = 0;
}