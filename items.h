//
// Created by mrjof on 11/24/2019.
//

#ifndef CODMWPOTCKHDIGIGO_ITEMS_H
#define CODMWPOTCKHDIGIGO_ITEMS_H

#endif //CODMWPOTCKHDIGIGO_ITEMS_H

//This header will be used for all items we put into the game
// will use the design patterns we stated on the assignment

#include <iostream>
#include <vector>

using namespace std;

class armor {

public:

    virtual int health() = 0;
    virtual string itemname() = 0;
    virtual ~armor() {}

private:


};

class base_armor: public armor
{
public:
    virtual int health()
    {
        return 10;
    }

    virtual string itemname (){
        return "Basic Armor";
    }
};

class armor_decorator: public armor
{
public:
    armor_decorator(armor& decorator):m_Decorator(decorator)
    {

    }

    virtual int health(){
       return m_Decorator.health();
    }

    virtual string itemname() {
        return m_Decorator.itemname();
    }
private:
    armor& m_Decorator;
};

class rusty_armor: public armor_decorator{
public:
    rusty_armor(armor& decorator):armor_decorator(decorator)
    {

    }

    virtual int health()
    {
        return armor_decorator::health() - 5;
    }

    virtual string itemname() {

        return armor_decorator::itemname() + " (Rusty)";
    }
};

class armor_large_plate : public armor_decorator {

public:
    armor_large_plate(armor& decorator):armor_decorator(decorator)
    {

    }

    virtual int health()
    {
        return armor_decorator::health() + 10;
    }

    virtual string itemname()
    {
        return armor_decorator::itemname() + " (Large Plate)";
    }

};





