#include "game_object.h"

class Player : public game_object{
    private:
        int ammo;
    public:
        Player(const char* texturesheet, SDL_Renderer * ren, int x, int y):game_object(texturesheet, ren, x, y){
            // initialising the player
            src_rec.h = 85;
            src_rec.w = 77;
            src_rec.x = 0;
            src_rec.y = 0;
            des_rec.h = 85;
            des_rec.w = 75;
            des_rec.x = 0;
            des_rec.y = 400-src_rec.h;
        };

        int get_ammo();
        void set_ammo(int ammo);

        void jump();
        void shoot();       
};