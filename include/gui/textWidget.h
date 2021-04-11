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
    void setFontPath(char *path);
    void setFontSize(int size);

    void setText(char *text, SDL_Color color);
    void setText(char *text);
    void setText(SDL_Color color);

    void free();
    void draw(SDL_Renderer *pRenderer);

protected:
    // Angle of the widget
    double angle = 0;
    // Font of the text
    TTF_Font *font;
    char *pathFont;
    int sizeFont;
    // Text
    SDL_Surface *text;
    char *printedText;
    SDL_Color colorText;
    SDL_Texture *texture;
};