#include <iostream>
#include "gui/window.h"
#include "control/keyBinding.h"
#include "gui/textWidget.h"
#include "control/widgetManager.h"
#include "gui/widget.h"

int main()
{
    Window window;

    // Init widget manager
    WidgetManager manager(&window);
    window.addWidget(&manager);
    // Init text widget
    int height = window.getHeight() / 2;
    int width = window.getWidth() / 2;
    TextWidget textW;
    textW.setPosition(width, height);
    window.addWidget(&textW);

    KeyBinding keybind(&window);

    std::cout
        << "Done initializing !\n";
    window.run();

    keybind.keyboardUntilQuit();

    return 0;
}