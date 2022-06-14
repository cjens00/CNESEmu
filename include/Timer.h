#pragma once
#include <sdl/include/SDL.h>

/// Some code from
/// https://lazyfoo.net/tutorials/SDL/23_advanced_timers/index.php

class Timer
{
    bool isPaused;
    bool isStarted;
    unsigned int startTicks;
    unsigned int pausedTicks;
public:
    Timer();
    void Start();
    void Stop();
    void Pause();
    void Unpause();
    bool IsStarted();
    bool IsPaused();
    unsigned int GetTicks();
};