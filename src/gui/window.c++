#include "gui/window.h"

Window::Window()
{
    WIDTH = 860;
    HEIGHT = 640;
    isInit = false;
    isRun = false;
}

void Window::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "could not initialize sdl2: " << SDL_GetError() << std::endl;
    }
    else
    {
        isInit = true;
    }
}

void Window::keyboardUntilQuit(SDL_Window *window)
{
    SDL_Event kevent;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&kevent))
        {
            switch (kevent.type)
            {
            case SDL_KEYDOWN:
                std::cout << "KEYDOWN: " << SDL_GetKeyName(kevent.key.keysym.sym) << " pressed\n";
                break;
            case SDL_QUIT:
                std::cout << "\nBye!\n";
                quit = true;
                SDL_DestroyWindow(window);
                break;
            default:
                break;
            }
        }
    }
};

void Window::run()
{
    if (!isInit)
    {
        init();
    }
    SDL_Window *window = SDL_CreateWindow(
        "main",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WIDTH, HEIGHT,
        SDL_WINDOW_SHOWN);

    keyboardUntilQuit(window);
    SDL_Quit();
};