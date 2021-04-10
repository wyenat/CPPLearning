#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Window
{
private:
    int HEIGHT;
    int WIDTH;
    SDL_Window *window;
    SDL_Renderer *pRenderer;

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
};