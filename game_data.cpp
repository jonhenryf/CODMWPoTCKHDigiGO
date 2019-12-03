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

//void game_data::loaddata() {
//    ofstream myfile;
//    myfile.open("savedata.txt");
//    string name1;
//    myfile >> name1;
//
//}