#include <cstdio>
#include <iostream>
#include "Application.h"

namespace Rasterium
{

    Application::Application()
    {
       if(!SDL_Init(SDL_INIT_VIDEO))
       {
        std::cerr << "SDL_INIT failed" << SDL_GetError() << std::endl;
        return;
       }
        window_ = SDL_CreateWindow(
            "Rasterium",
            800,
            600,
            0);
        if(!SDL_ShowWindow(window_))
        {
            std::cerr << "SDL_ShowWindow failed" << SDL_GetError() << std::endl;
            return;
        }
        if(!SDL_RaiseWindow(window_))
        {
            std::cerr << "SDL_RaiseWindow failed" << SDL_GetError() << std::endl;
            return;
        }
        if(!SDL_SetWindowPosition(
            window_,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED))
        {
            std::cerr << "SDL_SetWindowPosition failed" << SDL_GetError() << std::endl;
            return;
        }

        renderer_ = SDL_CreateRenderer(window_, nullptr);

        if(renderer_ == nullptr)
        {
            std::cerr << "SDL_CreateRenderer failed" << SDL_GetError() << std::endl;
            return;
        }





    }

    Application::~Application()
    {
        SDL_DestroyRenderer(renderer_);
        SDL_DestroyWindow(window_);
        SDL_Quit();
    }

    void Application::run()
    {

        bool running = true;

        Uint64 lastTime = SDL_GetPerformanceCounter();
        double deltaTime = 0.0;
        x_=100;
        y_=100;
        while (running)
        {

           
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_EVENT_QUIT)
                {
                    running = false;
                }
            }

            SDL_SetRenderDrawColor(renderer_, 0, 120, 0, 255);
            SDL_RenderClear(renderer_);

            // performance counter will give us the current ticks
            Uint64 currentTime = SDL_GetPerformanceCounter();

            // frequency will give ticks per second, so delta time is in seconds
            deltaTime = (double)(currentTime - lastTime) / SDL_GetPerformanceFrequency();
            lastTime = currentTime;

            // so if its been 15ms then it should be 100 * 0.015 = 1.5 pixels moved 
            x_+= 10 * deltaTime;
            y_+= 10 * deltaTime;

            SDL_FRect rect = { x_, y_, 200, 150 };
            SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);
            SDL_RenderFillRect(renderer_, &rect);
            SDL_RenderPresent(renderer_);
        }

    }
}