//
// Created by mrjof on 12/1/2019.
//

#include "enemy_actions.h"

int enemy_actions::gen_random_enemy()
{
    return (rand() % 4) + 1;
}

int enemy_actions::gen_random_drop()
{
    return (rand() % 4) + 1;
}

bool enemy_actions::defeated(int enemy_health)
{
    if (enemy_health <= 0){
        return true;
    }
    else
        return false;
}


void enemy_actions::enemy_events(int enemy_choice)
{
    if(enemy_choice == 1)
    {
        cout << "Pikachu has appeared!" << endl;

    }

    else if (enemy_choice == 2)
    {
        cout << "Voldemort has appeared!" << endl;

    }

    else if (enemy_choice == 3)
    {
        cout << "Swiper has appeared!" << endl;
    }

    else if (enemy_choice == 4)
    {
        cout << "Darth Vader has appeared!" << endl;
    }
}



//            string newitem;
//            int health_modifier = 0;
//
//            armor* base_armor1 = new base_armor();
//            base_armor1 -> health();
//            base_armor1 -> itemname();
//
//            armor* rust_armor1 = new rusty_armor(*base_armor1);
//            rust_armor1 -> health();
//            rust_armor1 -> itemname();
//
//            armor* plated_armor1 = new armor_large_plate(*rust_armor1);
//            health_modifier = plated_armor1 -> health();
//            newitem = plated_armor1 -> itemname();
//
//            cout << "Health modifier: " << health_modifier << endl;
//            cout << "New item: " << newitem << endl;
//
//            delete base_armor1;
//            delete rust_armor1;
//            delete plated_armor1;