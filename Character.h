//
// Created by mrjof on 11/24/2019.
//

#ifndef CODMWPOTCKHDIGIGO_CHARACTER_H
#define CODMWPOTCKHDIGIGO_CHARACTER_H

#include <iostream>
#include <vector>

using namespace std;

class Character {
public:

    void set_player_name();
    string get_player_name();
    void set_initial_stats ();
    int get_max_health ();
    int get_current_health ();
    int get_gains ();
    void add_max_health(int added_health);
    void add_current_health (int added_health);
    void subtract_current_health (int subtracted_health);
    void add_gains (int added_gains);



private:

    string player_name;
    vector<int> stats;
    int max_health = 0;
    int current_health = 0;
    int gains = 0;

};


#endif //CODMWPOTCKHDIGIGO_CHARACTER_H
