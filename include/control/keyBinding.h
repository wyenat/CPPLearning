#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "gui/window.h"

/**
 * This class serves binding of the keys to functions.
 * Here's the things left to do :
 * - MAP from setting file : a map file serves the input of a map object,
 *   allowing easy change (like "JUMP=A" calls callbackJump when A is pressed)
 * - Listener
 */
class KeyBinding
{
private:
    /**
     * This function shall disappear someday, it is a hardmapping.
     */
    void hardmap(const char *keycode);

    /**
     * Specific callback. To replace with function based callbacks, like "callbackJump"
     * rather than key-based callbacks.
     */
    void callbackA();

    // Directionnal callbacks
    void callbackUp();
    void callbackRight();
    void callbackDown();
    void callbackLeft();

    // Window
    Window *window;

    void keyPressed(SDL_Keycode key);

public:
    KeyBinding();
    KeyBinding(Window *window);
    void setWindow(Window *window);

    /**
     *  Listen to new events until a CTRL + C is detected
     */
    void keyboardUntilQuit();
};