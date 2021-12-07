#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>
#include<iostream>
using namespace std;

class game
{
private:
	bool is_running;
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	game();
	~game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool full_ornot);
	void HandleEvents();
	void update();
	void render();
	void clean();
	bool Is_Running() { return(is_running); };
};
#endif 

