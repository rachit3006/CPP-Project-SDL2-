#pragma once
#ifndef HOMESCREEN_HPP
#define HOMESCREEN_HPP
#include<SDL2/SDL_image.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<iostream>
using namespace std;

class Score
{
    public:
        void add_score(const char* score);
        void display_score(const  char* score);
    private:
        const char* score;
};



class Window 
{
    public:
        Window();
        ~Window();
        void makeWindow(const char* name, int w, int h);
    private:
      SDL_Window* window;
      SDL_Renderer* renderer;
};

#endif