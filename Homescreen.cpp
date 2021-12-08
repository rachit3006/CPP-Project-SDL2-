#include "Homescreen.h"

void Window::makeWindow(const char* title, int width, int height)
:window(NULL),renderer(NULL)
{
    if SDL_Init(!(SDL_INIT_EVERYTHING))
    {
        window = SDL_CreateWindow("title",SDL_WINDOWPOS_CENTERED_DISPLAY , SDL_WINDOWPOS_CENTERED_DISPLAY ,width,height,SDL_WINDOW_SHOWN);
        if(window==NULL)
            cout<<"Couldn't create window.   error"<< SDL_GetError() << endl;
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer==NULL)
		{
			cout <<"Couldn't create renderer. error"<< SDL_GetError() << endl;
		}
    }
    return 0;
}

Window::~Window()
{

}

Window::Window()
{
    
}