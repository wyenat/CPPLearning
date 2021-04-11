#pragma once
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

/**
 *  General widget class
 */
class Widget
{
public:
    Widget();
    void setPosition(int x, int y);
    void move(int x, int y);
    void setSize(int size_x, int size_y);
    void free(){};
    /**
     * Draws the widget using passed renderer
     */
    virtual void draw(SDL_Renderer *pRenderer);

    /**
     * Returns the name of this widget
     */
    virtual char *getName() { return name; };

protected:
    // Size of the widget
    SDL_Rect size;
    // Position of the widget
    SDL_Point center;
    // Name to print
    char *name;
};