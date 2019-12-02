//
// Created by mrjof on 12/1/2019.
//

#ifndef CODMWPOTCKHDIGIGO_ENEMY_ACTIONS_H
#define CODMWPOTCKHDIGIGO_ENEMY_ACTIONS_H

#include <ctime>
#include <chrono>
#include <random>
#include <iostream>

using namespace std;

class enemy_actions {

public:

    int gen_random_enemy();
    int gen_random_drop();
    void enemy_events(int enemy_choice);

private:

    int enemy_choice = 0;

};


#endif //CODMWPOTCKHDIGIGO_ENEMY_ACTIONS_H
