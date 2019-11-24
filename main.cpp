//
// Created by mrjof on 11/23/2019.
//

#include <iostream>
#include <vector>
#include "player.h"
#include "menu.h"

using namespace std;

int main() {

    string playername;
    int choice;

    menu menu1;
    player player1;



    menu1.display_starting_menu();
    player1.set_player_name();

    playername = player1.get_player_name();

    menu1.display_name(playername);
    player1.set_initial_stats();

   while(1) {

       menu1.display_main_menu(playername);

       menu1.set_choice();

       choice = menu1.get_choice();

       if (choice == 1) {
           cout << "Do this" << endl;
       }

       else if (choice == 2) {
           cout << "Adding stats as a test" << endl;
           player1.add_max_health(10);
           player1.add_current_health(10);
           player1.subtract_current_health(20);
           player1.add_gains(5);
       }

       else if (choice == 3) {
           menu1.display_stats(player1.get_max_health(), player1.get_current_health(), player1.get_gains());
       }

       else if (choice == 4) {
           cout << "Do this 4" << endl;
       }

       else if (choice == 5) {
        break;
       }

   }

   menu1.display_end();
    return 0;
}