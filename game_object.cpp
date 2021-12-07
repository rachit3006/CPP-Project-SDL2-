#include"game_object.h"
#include"TextureManager.h"

game_object::game_object(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	object_Tex = TextureManager::LoadTexture(texturesheet, renderer);
	xpos = x;
	ypos = y;
}

void game_object::Update()
{
	//Movement based on events happening ... change them here
	//Rect positions and sizes can be changed here
}

void game_object::Render()
{
	SDL_RenderCopy(renderer, object_Tex, &src_rec, &des_rec);
}

game_object::~game_object()
{

}