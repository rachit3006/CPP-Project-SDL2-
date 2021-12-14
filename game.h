#ifndef GAME_HPP
#define GAME_HPP
#include<SDL.h>
#include<SDL_ttf.h>
#include<string>
#include<iostream>
using namespace std;

class game
{
private:
	bool is_running;
	SDL_Window* window;
	SDL_Texture* backgrnd;
	SDL_Texture* CurrScore_tex;
	SDL_Texture* Show_Ammo;
	SDL_Rect Ammo_rect;
	SDL_Rect Score_rect;
	SDL_Rect Display_rect;
	SDL_Rect Display_rect2;
	SDL_Rect Back_rect;
	SDL_Rect Back_rect2;
	double Curr_Score;
	long long int x_back;

public:
	game();
	~game();
	static SDL_Renderer* renderer ;
	static SDL_Event* event;
	void init(const char* title, int xpos, int ypos, int width, int height, bool full_ornot);
	void HandleEvents();
	void update();
	void render();
	void clean();
	void Update_Score_TexandAmmo();
	void Update_Background();
	bool Is_Running() { return(is_running); };
};
#endif 

