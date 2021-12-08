#include "game_object.h"

class BackGround : public game_object{
    public:
        BackGround(const char* texturesheet, SDL_Renderer * ren, int x, int y):game_object(texturesheet, ren, x, y){
            src_rec.h = 400;
            src_rec.w = 1500;
            src_rec.x = 0;
            src_rec.y = 0;
            des_rec.h = 400;
            des_rec.w = 1500;
            des_rec.x = 0;
            des_rec.y = 0;
        } 
};