//
// Created by mrjof on 11/24/2019.
//

#include "thanos.h"
#include <ctime>
#include <random>



void thanos::set_initial_stats()
{
    max_boss_health = 500;
    boss_health = 500;
    boss_gains = 50;
    alive = true;
    weakness = 0;
}
bool thanos::is_alive()
{
    return alive;
}
void thanos::add_gainz(int gains)
{
    boss_gains = boss_gains + gains;
}
void thanos::add_health(int health)
{
    max_boss_health = max_boss_health + health;
}
void thanos::steal_item(string item)
{
    if (item == "Basic Armor (Bronze) (Medium Plate)")
    {
        thanos::add_health(40);
    }
    else if (item == "Basic Sword (Diamond)")
    {
        thanos::add_gainz(110);
    }
    else if (item == "Basic Sword (Bronze)")
    {
        thanos::add_gainz(40);
    }
    else if (item == "Basic Armor (Platinum) (Large Plate)")
    {
        thanos::add_health(60);
    }
}

int thanos::get_health()
{
    return boss_health;
}

int thanos::get_gainz()
{
    return boss_gains;
}
void thanos::weakness_change()
{
    weakness = (rand() % 3);
    cout << "Thanos shifted his defenses..." << endl;
}
void thanos::take_damage(int damage, int choice)
{
    if (weakness == 1 && choice == 2) {
        cout << "It was not very effective on Thanos..." << endl;

    }
    else if (weakness == 2 && choice == 1) {
        cout << "It was not very effective on Thanos..." << endl;
    }
    else {
        if (boss_health <= damage) {
            boss_health = 0;
            alive = false;
            cout << "You have defeated Thanos and returned peace to Gotham City!" << endl;
        } else {
            boss_health = boss_health - damage;
            cout << "Thanos has " << boss_health << " health left!" << endl;
        }
    }
}