//
// Created by mrjof on 11/24/2019.
//

#include "menu.h"

void menu::display_main_menu(string player_name)
{
    cout << "What would you like to do " << player_name << "?" << endl;
    cout << "1: Boss Battle!!!!" << endl << "2: Fight enemies! (Items can be dropped from defeating enemies)" << endl << "3: See Current Stats" << endl << "4: Inventory" << endl << "5: Save Game" << endl << "6: Exit" << endl;

}

void menu::display_starting_menu()
{
    cout << "Welcome to the best game ever!" << endl;
    cout << "Enter your name: " << endl;
}

void menu::display_save_menu()
{
    cout << "Load previous data?" << endl << "1: Yes" << endl << "2: No" << endl << "3: Exit" << endl;
}

void menu::display_default()
{
    cout << "Please select a valid choice! Thanks! <3" << endl;
}

void menu::display_name(string player_name)
{
    cout << "Nice!! your name is " << player_name << "!" << endl << "It's time to begin your journey!" << endl;
}

void menu::display_stats(int max_health, int current_health, int gains)
{
    cout << "Your max health is " << max_health << endl;
    cout << "Your current health is " << current_health << endl;
    cout << "Your GAINZ is " << gains << endl << endl;
}

void menu::display_current_health(int current_health)
{
    cout << "Your current health is " << current_health << endl;
}

void menu::display_end()
{
    cout << "Thanks for playing!" << endl;
}

void menu::set_choice()
{
    cin >> choice;
}

int menu::get_choice()
{
    return choice;
}