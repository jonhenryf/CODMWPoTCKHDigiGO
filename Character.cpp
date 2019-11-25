//
// Created by mrjof on 11/24/2019.
//

#include "Character.h"


void Character::set_player_name()
{
    cin  >> player_name;
}

string Character::get_player_name()
{
    return player_name;
}

void Character::set_initial_stats()
{
    stats.push_back(30);
    stats.push_back(30);
    stats.push_back(50);
}

int Character::get_max_health()
{
    for(int i = 0; i < stats.size(); i++)
    {
        if (i == 0)
        {
            max_health = stats[i];
        }
    }

    return max_health;
}

int Character::get_current_health()
{
    for(int i = 0; i < stats.size(); i++)
    {
        if (i == 1)
        {
            current_health = stats[i];
        }
    }

    return current_health;
}

int Character::get_gains()
{
    for(int i = 0; i < stats.size(); i++)
    {
        if (i == 2)
        {
            gains = stats[i];
        }
    }

    return gains;
}

void Character::add_max_health(int added_health)
{
    for(int i = 0; i < stats.size(); i++)
    {
        if (i == 0)
        {
            stats[i] = stats[i] + added_health;
        }
    }
}

void Character::add_current_health(int added_health)
{
    for(int i = 0; i < stats.size(); i++)
    {
        if (i == 1)
        {
            stats[i] = stats[i] + added_health;
        }
    }
}

void Character::subtract_current_health(int subtracted_health)
{
    for(int i = 0; i < stats.size(); i++)
    {
        if (i == 1)
        {
            stats[i] = stats[i] - subtracted_health;
        }
    }
}

void Character::add_gains(int added_gains)
{
    for(int i = 0; i < stats.size(); i++)
    {
        if (i == 2)
        {
            stats[i] = stats[i] + added_gains;
        }
    }
}

