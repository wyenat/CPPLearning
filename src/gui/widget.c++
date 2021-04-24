#include "gui/widget.h"

Widget::Widget()
{
    setSize(0, 0);
    setPosition(0, 0);
    angle = 0;
    debug = false;
    redraw = true;
    name = "Widget";
    speed = std::make_tuple(0, 0, 0.0);
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
    reComputeCenter();
}

void Widget::reComputeCenter()
{
    center.x = size.x + size.w / 2;
    center.y = size.y + size.h / 2;
}

void Widget::setAngle(double alpha)
{
    angle = std::fmod(alpha, 360.0);
    redraw = true;
}

void Widget::draw(SDL_Renderer *pRenderer)
{
    if (debug && redraw)
    {
        std::cout << "Drawing widget " << getName() << " at: (" << center.x << ", " << center.y
                  << ") with size: (" << size.h << ", " << size.w << "), angle: " << angle
                  << "and debug:" << debug << "\n";
        int arrowX = center.x + 100 * cos(angle);
        int arrowY = center.y + 100 * sin(angle);
        SDL_RenderDrawLine(pRenderer, center.x, center.y, arrowX, arrowY);
    }
}

void Widget::move(int x, int y)
{
    size.x += x;
    size.y += y;
    reComputeCenter();
    redraw = true;
}

void Widget::rotate(double alpha)
{

    setAngle(angle + alpha);
    std::cout << "Rotating " << getName() << "by " << getAngle() << ", to " << angle << std::endl;
    redraw = true;
}

void Widget::setSpeed(int speedX, int speedY, double speedW)
{
    speed = std::make_tuple(speedX, speedY, speedW);
}