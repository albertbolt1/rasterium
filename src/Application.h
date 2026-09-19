#pragma once
#include <SDL3/SDL.h>

namespace Rasterium {

class Application
{
public:
    Application();
    ~Application();

    void run();

private:
    SDL_Window* window_;
};

}