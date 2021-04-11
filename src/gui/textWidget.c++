#include "gui/textWidget.h"

TextWidget::TextWidget()
{
    angle = 0;
    char *defaultFont = "src/ressources/fonts/chopin_script.ttf";
    setFont(defaultFont, 55);
    setText("Default text", SDL_Color{255, 255, 255, 255});
    setPosition(0, 0);
    name = "TextWidget";
}

void TextWidget::setAngle(double angle)
{
    angle = angle;
}

char *TextWidget::getName()
{
    name = "TW modified";
    return name;
}

void TextWidget::setFont(char *path, int size)
{
    std::ifstream pathToTTF(path);
    if (!pathToTTF.is_open())
    {
        std::cerr << "Something went wrong when trying to open: " << path << ". Not changing font.\n";
        return;
    }
    font = TTF_OpenFont(path, size);
}
void TextWidget::setText(char *setText, SDL_Color color)
{
    text = TTF_RenderText_Blended(font, setText, color);
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
    SDL_RendererFlip flip = static_cast<SDL_RendererFlip>(SDL_FLIP_NONE);
    SDL_RenderCopyEx(pRenderer, texture, nullptr, &size, angle, &center, flip);
    SDL_RenderPresent(pRenderer);
}