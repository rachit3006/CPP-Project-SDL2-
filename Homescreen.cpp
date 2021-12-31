#include "Homescreen.h"

void Window::makeWindow(const char *title, int width, int height)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "error: Failed to initialize " << SDL_GetError() << endl;
    }
    window = SDL_CreateWindow("Ammomatics v1.0", 0, 0, width, height, 0);

    if (window == NULL)
        cout << "Couldn't create window.   error" << SDL_GetError() << endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL)
    {
        cout << "Couldn't create renderer. error" << SDL_GetError() << endl;
    }

    surface = SDL_GetWindowSurface(window);
    SDL_Rect dest;
    dest.x = 0;
    dest.y = 100;
    bg_image = SDL_LoadBMP("images/back.bmp");
    SDL_BlitSurface(bg_image, NULL, surface, &dest);
    SDL_UpdateWindowSurface(window);
}

Window::~Window()
{
}

Window::Window()
{
}

void Window::set_button(const char *path, int p_x, int p_y)
{
    surface = SDL_GetWindowSurface(Window::window);
    button = SDL_LoadBMP(path);
    SDL_Rect dest;
    dest.x = p_x;
    dest.y = p_y;
    int result = SDL_BlitSurface(button, NULL, surface, &dest);
    if (result < 0)
        cout << "blit failed" << endl;
    SDL_UpdateWindowSurface(window);
}

void Buttons::mouse_click(int p_x, int p_y, int b_w, int b_h, int flag)
{
    SDL_Event mouse_event;
    bool quit = true;
    while (quit)
    {
        while (SDL_PollEvent(&mouse_event))
        {
            switch (mouse_event.type)
            {
            case SDL_QUIT:
                quit = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                mx = mouse_event.motion.x;
                my = mouse_event.motion.y;
                if (mx > p_x && mx < (p_x + b_w) && my < (p_y + b_h) && my > p_y && mouse_event.type == SDL_MOUSEBUTTONDOWN)
                    cout << "clicked" << endl;
                break;
            default:
                break;
            }
        }
    }
}

Buttons::Buttons()
{
}

Buttons::~Buttons()
{
}
