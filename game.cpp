#include"game.h"
#include "Player.h"
#include"TextureManager.h"
#include"game_object.h"
#include<vector>
#include "Bullet.h"


SDL_Renderer* game :: renderer = NULL;
vector<Bullet*> bullets;
Player* player;
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
	TTF_Init();

	//Create Game_objects
	CurrScore_tex = NULL;
	Curr_Score = 0;
	
	backgrnd = TextureManager::LoadTexture("assets/back.png");
	player = new Player("assets/player.png", renderer, 0, 0, window_height, window_width, 85, 77, 65);

	Update_Score_TexandAmmo();
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

	if (event.type == SDL_KEYUP) {
		if (event.key.keysym.sym == SDLK_RETURN) {
			if (player->get_ammo() > 0) {
				bullets.push_back(new Bullet("assets/bullet.png", renderer, player->getx(), player->gety(), window_height, window_width, 595, 420));
				player->set_ammo(player->get_ammo() - 1);
			}
		}
	}

	if (keystates[SDL_SCANCODE_SPACE])
	{
		//Event for jump.
		player->set_space_pressed(true);
	}
	else {
		player->set_space_pressed(false);
	}
}

void game::update() //Game Logic is Handled Here
{
	//Update your game objects here

	player->update();
	for (int i = 0;i < bullets.size();i++) {
		bullets[i]->update();
		if (bullets[i]->getx() > window_width + bullets[i]->getwidth()) {
			bullets.erase(bullets.begin() + i);
		}
	}

	Curr_Score = Curr_Score + (0.167);
	Update_Score_TexandAmmo();
}

void game::render()
{
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.h = 600;
	rect.w = 1500;

	SDL_Rect Score_rect;
	Score_rect.x = 1300;
	Score_rect.y = 0;
	Score_rect.w = 200;
	Score_rect.h = 80;

	SDL_Rect Ammo_rect;
	Ammo_rect.x = 0;
	Ammo_rect.y = 530;
	Ammo_rect.w = 200;
	Ammo_rect.h = 70;

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgrnd, &rect, &rect);
	SDL_RenderCopy(renderer, CurrScore_tex, NULL, &Score_rect);
	SDL_RenderCopy(renderer, Show_Ammo, NULL, &Ammo_rect);
	player->Render();
	for (Bullet* bullet : bullets) bullet->Render();
	SDL_RenderPresent(renderer);
}

void game:: Update_Score_TexandAmmo() 
{
	TTF_Font* Font = TTF_OpenFont("assets/Font.ttf", 24);
	if (Font == NULL)
	{
		cout << "Font is NULL" << endl;
	}
	SDL_Color White = { 255, 255, 0 };
	string s;
	s = to_string((long int) Curr_Score);
	s = "Score : " + s;
	SDL_Surface* surface = TTF_RenderText_Solid(Font, s.c_str(), White);
	CurrScore_tex = SDL_CreateTextureFromSurface(renderer, surface);

	s = to_string((long int)player->get_ammo());
	s = "Ammo : " + s;
	surface = TTF_RenderText_Solid(Font, s.c_str(), White);
	Show_Ammo = SDL_CreateTextureFromSurface(renderer, surface);

	if (CurrScore_tex == NULL)
	{
		cout << "Score Texture is NULL" << endl;
	}
	if (Show_Ammo == NULL)
	{
		cout << "Ammo Texture is NULL" << endl;
	}

	SDL_FreeSurface(surface);
	TTF_CloseFont(Font);
}

void game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	TTF_Quit();
	cout << "Game Cleaned" <<  endl;
}