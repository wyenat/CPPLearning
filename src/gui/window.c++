#include "gui/window.h"
#include "control/keyBinding.h"

Window::Window()
{
    WIDTH = 860;
    HEIGHT = 640;
    init();
}

void Window::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "could not initialize sdl2: " << SDL_GetError() << std::endl;
    }
    window = SDL_CreateWindow(
        "main",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WIDTH, HEIGHT,
        SDL_WINDOW_HIDDEN);
    pRenderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_SOFTWARE);
    kb.setWindow(window);
    SDL_SetWindowTitle(window, "Window");
}

void Window::keyboardUntilQuit()
{
    SDL_Event kevent;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&kevent))
        {
            switch (kevent.type)
            {
            case SDL_KEYDOWN:
                kb.keyPressed(kevent.key.keysym.sym);
                break;
            case SDL_QUIT:
                std::cout << "\nBye!\n";
                quit = true;
                SDL_DestroyWindow(window);
                SDL_Quit();
                break;
            default:
                break;
            }
        }
    }
};

void Window::run()
{
    SDL_ShowWindow(window);
    keyboardUntilQuit();
};

void Window::draw()
{
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderPresent(pRenderer);
    TTF_Font *font = TTF_OpenFont("Alef-Regular.ttf", 20);
    SDL_Color COLOR_WHITE = SDL_Color{255, 255, 255, 255};
    SDL_Surface *text = TTF_RenderText_Blended(font, "Hello, World", COLOR_WHITE);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(pRenderer, text);
    SDL_Rect position;

    SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h); // Récupere la dimension de la texture

    // Centre la texture sur l'écran
    position.x = WIDTH / 2 - position.w / 2;
    position.y = HEIGHT / 2 - position.h / 2;

    // Libération des resource de la police et de la surface qui contient le texte
    SDL_FreeSurface(text);
    TTF_CloseFont(font);

    SDL_Point center = {position.w / 2, position.h / 2};
    double angle = 0;
    SDL_RendererFlip flip = static_cast<SDL_RendererFlip>(SDL_FLIP_NONE);
    SDL_RenderPresent(pRenderer);
}