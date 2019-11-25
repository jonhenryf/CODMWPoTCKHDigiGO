//
// Created by mrjof on 11/23/2019.
//

#include <iostream>
#include <vector>
#include "player.h"
#include "menu.h"
#include "inventory.h"
#include "boss_battle.h"
#include "enemy.h"
#include "items.h"

using namespace std;

int main() {

    string playername;
    int choice = 0;
    int data_choice = 0;

    menu menu1;
    player player1;
    inventory inventory1;


    menu1.display_save_menu();
    menu1.set_choice();
    data_choice = menu1.get_choice();

    if(data_choice == 1) {
        cout << "Loading saved data..." << endl;
        cout << "No saved data... Starting New Game" << endl << endl;

        menu1.display_starting_menu();
        player1.set_player_name();

        playername = player1.get_player_name();

        menu1.display_name(playername);

        player1.set_initial_stats();

    }

    else{
        cout << "Starting New Game" << endl;

        menu1.display_starting_menu();
        player1.set_player_name();

        playername = player1.get_player_name();

        menu1.display_name(playername);

        player1.set_initial_stats();

    }


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

               cout << "Inventory testing with no items" << endl;
               inventory1.print_inventory();

               cout << "Now adding items..." << endl;
               inventory1.add_to_inventory("Rusty Armor");
               inventory1.add_to_inventory("Rusty Sword");
               inventory1.add_to_inventory("Rusty Helmet");
               inventory1.print_inventory();

       }

       else if (choice == 5) {
            cout <<"Saving Game..." << endl;

            string newitem;
            int health_modifier = 0;

            armor* base_armor1 = new base_armor();
            base_armor1 -> health();
            base_armor1 -> itemname();

            armor* rust_armor1 = new rusty_armor(*base_armor1);
            rust_armor1 -> health();
            rust_armor1 -> itemname();

            armor* plated_armor1 = new armor_large_plate(*rust_armor1);
            health_modifier = plated_armor1 -> health();
            newitem = plated_armor1 -> itemname();

            cout << "Health modifier: " << health_modifier << endl;
            cout << "New item: " << newitem << endl;

            delete base_armor1;
            delete rust_armor1;

       }

       else if(choice == 6) {
           break;
       }

   }

   menu1.display_end();
    return 0;
}