#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "control/keyBinding.h"

class Window
{
private:
    int HEIGHT;
    int WIDTH;
    SDL_Window *window;
    SDL_Renderer *pRenderer;
    KeyBinding kb;

    void init();
    void keyboardUntilQuit();

public:
    Window();
    void run();
    void draw();
};