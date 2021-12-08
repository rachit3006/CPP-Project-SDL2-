#include"Player.h"
#include <cstdlib>

using namespace std;

int Player::get_ammo(){
    return ammo;
}

void Player::set_ammo(int ammo){
    this->ammo = ammo;
}

void Player::update(){
    if(des_rec.y < window_height-src_rec.h && !space_pressed){
        final_velocity = initial_velocity - gravity;
        des_rec.y += abs(((final_velocity*final_velocity) - (initial_velocity*initial_velocity))/(2*gravity));
        initial_velocity = final_velocity;
    }
    if(des_rec.y > 0 && space_pressed){
        final_velocity = initial_velocity + acceleration;
        des_rec.y -= ((final_velocity*final_velocity) - (initial_velocity*initial_velocity))/(2*acceleration);
        initial_velocity = final_velocity;
    }
}