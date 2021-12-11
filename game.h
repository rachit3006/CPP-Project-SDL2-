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
	double Curr_Score;

public:
	game();
	~game();
	static SDL_Renderer* renderer;
	static SDL_Event* event;
	void init(const char* title, int xpos, int ypos, int width, int height, bool full_ornot);
	void HandleEvents();
	void update();
	void render();
	void clean();
	//void load_bkg();
	void Update_Score_TexandAmmo();
	bool Is_Running() { return(is_running); };
};
#endif 

