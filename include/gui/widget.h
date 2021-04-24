#pragma once
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cmath>
#include <tuple>
/**
 *  General widget class
 */
class Widget
{
public:
    Widget();
    void setPosition(int x, int y);
    void move(int x, int y);
    void rotate(double angle);
    void setSize(int size_x, int size_y);
    void setAngle(double alpha);
    void setDebug(bool d) { debug = d; };
    bool getDebug() { return debug; };
    int getWidth() { return size.w; };
    int getHeight() { return size.h; };
    int getXPosition() { return size.x; };
    int getYPosition() { return size.y; };
    double getAngle() { return angle; };
    void free(){};
    void setRedraw(bool r) { redraw = r; };
    std::tuple<int, int, double> getSpeed() { return speed; };

    /**
     *  Set speed in X axis, Y axis and rotation speed
     */
    void setSpeed(int speedX, int speedY, double speedW);
    /**
     * Draws the widget using passed renderer
     */
    virtual void
    draw(SDL_Renderer *pRenderer);

    /**
     * Returns the name of this widget
     */
    virtual char *getName() { return name; };
    void reComputeCenter();

protected:
    // Size of the widget
    SDL_Rect size;
    // Position of the widget
    SDL_Point center;
    // Name to print
    char *name;
    // Angle of the texture
    double angle;
    // Debug point
    bool debug;
    // Speed
    std::tuple<int, int, double> speed;
    // Redraw
    bool redraw;
};