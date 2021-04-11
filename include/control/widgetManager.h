#pragma once
#include "gui/window.h"
#include <iostream>

/**
 * A widget that enable to cycle through widgets and perform
 * actions on them.
 */
class WidgetManager : public TextWidget
{
private:
    int current;
    Window *window;
    void setTopRightCorner();

public:
    WidgetManager(Window *window);
    void cycle();
    void move(int x, int y);
};