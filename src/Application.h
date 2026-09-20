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
    SDL_Renderer* renderer_;
    float x_, y_;
    bool up_pressed_    = false;
    bool down_pressed_  = false;
    bool left_pressed_  = false;
    bool right_pressed_ = false;
};

}