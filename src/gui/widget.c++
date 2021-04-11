#include "gui/widget.h"

Widget::Widget()
{
    setSize(0, 0);
    name = "Widget";
}

void Widget::setSize(int size_x, int size_y)
{
    size.x = size_x;
    size.y = size_y;
}

void Widget::setPosition(int x, int y)
{
    center.x = x;
    center.y = y;
}

void Widget::draw(SDL_Renderer *pRenderer)
{
    std::cout << "Drawing widget " << getName() << " at: (" << center.x << ", " << center.y
              << ") with size: (" << size.h << ", " << size.w << ")\n";
}