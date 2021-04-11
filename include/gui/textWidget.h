#pragma once
#include "gui/widget.h"
#include <fstream>
#include <iostream>

/**
 * Renders a text on the window
 */
class TextWidget : public Widget
{
public:
    TextWidget();
    void setAngle(double angle);
    void setFont(char *path, int size);
    void setText(char *text, SDL_Color color);
    void free();
    void draw(SDL_Renderer *pRenderer);
    char *getName();

private:
    // Angle of the widget
    double angle = 0;
    // Font of the text
    TTF_Font *font;
    // Text
    SDL_Surface *text;
    SDL_Texture *texture;
};