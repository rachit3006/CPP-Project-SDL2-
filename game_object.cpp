
#include "game_object.h"
#include "TextureManager.h"

game_object::game_object(const char *texturesheet, SDL_Renderer *ren, int x, int y)
{
	renderer = ren;
	object_Tex = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}

void game_object::Render()
{
	SDL_RenderCopy(renderer, object_Tex, &src_rec, &des_rec);
}

game_object::~game_object()
{
	SDL_DestroyTexture(object_Tex);
	SDL_DestroyRenderer(renderer);
	object_Tex = NULL;
	renderer = NULL;
}