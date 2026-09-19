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
    }

    Application::~Application()
    {
        SDL_DestroyWindow(window_);
        SDL_Quit();
    }

    void Application::run()
    {

        bool running = true;

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

            SDL_Delay(16);
        }

    }
}