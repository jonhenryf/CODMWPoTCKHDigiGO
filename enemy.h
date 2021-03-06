//
// Created by mrjof on 11/23/2019.
//

#ifndef CODMWPOTCKHDIGIGO_ENEMY_H
#define CODMWPOTCKHDIGIGO_ENEMY_H

#endif //CODMWPOTCKHDIGIGO_ENEMY_H

#include <iostream>

using namespace std;

//code for multiple enemies will go here

class Abstractenemy {

public:

    virtual int attack() = 0;

    virtual int get_remaining_health() = 0;

    virtual void set_remaining_health(int player_damage) = 0;

    virtual void heal_health();

};

class pikachu: public Abstractenemy {
public:
    int attack() {
        cout << "Pikachu used Volt Tackle!!" << endl << "-10 Health" << endl;
        return 10;
    }

    void set_remaining_health(int player_damage) {
        pikachu_health = pikachu_health - player_damage;
    }

    int get_remaining_health() {
        return pikachu_health;
    }

    void heal_health() {
        pikachu_health = pikachu_max_health;
    }

private:
    int pikachu_health = 25;
    int pikachu_max_health = 25;
};

class voldemort: public Abstractenemy {
public:
    int attack() {
        cout << "Voldemort used Avada Kedavra!!" << endl << "-50 Health" << endl;
        return 50;
    }

    void set_remaining_health(int player_damage) {
        voldemort_health = voldemort_health - player_damage;
    }

    int get_remaining_health() {
        return voldemort_health;
    }

    void heal_health() {
        voldemort_health = voldemort_max;
    }

private:
    int voldemort_health = 75;
    int voldemort_max = 75;
};

class swiper: public Abstractenemy {
public:
    int attack() {
        cout << "Swiper no swiping!!" << endl << "-5 Health" << endl;
        return 5;
    }

    void set_remaining_health(int player_damage) {
        swiper_health = swiper_health - player_damage;
    }

    int get_remaining_health() {
        return swiper_health;
    }

    void heal_health() {
        swiper_health = swiper_max;
    }

private:
    int swiper_health = 50;
    int swiper_max = 50;
};

class darthvader: public Abstractenemy {
public:
    int attack() {
        cout << "Darth Vader is not your father... Darth Vader then uses force choke!!" << endl << "-50 Health" << endl;
        return 50;
    }

    void set_remaining_health(int player_damage) {
        darthvader_health = darthvader_health - player_damage;
    }

    int get_remaining_health() {
        return darthvader_health;
    }

    void heal_health() {
        darthvader_health = darthvader_max;
    }

private:
    int darthvader_health = 100;
    int darthvader_max = 100;
};