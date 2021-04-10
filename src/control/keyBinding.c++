#include "control/keyBinding.h"

KeyBinding::KeyBinding(SDL_Window *w)
{
    window = w;
}

KeyBinding::KeyBinding()
{
}

void KeyBinding::setWindow(SDL_Window *w)
{
    window = w;
}

void KeyBinding::hardmap(const char *keycode)
{
    // TODO Very inefficient way to do it, improve
    if (!strcmp(keycode, "A"))
    {
        callbackA();
        return;
    }
    if (!strcmp(keycode, "Up"))
    {
        callbackUp();
        return;
    }
    if (!strcmp(keycode, "Right"))
    {
        callbackRight();
        return;
    }
    if (!strcmp(keycode, "Down"))
    {
        callbackDown();
        return;
    }
    if (!strcmp(keycode, "Left"))
    {
        callbackLeft();
        return;
    }
    std::cout << "Key " << keycode << " pressed but not binded\n";
}

void KeyBinding::callbackUp()
{
    std::cout << "UP pressed!" << std::endl;
}
void KeyBinding::callbackRight()
{
    std::cout << "Right pressed!" << std::endl;
}
void KeyBinding::callbackDown()
{
    std::cout << "Down pressed!" << std::endl;
}
void KeyBinding::callbackLeft()
{
    std::cout << "Left pressed!" << std::endl;
}

void KeyBinding::callbackA()
{
    std::cout << "A pressed!" << std::endl;
    // window.draw();
}

void KeyBinding::keyPressed(SDL_Keycode key)
{
    const char *keycode = SDL_GetKeyName(key);
    hardmap(keycode);
}