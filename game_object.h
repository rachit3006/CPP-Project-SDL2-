#ifndef PLAYER_H
#define PLAYER_H
#include "game.h"
#include"TextureManager.h"
class game_object
{
protected:
	int xpos;
	int ypos;
	SDL_Texture* object_Tex;
	SDL_Renderer* renderer;
	SDL_Rect src_rec, des_rec;

public:
	game_object(const char* texturesheet, SDL_Renderer * ren, int x, int y);
	~game_object(){
		SDL_DestroyTexture(object_Tex);
		SDL_DestroyRenderer(renderer);
		object_Tex = NULL;
		renderer = NULL;
	};
	void Update();
	void Render();
};

#endif 

