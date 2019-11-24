//
// Created by mrjof on 11/23/2019.
//

#ifndef CODMWPOTCKHDIGIGO_PLAYER_H
#define CODMWPOTCKHDIGIGO_PLAYER_H

#endif //CODMWPOTCKHDIGIGO_PLAYER_H

#include <iostream>
#include <vector>

using namespace std;

class player {

public:

void set_player_name() {

    cin  >> player_name;

}

string get_player_name() {

    return player_name;

}

void set_initial_stats () {

    stats.push_back(30);
    stats.push_back(30);
    stats.push_back(50);


}

int get_max_health () {

    for(int i = 0; i < stats.size(); i++)
    {
        if (i == 0)
        {
            max_health = stats[i];
        }
    }

    return max_health;
}

int get_current_health () {

    for(int i = 0; i < stats.size(); i++)
    {
        if (i == 1)
        {
            current_health = stats[i];
        }
    }

    return current_health;

}

int get_gains () {

    for(int i = 0; i < stats.size(); i++)
    {
        if (i == 2)
        {
            gains = stats[i];
        }
    }

    return gains;
}

void add_max_health (int added_health) {

    for(int i = 0; i < stats.size(); i++)
    {
        if (i == 0)
        {
            stats[i] = stats[i] + added_health;
        }
    }

}

void add_current_health (int added_health) {

    for(int i = 0; i < stats.size(); i++)
    {
        if (i == 1)
        {
            stats[i] = stats[i] + added_health;
        }
    }

}

void subtract_current_health (int subtracted_health) {

    for(int i = 0; i < stats.size(); i++)
    {
        if (i == 1)
        {
            stats[i] = stats[i] - subtracted_health;
        }
    }

}

void add_gains (int added_gains) {

    for(int i = 0; i < stats.size(); i++)
    {
        if (i == 2)
        {
            stats[i] = stats[i] + added_gains;
        }
    }
}


private:

    string player_name;

    vector<int> stats;
    int max_health = 0;
    int current_health = 0;
    int gains = 0;

};