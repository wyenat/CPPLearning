#include <iostream>
#include "gui/window.h"
#include "control/keyBinding.h"
#include "gui/textWidget.h"
#include "control/widgetManager.h"
#include "gui/widget.h"
#include "simulation/world.h"
#include <chrono>

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

    // Init world
    World world(&window);
    world.makeGravitySensible(1);

    KeyBinding keybind(&window);

    std::cout << "Done initializing !\n";
    window.run();

    /**
     * Entering game loop
     */
    clock_t start = std::clock();
    while (window.isRun())
    {
        keybind.processKeys();
        if ((std::clock() - start) / (CLOCKS_PER_SEC / 1000) > 50)
        {
            start = std::clock();
            world.fall();
        }
    }

    return 0;
}