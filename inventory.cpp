//
// Created by mrjof on 11/24/2019.
//

#include "inventory.h"

void inventory::add_to_inventory(string item)
{
    inventory.push_back(item);
}
vector<string> inventory::get_inventory(){
    return inventory;
}

void inventory::print_inventory()
{
    if(inventory.empty()) {
        cout << "Your inventory is currently empty!" << endl << endl;
    }
    else
        for (int i = 0; i < inventory.size(); i++) {
            cout << inventory[i] << endl;
        }
}

bool inventory::inventory_is_empty()
{
    if(!inventory.empty()) {
        return false;
    } else
        return true;
}

bool inventory::check_inventory(string item)
{
    bool result = false;

    for (int i = 0; i < inventory.size(); i++) {
        if(inventory[i] == item) {
            result = true;
            break;
        }
        else
            result = false;
    }
    return result;
}

