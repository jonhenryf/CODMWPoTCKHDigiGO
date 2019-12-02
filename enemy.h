//
// Created by mrjof on 11/23/2019.
//

#ifndef CODMWPOTCKHDIGIGO_ENEMY_H
#define CODMWPOTCKHDIGIGO_ENEMY_H

#endif //CODMWPOTCKHDIGIGO_ENEMY_H

#include <iostream>
#include <vector>

using namespace std;

//code for multiple enemies will go here

class enemy {

public:

    virtual int attack()
    {
        return 0;
    }

    virtual int remaining_health(int player_damage)
    {
        return 0;
    }

};

class pikachu: public enemy {
public:
    int attack() {
        cout << "Pikachu used Volt Tackle!!" << endl << "-10 Health" << endl;
        return 10;
    }

    int remaining_health(int player_damage) {
        pikachu_health = pikachu_health - player_damage;
        return pikachu_health;
    }

private:
    int pikachu_health = 25;
};

class voldemort: public enemy {
public:
    int attack() {
        cout << "Voldemort used Avada Kedavra!!" << endl << "-50 Health" << endl;
        return 50;
    }

    int remainging_health(int player_damage) {
        voldemort_health = voldemort_health - player_damage;
        return voldemort_health;
    }
private:
    int voldemort_health = 75;
};

class swiper: public enemy {
public:
    int attack() {
        cout << "Swiper no swiping!!" << endl << "-5 Health" << endl;
        return 5;
    }

    int remaining_health(int player_damage) {
        swiper_health = swiper_health - player_damage;
        return swiper_health;
    }

private:
    int swiper_health = 50;
};

class darthvader: public enemy {
public:
    int attack() {
        cout << "Darth Vader is not your father... Darth Vader then uses force choke!!" << endl << "-50 Health" << endl;
        return 50;
    }

    int remaing_health(int player_damage) {
        darthvader_health = darthvader_health - player_damage;
        return  darthvader_health;
    }

private:
    int darthvader_health = 100;
};

