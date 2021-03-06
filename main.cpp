//
// Created by mrjof on 11/23/2019.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <random>

// class and header files
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

    srand(time(NULL));

    string playername;
    int choice = 0;
    int data_choice = 0;
    int enemy_choice = 0;
    int attack_choice = 0;
    int drop_value = 0;

    menu menu1;
    Character player1;
    inventory inventory1;
    thanos thanos1;
    enemy_actions action1;
    attacks attack1;
    game_data gamedata1;

    //for item drop
    string newitem;

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
            vector<string> savedata = gamedata1.loaddata();
//            cout << "No saved data... Starting New Game" << endl << endl;

            playername = savedata[0];
            menu1.display_name(playername);
            savedata.erase(savedata.begin());
            player1.set_initial_stats();
            thanos1.set_initial_stats();
            if (!savedata.empty()) {
                while (!savedata.empty()) {
                    if (savedata[0] == "Basic Armor (Bronze) (Medium Plate)")
                    {
                        player1.add_max_health(40);
                    }
                    else if (savedata[0] == "Basic Sword (Diamond)")
                    {
                        player1.add_gains(110);
                    }
                    else if (savedata[0] == "Basic Sword (Bronze)")
                    {
                        player1.add_gains(40);
                    }
                    else if (savedata[0] == "Basic Armor (Platinum) (Large Plate)")
                    {
                        player1.add_max_health(60);
                    }
                    inventory1.add_to_inventory(savedata[0]);
                    savedata.erase(savedata.begin());
                }
                player1.heal_current_health();
            }
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
           if (!thanos1.is_alive())
           {
               cout << "You have already defeated thanos. Stay tuned for the next boss update!" << endl;
           }
           else {
               while (player1.get_current_health() > 0 && thanos1.is_alive()) {
                   cout << "Thanos's Health: " << thanos1.get_health() << endl;
                   cout << "Your Health: " << player1.get_current_health() << endl;

                   attack1.display_attacks();
                   attack1.set_attack();
                   attack_choice = attack1.get_attack();

                   if (attack_choice == 1) {

                       thanos1.take_damage((basicAttack->attack(player1.get_gains())), attack_choice);
                       if (thanos1.get_health() > 0) {
                           player1.subtract_current_health(thanos1.get_gainz());
                       }
                   } else if (attack_choice == 2) {

                       Adapter->switch_attack(basicAttack);
                       thanos1.take_damage((basicAttack->attack(player1.get_gains())), attack_choice);
                       if (thanos1.get_health() > 0) {
                           player1.subtract_current_health(thanos1.get_gainz());
                       }
                   } else {
                       menu1.display_default();
                   }
                   if (thanos1.is_alive()) {
                       thanos1.weakness_change();
                   }
                   if (player1.get_current_health() <= 0) {
                       cout << "You don't feel so good Mr. Stark..." << endl;
                       if (!inventory1.inventory_is_empty()) {
                           string temp = inventory1.remove_from_inventory();
                           thanos1.steal_item(temp);
                           cout << "Thanos steals one of your items from your inventory." << endl;
                           cout << "Expect to find him stronger than before." << endl;

                           if (temp == "Basic Armor (Bronze) (Medium Plate)") {
                               player1.add_max_health(-40);
                           } else if (temp == "Basic Sword (Diamond)") {
                               player1.add_gains(-110);
                           } else if (temp == "Basic Sword (Bronze)") {
                               player1.add_gains(-40);
                           } else if (temp == "Basic Armor (Platinum) (Large Plate)") {
                               player1.add_max_health(-60);
                           }
                           cout << "You feel your strength leaving you..." << endl;
                       }
                   }
               }
               player1.heal_current_health();
           }
       }

       else if (choice == 2) {

           cout << "Finding enemy..." << endl;

           enemy_choice = action1.gen_random_enemy();

           action1.enemy_events(enemy_choice);

           if (enemy_choice == 1 || enemy_choice == 2) {
               enemy1 -> heal_health();
               while (player1.get_current_health() > 0 && enemy1 -> get_remaining_health() > 0) {
                   cout << "Pikachu's Health: " << enemy1->get_remaining_health() << endl;
                   cout << "Your Health: " << player1.get_current_health() << endl;

                   attack1.display_attacks();
                   attack1.set_attack();
                   attack_choice = attack1.get_attack();

                   if (attack_choice == 1) {
                       cout << "Attack Failed!" << endl;

//                       enemy1->set_remaining_health(basicAttack->attack(player1.get_gains()));
                       player1.subtract_current_health(enemy1->attack());

                   } else if (attack_choice == 2) {

                       Adapter->switch_attack(basicAttack);
                       enemy1->set_remaining_health(Adapter->attack(player1.get_gains()));
                       player1.subtract_current_health(enemy1->attack());

                   }
                   else {
                       menu1.display_default();
                   }
               }

               if (enemy1->get_remaining_health() <= 0) {
                   cout << "You have defeated Pikachu!" << endl;
                   // where a drop will be implemented

                   drop_value = (rand() % 2) + 1;

                   if (drop_value == 1) {

                       int health_modifier1 = 0;

                       armor* base_armor1 = new base_armor();
                       base_armor1 -> health();
                       base_armor1 -> itemname();

                       armor* bronze_armor1 = new bronze_armor(*base_armor1);
                       bronze_armor1 -> health();
                       bronze_armor1 -> itemname();
                       armor* plated_armor1 = new armor_medium_plate(*bronze_armor1);
                       health_modifier1 = plated_armor1 -> health();
                       newitem = plated_armor1 -> itemname();

                       cout << "Health modifier: " << health_modifier1 << endl;
                       cout << "Dropped New item: " << newitem << endl;

                       if(inventory1.check_inventory(newitem)){

                           cout << "You already have this item!" << endl;

                       }
                       else {
                           inventory1.add_to_inventory(newitem);
                           player1.add_max_health(health_modifier1);
                       }

                       delete base_armor1;
                       delete bronze_armor1;
                       delete plated_armor1;

                   }

                   else if(drop_value == 2) {
                       cout << "Nothing has dropped..." << endl;
                   }
               }

               else
               {
                   cout << "Pikachu was too strong... Try again next time..." << endl;
               }

               player1.heal_current_health();
               continue;
           }


           else if (enemy_choice == 3 || enemy_choice == 4) {
               enemy2 -> heal_health();
               while (player1.get_current_health() > 0 && enemy2 -> get_remaining_health() > 0) {
                   cout << "Swiper's Health: " << enemy2->get_remaining_health() << endl;
                   cout << "Your Health: " << player1.get_current_health() << endl;

                   attack1.display_attacks();
                   attack1.set_attack();
                   attack_choice = attack1.get_attack();

                   if (attack_choice == 1) {

                       enemy2->set_remaining_health(basicAttack->attack(player1.get_gains()));
                       player1.subtract_current_health(enemy2->attack());

                   } else if (attack_choice == 2) {

                       Adapter->switch_attack(basicAttack);
                       enemy2->set_remaining_health(Adapter->attack(player1.get_gains()));
                       player1.subtract_current_health(enemy2->attack());
                   }
                   else {
                       menu1.display_default();
                   }
               }

               if (enemy2->get_remaining_health() <= 0) {
                   cout << "You have defeated Swiper!" << endl;
                   // where a drop will be implemented

                   drop_value = (rand() % 2) + 1;

                   if (drop_value == 1) {

                       int gainz_modifier1 = 0;

                       sword* base_sword1 = new base_sword();
                       base_sword1 -> gainz();
                       base_sword1 -> itemname();

                       sword* bronze_sword1 = new bronze_sword(*base_sword1);
                       gainz_modifier1 = bronze_sword1 -> gainz();
                       newitem = bronze_sword1 -> itemname();

                       cout << "Gainz modifier: " << gainz_modifier1 << endl;
                       cout << "Dropped New item: " << newitem << endl;

                       if(inventory1.check_inventory(newitem)){
                           cout << "You already have this item!" << endl;
                       }
                       else {
                           inventory1.add_to_inventory(newitem);
                           player1.add_gains(gainz_modifier1);
                       }
                       delete base_sword1;
                       delete bronze_sword1;
                   }
                   else if (drop_value == 2) {
                       cout << "Nothing has dropped..." << endl;
                   }
               }
               else
               {
                   cout << "Swiper was too strong... Try again next time..." << endl;
               }

               player1.heal_current_health();
               continue;
           }

           else if (enemy_choice == 5) {
               enemy3 -> heal_health();
               while (player1.get_current_health() > 0 && enemy3 -> get_remaining_health() > 0) {
                   cout << "Voldemort's Health: " << enemy3->get_remaining_health() << endl;
                   cout << "Your Health: " << player1.get_current_health() << endl;

                   attack1.display_attacks();
                   attack1.set_attack();
                   attack_choice = attack1.get_attack();

                   if (attack_choice == 1) {
                       cout << "Attack Failed!" << endl;
//                       enemy3->set_remaining_health(basicAttack->attack(player1.get_gains()));
                       player1.subtract_current_health(enemy3->attack());

                   } else if (attack_choice == 2) {

                       Adapter->switch_attack(basicAttack);
                       enemy3->set_remaining_health(Adapter->attack(player1.get_gains()));
                       player1.subtract_current_health(enemy3->attack());

                   }
                   else {
                       menu1.display_default();
                   }
               }

               if (enemy3->get_remaining_health() <= 0) {
                   cout << "You have defeated Voldemort!" << endl;

                   drop_value = (rand() % 2) + 1;

                   if (drop_value == 1) {

                        int health_modifier = 0;

                        armor* base_armor1 = new base_armor();
                        base_armor1 -> health();
                        base_armor1 -> itemname();

                        armor* platinum_armor1 = new platinum_armor(*base_armor1);
                        platinum_armor1 -> health();
                        platinum_armor1 -> itemname();

                        armor* plated_armor1 = new armor_large_plate(*platinum_armor1);
                        health_modifier = plated_armor1 -> health();
                        newitem = plated_armor1 -> itemname();

                        cout << "Health modifier: " << health_modifier << endl;
                        cout << "Dropped New item: " << newitem << endl;

                       if(inventory1.check_inventory(newitem)){
                           cout << "You already have this item!" << endl;
                       }
                       else {
                           inventory1.add_to_inventory(newitem);
                           player1.add_max_health(health_modifier);
                       }
                        delete base_armor1;
                        delete platinum_armor1;
                        delete plated_armor1;
                   }
                   else if (drop_value == 2) {
                       cout << "Nothing has dropped..." << endl;
                   }
               }
               else
               {
                   cout << "Voldemort was too strong... Try again next time..." << endl;
               }
               player1.heal_current_health();

               continue;
           }

           else if (enemy_choice == 6) {
               enemy4 -> heal_health();
               while (player1.get_current_health() > 0 && enemy4 -> get_remaining_health() > 0) {
                   cout << "Darth Vader's Health: " << enemy4->get_remaining_health() << endl;
                   cout << "Your Health: " << player1.get_current_health() << endl;

                   attack1.display_attacks();
                   attack1.set_attack();
                   attack_choice = attack1.get_attack();

                   if (attack_choice == 1) {
                       enemy4->set_remaining_health(basicAttack->attack(player1.get_gains()));
                       player1.subtract_current_health(enemy4->attack());
                   } else if (attack_choice == 2) {
                       cout << "Attack Failed!" << endl;
//                       Adapter->switch_attack(basicAttack);
//                       enemy4->set_remaining_health(Adapter->attack(player1.get_gains()));
                       player1.subtract_current_health(enemy4->attack());
                   }
                   else {
                       menu1.display_default();
                   }
               }

               if (enemy4->get_remaining_health() <= 0) {

                   cout << "You have defeated Darth Vader!" << endl;

                   drop_value = (rand() % 2) + 1;

                   if (drop_value == 1) {

                       int gainz_modifier = 0;

                       sword* base_sword1 = new base_sword();
                       base_sword1 -> gainz();
                       base_sword1 -> itemname();

                       sword* diamond_sword1 = new diamond_sword(*base_sword1);
                       gainz_modifier = diamond_sword1 -> gainz();
                       newitem = diamond_sword1 -> itemname();

                       cout << "Gainz modifier: " << gainz_modifier << endl;
                       cout << "Dropped New item: " << newitem << endl;

                       if(inventory1.check_inventory(newitem)){
                           cout << "You already have this item!" << endl;
                       }
                       else {
                           inventory1.add_to_inventory(newitem);
                           player1.add_gains (gainz_modifier);
                       }
                       delete base_sword1;
                       delete diamond_sword1;
                   }

                   else if (drop_value == 2) {
                       cout << "Nothing has dropped..." << endl;
                   }
               }

               else
               {
                   cout << "Darth Vader was too strong... Try again next time..." << endl;
               }
               player1.heal_current_health();
               continue;
           }

       }

       else if (choice == 3) {
           menu1.display_stats(player1.get_max_health(), player1.get_current_health(), player1.get_gains());
       }

       else if (choice == 4) {
               inventory1.print_inventory();
       }

       else if (choice == 5) {
            cout <<"Saving Game..." << endl;
            gamedata1.savedata(inventory1.get_inventory(), player1.get_player_name());
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