#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include "gui/widget.h"
#include "gui/textWidget.h"
#include <algorithm>

class Window
{
private:
    int HEIGHT = 640;
    int WIDTH = 860;
    SDL_Window *window;
    SDL_Renderer *pRenderer;
    std::vector<Widget *> widgets;
    bool running;

    /**
     *  Initialise window and SDL
     */
    void init();

public:
    Window();

    /**
     * Destroy the Window and close SDL
     */
    void dispose();

    /**
     * Open the windows
     */
    void run();

    /**
     * Draws what is is stored in the renderer
     */
    void draw();

    /**
     * Return the widget stored at index
     */
    Widget *getWidgetAt(int index);
    void addWidget(Widget *widget);
    int getNbWidgets() { return widgets.size(); };

    SDL_Renderer *getRenderer() { return pRenderer; };

    /**
     * Return Height, Width of the window
     */
    int getWidth() { return WIDTH; };
    int getHeight() { return HEIGHT; };

    bool isRun() { return running; };
};