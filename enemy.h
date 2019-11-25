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

};

class pikachu: public enemy {
public:
    int attack() {
        cout << "Pikachu used Volt Tackle!!" << endl << "-10 Health" << endl;
        return 10;
    }
};

class voldemort: public enemy {
public:
    int attack() {
        cout << "Voldemort used Avada Kedavra!!" << endl << "-50 Health" << endl;
        return 50;
    }
};

class swiper: public enemy {
public:
    int attack() {
        cout << "Swiper swiped your stuff!!" << endl << "-5 Health" << endl;
        return 5;
    }
};

class darthvader: public enemy {
public:
    int attack() {
        cout << "Darth Vader is not your father... Darth Vader then uses force choke!!" << endl << "-50 Health" << endl;
        return 50;
    }
};

