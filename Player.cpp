#include "Player.h"
#include <cstdlib>

using namespace std;

int Player::getx()
{
    return des_rec.x;
}

int Player::gety()
{
    return des_rec.y;
}

int Player::get_ammo()
{
    return ammo;
}

void Player::set_ammo(int ammo)
{
    // setting ammo
    if (ammo >= 0)
        this->ammo = ammo;
    else
        this->ammo = 0;
}

void Player::set_space_pressed(bool is_pressed)
{
    this->space_pressed = is_pressed;
}

SDL_Rect Player::getPlayerRect()
{
    return des_rec;
}

void Player::update()
{
    // when spacebar is not pressed and the player is in air
    if (des_rec.y <= window_height - src_rec.h - platform_height && !space_pressed)
    {
        // implementing gravity 
        final_velocity = initial_velocity + gravity;
        // keeping the player above the platform
        if (des_rec.y < platform_height)
            des_rec.y = platform_height;
        if (des_rec.y + (((final_velocity * final_velocity) - (initial_velocity * initial_velocity)) / (2 * gravity)) > window_height - src_rec.h - platform_height)
        {
            des_rec.y = window_height - src_rec.h - platform_height;
            final_velocity = initial_velocity = 0;
        }
        else
        {
            des_rec.y += (((final_velocity * final_velocity) - (initial_velocity * initial_velocity)) / (2 * gravity));
        }
        initial_velocity = final_velocity;
    }
    // when spacebar is pressed and the player is not at top of the screen
    if (des_rec.y >= platform_height && space_pressed)
    {
        // implementing the acceleration of the player in upwards direction
        final_velocity = initial_velocity - acceleration;
        // keeping the player below the ceiling
        if (des_rec.y > window_height - src_rec.h - platform_height)
            des_rec.y = window_height - src_rec.h - platform_height;
        if (des_rec.y + (((final_velocity * final_velocity) - (initial_velocity * initial_velocity)) / (-2 * acceleration)) < platform_height)
        {
            des_rec.y = platform_height;
            final_velocity = initial_velocity = 0;
        }
        else
        {
            des_rec.y += (((final_velocity * final_velocity) - (initial_velocity * initial_velocity)) / (-2 * acceleration));
        }
        initial_velocity = final_velocity;
    }
}