#include"game.h"
#include "Player.h"
#include "BackGround.h"
#include"TextureManager.h"
#include"game_object.h"

Player* player;
BackGround* background;

game::game()
{

}

game :: ~game()
{

}

void game::init(const char* title, int xpos, int ypos, int width, int height, bool full_ornot)
{
	int flag = 0;
	if (full_ornot)
	{
		flag = SDL_WINDOW_FULLSCREEN;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
		if (window)
		{
			cout << "Window Created" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Renderer Created" << endl;
		}

		is_running = true;
	}
	else
	{
		is_running = false;
	}

	//Create Game_objects
	player = new Player("assets/player.png", renderer, 0, 0, 400, 800, 85, 77);
	background = new BackGround("assets/back.png", renderer, 0, 0);
}

void game::HandleEvents() //Handle Various events happening
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case(SDL_QUIT):
	{
		is_running = false;
		break;
	}
	}
}

void game::update() //Game Logic is Handled Here
{
	//Update your game objects here
	player->update();
}

void game::render()
{
	SDL_RenderClear(renderer);
	//Render Your game objects here from there respective functions
	background->Render();
	player->Render();
	SDL_RenderPresent(renderer);
}

void game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleaned" <<  endl;
}