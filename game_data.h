//
// Created by mrjof on 11/24/2019.
//

#ifndef CODMWPOTCKHDIGIGO_GAME_DATA_H
#define CODMWPOTCKHDIGIGO_GAME_DATA_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class game_data {

public:
    void savedata(vector<string> inventory, string name);
    vector<string> loaddata();

};


#endif //CODMWPOTCKHDIGIGO_GAME_DATA_H
