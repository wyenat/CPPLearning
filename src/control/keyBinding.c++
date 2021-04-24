#include "control/keyBinding.h"

KeyBinding::KeyBinding(Window *w)
{
    window = w;
    linkWM();
}

KeyBinding::KeyBinding()
{
}

void KeyBinding::linkWM()
{
    Widget *w = window->getWidgetAt(0);
    if (strcmp(w->getName(), "Widget Manager"))
    {
        std::cerr << "Expected Widget Manager at index 0! Got " << w->getName() << " instead.\n";
        return;
    }
    wm = reinterpret_cast<WidgetManager *>(window->getWidgetAt(0));
}

void KeyBinding::setWindow(Window *w)
{
    window = w;
    linkWM();
}

void KeyBinding::hardmap(const char *keycode)
{
    // TODO Very inefficient way to do it, improve
    if (!strcmp(keycode, "A"))
    {
        callbackA();
    }
    else if (!strcmp(keycode, "C"))
    {
        callbackC();
    }
    else if (!strcmp(keycode, "D"))
    {
        callbackDebug();
    }
    else if (!strcmp(keycode, "Up"))
    {
        callbackUp();
    }
    else if (!strcmp(keycode, "Right"))
    {
        callbackRight();
    }
    else if (!strcmp(keycode, "Down"))
    {
        callbackDown();
    }
    else if (!strcmp(keycode, "Left"))
    {
        callbackLeft();
    }
    else if (!strcmp(keycode, "Escape"))
    {
        callbackEscape();
    }
    else
    {
        std ::cout << "Key " << keycode << " pressed but not binded\n";
    }
}

void KeyBinding::callbackEscape()
{
    std::cout << "Escape pressed : Bye bye !\n";
    window->dispose();
}

void KeyBinding::callbackUp()
{
    wm->move(0, -10);
}

void KeyBinding::callbackDebug()
{
    wm->setDebug(!wm->getDebug());
}

void KeyBinding::callbackRight()
{
    wm->move(10, 0);
}
void KeyBinding::callbackDown()
{
    wm->move(0, 10);
}
void KeyBinding::callbackLeft()
{
    wm->move(-10, 0);
}

void KeyBinding::callbackA()
{
    wm->rotateWidget(5);
}
void KeyBinding::callbackC()
{
    wm->cycle();
}

void KeyBinding::keyPressed(SDL_Keycode key)
{
    const char *keycode = SDL_GetKeyName(key);
    hardmap(keycode);
}

void KeyBinding::processKeys()
{
    SDL_Event kevent;
    while (SDL_PollEvent(&kevent))
    {
        switch (kevent.type)
        {
        case SDL_KEYDOWN:
            keyPressed(kevent.key.keysym.sym);
            break;
        case SDL_QUIT:
            std::cout << "\nBye!\n";
            window->dispose();
            break;
        default:
            break;
        }
    }
};