//
// Created by mrjof on 11/23/2019.
//

#ifndef CODMWPOTCKHDIGIGO_MENU_H
#define CODMWPOTCKHDIGIGO_MENU_H

#endif //CODMWPOTCKHDIGIGO_MENU_H

#include <iostream>
#include <vector>

using namespace std;

class menu {
public:

    void display_main_menu(string player_name) {

        cout << "What would you like to do " << player_name << "?" << endl;
        cout << "1: Go battle CWB" << endl << "2: Power Up Stats by Eating" << endl << "3: See Current Stats" << endl << "4: Inventory" << endl << "5: Exit" << endl;

    }

    void display_starting_menu () {
        cout << "Welcome to the best game ever!" << endl;
        cout << "Enter your name: " << endl;
    }

    void display_name (string player_name) {

        cout << "Nice!! your name is " << player_name << "!" << endl << "It's time to begin your journey!" << endl;

    }

    void display_stats (int max_health, int current_health, int gains) {

        cout << "Your max health is " << max_health << endl;
        cout << "Your current health is " << current_health << endl;
        cout << "Your GAINZ is " << gains << endl << endl;

    }

    void display_current_health (int current_health) {

        cout << "Your current health is " << current_health << endl;

    }


    void display_end () {
        cout << "Thanks for playing!" << endl;
    }

    void set_choice () {
        cin >> choice;
    }

    int get_choice () {
        return choice;
    }







private:

    int choice;

};