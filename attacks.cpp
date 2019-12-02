//
// Created by mrjof on 12/1/2019.
//

#include "attacks.h"

void attacks::set_attack()
{
    cin >> attack_choice;
}

void attacks::display_attacks()
{

    cout << "Choose your attack:" << endl;
    cout << "1: Basic Attack" << endl;
    cout << "2: Ranged Attack" << endl;

}

int attacks::get_attack()
{
    return attack_choice;
}