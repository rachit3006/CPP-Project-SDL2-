#include "Homescreen.h"

void Window::makeWindow(const char* title, int width, int height)
{
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        cout<<"error: Failed to initialize "<< SDL_GetError()<<endl;    
    }
    window = SDL_CreateWindow("Ammomatics v1.0",0 , 0 ,width,height,0);
    if(window==NULL)
            cout<<"Couldn't create window.   error"<< SDL_GetError() << endl;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer==NULL)
		{
			cout <<"Couldn't create renderer. error"<< SDL_GetError() << endl;
		}

    surface=SDL_GetWindowSurface(window);
    bg_image=SDL_LoadBMP("/home/born2win685/Desktop/cpp_project/images/bg.bmp");
    SDL_BlitSurface(bg_image, NULL,surface,NULL);
    SDL_UpdateWindowSurface(window);

    SDL_Event event;
    bool quit=true;
    while(quit)
    {
        while(SDL_PollEvent(&event)!=0)
        {

        if(event.type == SDL_QUIT)
            quit=false;
        }
    }
}

Window::~Window()
{

}

Window::Window()
{
    
}
