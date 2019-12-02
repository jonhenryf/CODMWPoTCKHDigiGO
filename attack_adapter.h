//
// Created by mrjof on 12/1/2019.
//

#ifndef CODMWPOTCKHDIGIGO_ATTACK_ADAPTER_H
#define CODMWPOTCKHDIGIGO_ATTACK_ADAPTER_H

#endif //CODMWPOTCKHDIGIGO_ATTACK_ADAPTER_H


#include <iostream>
using namespace std;

//Adaptee Interface
class abstractattack {
public:
    virtual int attack(int gainz) = 0;
};

//Adaptee
class basic_attack : public abstractattack {
public:
    int attack(int gainz) {
        cout << "You used a basic attack!" << endl;
        cout << "You did " << gainz << " damage!" << endl;
        return gainz;
    }
};

//Target Interface
class Abstractrange {
public:
    virtual int attack(int gainz) = 0;
};


//Adapter
class adapter : public Abstractrange
{
   abstractattack* basic_attack;

public:

    void switch_attack(abstractattack* range_attack)
    {
        basic_attack = range_attack;
    }

    int attack(int gainz)
    {
       return basic_attack -> attack(gainz);
    }
};


