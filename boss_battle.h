//
// Created by mrjof on 11/23/2019.
//

#ifndef CODMWPOTCKHDIGIGO_BOSS_BATTLE_H
#define CODMWPOTCKHDIGIGO_BOSS_BATTLE_H

#endif //CODMWPOTCKHDIGIGO_BOSS_BATTLE_H

#include <iostream>
#include <vector>

using namespace std;

class final_boss {
public:

    void set_initial_stats () {

        boss_health = 500;
        boss_gains = 50;

    }

private:

    int boss_health = 0;
    int boss_gains = 0;

};