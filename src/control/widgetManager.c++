#include "control/widgetManager.h"

WidgetManager::WidgetManager(Window *w)
{
    TextWidget();
    window = w;
    name = "Widget Manager";
    current = 1;
    setFontSize(20);
    char *defaultText("WM:");
    setText(defaultText);
    setTopRightCorner();
}

void WidgetManager::setTopRightCorner()
{
    texture = SDL_CreateTextureFromSurface(window->getRenderer(), text);
    SDL_QueryTexture(texture, nullptr, nullptr, &size.w, &size.h);
    int right_side = window->getWidth() - size.w;
    std::cout << "Right side at: " << right_side << ".\n";
    setPosition(right_side, 0);
}

void WidgetManager::cycle()
{
    current = (current + 1) % window->getNbWidgets();
    std::string toPrint = std::string("VM:") + std::string(window->getWidgetAt(current)->getName());
    char *toPrintChar = &toPrint[0];
    setText(toPrintChar);
    setTopRightCorner();
    window->draw();
}

void WidgetManager::move(int x, int y)
{
    Widget *w = window->getWidgetAt(current);
    w->move(x, y);
    window->draw();
}