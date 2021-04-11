#include "gui/window.h"

Window::Window()
{
    WIDTH = 860;
    HEIGHT = 640;
    running = false;
    init();
}

void Window::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "could not initialize sdl2: " << SDL_GetError() << std::endl;
    }

    if (TTF_Init() < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    window = SDL_CreateWindow(
        "main",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WIDTH, HEIGHT,
        SDL_WINDOW_HIDDEN);
    pRenderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_SOFTWARE);
    SDL_SetWindowTitle(window, "Window");
}

void Window::run()
{
    init();
    SDL_ShowWindow(window);
    running = true;
};

void Window::dispose()
{
    running = false;
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::addWidget(Widget *widget)
{
    widgets.push_back(widget);
    std::cout << "Widget added, now have :" << widgets.size() << std::endl;
}

Widget *Window::getWidgetAt(int index)
{
    return widgets.at(index);
}

void Window::draw()
{
    for (Widget *w : widgets)
    {
        w->draw(pRenderer);
    }
}