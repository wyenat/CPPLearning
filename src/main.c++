#include <iostream>
#include "gui/window.h"
#include "control/keyBinding.h"
#include "gui/textWidget.h"
#include "gui/widget.h"

int main()
{
    Window window;
    KeyBinding keybind(&window);

    // Init text widget
    int height = std::get<0>(window.getDimensions()) / 2;
    int width = std::get<1>(window.getDimensions()) / 2;
    TextWidget textW;
    textW.setPosition(height, width);
    window.addWidget(&textW);

    std::cout << "Done initializing !\n";
    window.run();

    keybind.keyboardUntilQuit();

    return 0;
}