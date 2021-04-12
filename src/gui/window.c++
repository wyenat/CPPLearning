#include "gui/window.h"

Window::Window()
{
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
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
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
    draw();
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
    if (widgets.empty())
    {
        std::cerr << "Trying to reach widgets but vector is empty...Return nullptr\n";
        return nullptr;
    }
    if (index > getNbWidgets())
    {
        std::cerr << "Trying to reach widget " << index << ", but only " << widgets.size()
                  << "available! Returning first widget instead...\n";
        return widgets.at(0);
    }
    return widgets.at(index);
}

void Window::draw()
{
    SDL_RenderClear(pRenderer);
    for (Widget *w : widgets)
    {
        w->draw(pRenderer);
    }
    SDL_RenderPresent(pRenderer);
}