//
// Created by mrjof on 11/23/2019.
//

#ifndef CODMWPOTCKHDIGIGO_INVENTORY_H
#define CODMWPOTCKHDIGIGO_INVENTORY_H

#endif //CODMWPOTCKHDIGIGO_INVENTORY_H

#include <iostream>
#include <vector>

using namespace std;

class inventory {
public:

    void add_to_inventory(string item){
        inventory.push_back(item);
    }

    void print_inventory() {

        if(inventory.empty()) {
            cout << "Your inventory is currently empty!" << endl << endl;
        }

        else

            for (int i = 0; i < inventory.size(); i++) {
                cout << inventory[i] << endl;
            }

    }

    bool inventory_is_empty () {
        if(!inventory.empty()) {
            return false;
        } else
            return true;
    }



private:

    vector<string> inventory;

};