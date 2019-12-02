//
// Created by mrjof on 11/23/2019.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <random>


#include "Character.h"
#include "menu.h"
#include "inventory.h"
#include "thanos.h"
#include "game_data.h"
#include "enemy.h"
#include "items.h"
#include "enemy_actions.h"
#include "attacks.h"
#include "attack_adapter.h"

using namespace std;

int main() {

    string playername;
    int choice = 0;
    int data_choice = 0;
    int enemy_choice = 0;
    int attack_choice = 0;

    menu menu1;

    Character player1;
    inventory inventory1;
    thanos thanos1;
    enemy_actions action1;
    attacks attack1;

    //enemies
    pikachu p;
    swiper s;
    voldemort v;
    darthvader d;

    Abstractenemy *enemy1 = &p;
    Abstractenemy *enemy2 = &s;
    Abstractenemy *enemy3 = &v;
    Abstractenemy *enemy4 = &d;

    //attacks
    basic_attack *basicAttack = new basic_attack;
    adapter *Adapter = new adapter;


    while(1) {

        menu1.display_save_menu();
        menu1.set_choice();
        data_choice = menu1.get_choice();

        if (data_choice == 1) {
            cout << "Loading saved data..." << endl;
            cout << "No saved data... Starting New Game" << endl << endl;

            menu1.display_starting_menu();
            player1.set_player_name();

            playername = player1.get_player_name();

            menu1.display_name(playername);

            player1.set_initial_stats();
            thanos1.set_initial_stats();


            break;

        } else if (data_choice == 2) {
            cout << "Starting New Game" << endl;

            menu1.display_starting_menu();
            player1.set_player_name();

            playername = player1.get_player_name();

            menu1.display_name(playername);

            player1.set_initial_stats();
            thanos1.set_initial_stats();

            break;

        } else if (data_choice == 3) {
            menu1.display_end();
            return 0;

        }

        else {
            menu1.display_default();
        }

    }


   while(1) {

       menu1.display_main_menu(playername);

       menu1.set_choice();

       choice = menu1.get_choice();

       if (choice == 1) {
           cout << "Do this" << endl;
       }

       else if (choice == 2) {

           cout << "Finding enemy..." << endl;
           enemy_choice = action1.gen_random_enemy();

           action1.enemy_events(enemy_choice);

           if (enemy_choice == 1) {
               while (player1.get_current_health() > 0 && enemy1 -> get_remaining_health() > 0) {
                   cout << "Pikachu Health: " << enemy1->get_remaining_health() << endl;
                   cout << "Your Health: " << player1.get_current_health() << endl;

                   attack1.display_attacks();
                   attack1.set_attack();
                   attack_choice = attack1.get_attack();

                   if (attack_choice == 1) {

                       enemy1->set_remaining_health(basicAttack->attack(player1.get_gains()));
                       player1.subtract_current_health(enemy1->attack());

                   } else if (attack_choice == 2) {

                       Adapter->switch_attack(basicAttack);
                       enemy1->set_remaining_health(Adapter->attack(player1.get_gains()));
                       player1.subtract_current_health(enemy1->attack());

                   }
               }

               if (enemy1->get_remaining_health() <= 0) {
                   cout << "You have defeated Pikachu!" << endl;
                   // where a drop will be implemented
               }

               else
               {
                   cout << "Pikachu was too string... Try again next time..." << endl;
               }

               player1.heal_current_health();
               enemy1 -> heal_health();
               continue;
           }


           else if (enemy_choice == 2) {
               cout << "not yet" << endl;
               continue;


           }

           else if (enemy_choice == 3) {
               cout << "not yet" << endl;
               continue;
           }

           else if (enemy_choice == 4) {
               cout << "not yet" << endl;
               continue;
           }


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

//            string newitem;
//            int health_modifier = 0;
//
//            armor* base_armor1 = new base_armor();
//            base_armor1 -> health();
//            base_armor1 -> itemname();
//
//            armor* rust_armor1 = new rusty_armor(*base_armor1);
//            rust_armor1 -> health();
//            rust_armor1 -> itemname();
//
//            armor* plated_armor1 = new armor_large_plate(*rust_armor1);
//            health_modifier = plated_armor1 -> health();
//            newitem = plated_armor1 -> itemname();
//
//            cout << "Health modifier: " << health_modifier << endl;
//            cout << "New item: " << newitem << endl;
//
//            delete base_armor1;
//            delete rust_armor1;
//            delete plated_armor1;

       }

       else if(choice == 6) {
           break;
       }

       else
           menu1.display_default();

   }

   menu1.display_end();
    return 0;
}