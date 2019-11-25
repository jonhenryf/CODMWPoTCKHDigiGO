//
// Created by mrjof on 11/24/2019.
//

#ifndef CODMWPOTCKHDIGIGO_MENU_H
#define CODMWPOTCKHDIGIGO_MENU_H

#include <iostream>
#include <vector>

using namespace std;

class menu {

public:

    void display_main_menu(string player_name);
    void display_starting_menu ();
    void display_save_menu ();
    void display_default ();
    void display_name (string player_name);
    void display_stats (int max_health, int current_health, int gains);
    void display_current_health (int current_health);
    void display_end ();
    void set_choice ();
    int get_choice ();

private:

    int choice = 0;

};


#endif //CODMWPOTCKHDIGIGO_MENU_H
