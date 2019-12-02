//
// Created by mrjof on 12/1/2019.
//

#ifndef CODMWPOTCKHDIGIGO_ATTACKS_H
#define CODMWPOTCKHDIGIGO_ATTACKS_H

#include <iostream>

using namespace std;

class attacks {

public:

    void set_attack();
    int get_attack();
    void display_attacks();

private:

    int attack_choice = 0;
    int spell = 0;
    int special_attack = 0;

};


#endif //CODMWPOTCKHDIGIGO_ATTACKS_H
