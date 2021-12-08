#include<vector>
#include"game.h"
#include "Player.h"
#include "BackGround.h"
#include"TextureManager.h"
#include"game_object.h"
#include "Bullet.h"

Player* player;
vector<Bullet *> bullets;
BackGround* background;

int window_height = 600, window_width = 1500;

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
	player = new Player("assets/player.png", renderer, 0, 0, window_height, window_width, 85, 77, 65);
	background = new BackGround("assets/back.png", renderer, 0, 0, window_height, window_width);
}

void game::HandleEvents() //Handle Various events happening
{
	SDL_Event event;
	SDL_PollEvent(&event);
	const  Uint8* keystates = SDL_GetKeyboardState(NULL);
	
	if (event.type == SDL_QUIT)
	{
		is_running = false;
	}
	
	if (event.type == SDL_KEYUP){
		if (event.key.keysym.sym == SDLK_RETURN){
			if(player->get_ammo() > 0){
				bullets.push_back(new Bullet("assets/bullet.png", renderer, player->getx(), player->gety(), window_height, window_width, 595, 420));
				player->set_ammo(player->get_ammo()-1);
			}
		}
	}
    
	if (keystates[SDL_SCANCODE_SPACE])
	{
		//Event for jump.
		player->set_space_pressed(true);
	}
	else{
		player->set_space_pressed(false);
	}
}

void game::update() //Game Logic is Handled Here
{
	//Update your game objects here
	player->update();
	for(int i=0;i<bullets.size();i++){
		bullets[i]->update();
		if(bullets[i]->getx() > window_width + bullets[i]->getwidth()){
			bullets.erase(bullets.begin() + i);
		}
	} 
}

void game::render()
{
	SDL_RenderClear(renderer);
	//Render Your game objects here from there respective functions
	background->Render();
	player->Render();
	for(Bullet* bullet : bullets) bullet->Render();
	SDL_RenderPresent(renderer);
}

void game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleaned" <<  endl;
}