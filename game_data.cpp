//
// Created by mrjof on 11/24/2019.
//

#include "game_data.h"


void game_data::savedata(vector<string> inventory, string name) {

    ofstream myfile;
    myfile.open("savedata.txt");
    myfile << name << endl;
    for (int i = 0; i < inventory.size(); i++) {
        myfile << inventory[i] << endl;
    }
    myfile.close();
}

vector<string> game_data::loaddata() {
    ifstream myfile;
    myfile.open("savedata.txt");
    vector<string> inv;
    string data1;
    while(getline(myfile, data1))
    {
        cout << data1 << endl;
        inv.push_back(data1);
    }
    myfile.close();
    return inv;
}