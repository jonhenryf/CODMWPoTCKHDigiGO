//
// Created by mrjof on 11/24/2019.
//

#ifndef CODMWPOTCKHDIGIGO_INVENTORY_H
#define CODMWPOTCKHDIGIGO_INVENTORY_H

#include <iostream>
#include <vector>

using namespace std;

class inventory {

public:

    void add_to_inventory(string item);
    void print_inventory();
    bool inventory_is_empty ();
    bool check_inventory(string item);
    vector<string> get_inventory();

private:

    vector<string> inventory;

};


#endif //CODMWPOTCKHDIGIGO_INVENTORY_H
