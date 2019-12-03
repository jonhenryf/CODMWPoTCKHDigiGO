//
// Created by mrjof on 11/24/2019.
//

#ifndef CODMWPOTCKHDIGIGO_THANOS_H
#define CODMWPOTCKHDIGIGO_THANOS_H

#include <iostream>
#include <vector>

using namespace std;

class thanos {

public:

    void set_initial_stats ();
    void add_gainz(int gains);
    void add_health(int health);
    int get_gainz();
    int get_health();
    bool is_alive();

    void steal_item(string item);
    void take_damage(int damage, int choice);
    void weakness_change();


private:
    int max_boss_health = 0;
    int boss_health = 0;
    int boss_gains = 0;
    bool alive;
    int weakness = 0;
};


#endif //CODMWPOTCKHDIGIGO_THANOS_H
