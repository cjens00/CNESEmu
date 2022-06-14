#include "Timer.h"

Timer::Timer()
{
    //Initialize the variables
    startTicks = 0;
    pausedTicks = 0;
    isPaused = false;
    isStarted = false;
}

void Timer::Start()
{
    startTicks = SDL_GetTicks();
    pausedTicks = 0;
    isStarted = true;
    isPaused = false;
}

void Timer::Stop()
{
    startTicks = 0;
    pausedTicks = 0;
    isPaused = false;
    isStarted = false;
}

void Timer::Pause()
{
    if (isStarted && !isPaused)
    {
        isPaused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
        startTicks = 0;
    }
}

void Timer::Unpause()
{
    if (isStarted && isPaused)
    {
        isPaused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}

bool Timer::IsStarted()
{
    return isStarted;
}

bool Timer::IsPaused()
{
    return isStarted && isPaused;
}

unsigned int Timer::GetTicks()
{
    unsigned int time = 0;
    if (isStarted)
    {
        if (isPaused)
        { time = pausedTicks; }
        else
        { time = SDL_GetTicks() - startTicks; }
    }
    return time;
}
