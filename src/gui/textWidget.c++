#include "gui/textWidget.h"

TextWidget::TextWidget()
{
    Widget();
    angle = 0;
    pathFont = "src/ressources/fonts/Roboto-Regular.ttf";
    int sizeFont = 55;
    setFont(pathFont, sizeFont);
    printedText = "Default text";
    colorText = SDL_Color{255, 255, 255, 255};
    setText(printedText, colorText);
    setPosition(0, 0);
    name = "TextWidget";
}

void TextWidget::setAngle(double angle)
{
    angle = angle;
}

void TextWidget::setFont(char *path, int size)
{
    std::ifstream pathToTTF(path);
    if (!pathToTTF.is_open())
    {
        std::cerr << "Something went wrong when trying to open: " << path << ". Not changing font.\n";
        return;
    }
    pathToTTF.close();
    font = TTF_OpenFont(path, size);
}

void TextWidget::setFontPath(char *path)
{
    pathFont = path;
    setFont(pathFont, sizeFont);
}

void TextWidget::setFontSize(int size)
{
    sizeFont = size;
    setFont(pathFont, sizeFont);
}

void TextWidget::setText(char *t, SDL_Color color)
{
    text = TTF_RenderText_Blended(font, t, color);
}

void TextWidget::setText(char *t)
{
    printedText = t;
    setText(printedText, colorText);
}

void TextWidget::setText(SDL_Color color)
{
    colorText = color;
    setText(printedText, colorText);
}

void TextWidget::free()
{
    SDL_FreeSurface(text);
    TTF_CloseFont(font);
}

void TextWidget::draw(SDL_Renderer *pRenderer)
{
    Widget::draw(pRenderer);
    texture = SDL_CreateTextureFromSurface(pRenderer, text);
    SDL_QueryTexture(texture, nullptr, nullptr, &size.w, &size.h);
    SDL_RenderCopy(pRenderer, texture, nullptr, &size);
}