#pragma once
#include "gui/window.h"
#include <vector>
#include <tuple>
class World
{
private:
    Window *window;
    std::vector<int> gravitySensibleWidgets;
    int worldSpeedX = 0;
    int worldSpeedY = 1;

    /**
     * Gravity related functions
     */
    void incrementSpeed(Widget *w);
    void moveWidget(Widget *w);
    void checkCollisions(Widget *w);

public:
    World();
    World(Window *w);
    void addWindow(Window *w) { window = w; };

    /**
     * Gravity related functions
     */
    void makeGravitySensible(int indexWidget) { gravitySensibleWidgets.push_back(indexWidget); };
    void fall();
};