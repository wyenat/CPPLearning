#include "simulation/world.h"

World::World()
{
}

World::World(Window *w)
{
    window = w;
}

/**
 * For now, speed increment linearly toward the bottom of the screen
 */
void World::incrementSpeed(Widget *w)
{
    std::tuple<int, int, double> tup = w->getSpeed();
    w->setSpeed(std::get<0>(tup) + worldSpeedX, std::get<1>(tup) + worldSpeedY, std::get<2>(tup));
}

void World::moveWidget(Widget *w)
{
    std::tuple<int, int, double> speed = w->getSpeed();
    w->setPosition(w->getXPosition() + std::get<0>(speed), w->getYPosition() + std::get<1>(speed));
}

void World::checkCollisions(Widget *w)
{
    std::tuple<int, int, double> tup = w->getSpeed();
    bool posX = w->getXPosition() + w->getWidth() > window->getWidth();
    bool posY = w->getYPosition() + w->getHeight() > window->getHeight();
    if (posX)
    {
        w->setPosition(window->getWidth() - w->getWidth(), w->getYPosition());
        w->setSpeed(0, std::get<1>(tup), std::get<2>(tup));
    }
    if (posY)
    {
        w->setPosition(w->getXPosition(), window->getHeight() - w->getHeight());
        w->setSpeed(std::get<0>(tup), 0, std::get<2>(tup));
    }
}

void World::fall()
{
    // increment speed
    for (int index : gravitySensibleWidgets)
    {
        Widget *w = window->getWidgetAt(index);
        incrementSpeed(w);
        moveWidget(w);
        checkCollisions(w);
    }
    window->draw();
}