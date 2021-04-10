#include <iostream>
#include "gui/window.h"
#include "control/keyBinding.h"

int main()
{
    Window window;
    KeyBinding keybind(&window);
    std::cout << "Done initializing !\n";
    window.run();
    keybind.keyboardUntilQuit();

    return 0;
}