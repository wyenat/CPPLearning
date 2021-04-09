#include <SDL2/SDL.h>
#include <iostream>

class Window
{
private:
    bool isInit;
    bool isRun;
    int HEIGHT;
    int WIDTH;

    void init();
    void keyboardUntilQuit(SDL_Window *window);

public:
    Window();
    void run();
};