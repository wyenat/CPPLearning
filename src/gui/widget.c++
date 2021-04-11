#include "gui/widget.h"

Widget::Widget()
{
    setSize(0, 0);
    name = "Widget";
}

void Widget::setSize(int size_h, int size_w)
{
    size.h = size_h;
    size.w = size_w;
}

void Widget::setPosition(int x, int y)
{
    size.x = x;
    size.y = y;
}

void Widget::draw(SDL_Renderer *pRenderer)
{
    std::cout << "Drawing widget " << getName() << " at: (" << center.x << ", " << center.y
              << ") with size: (" << size.h << ", " << size.w << ")\n";
}

void Widget::move(int x, int y)
{
    size.x += x;
    size.y += y;
}