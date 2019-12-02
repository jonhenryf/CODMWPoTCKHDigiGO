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

class bronze_armor: public armor_decorator{
public:
    bronze_armor(armor& decorator):armor_decorator(decorator)
    {

    }

    virtual int health()
    {
        return armor_decorator::health() + 30;
    }

    virtual string itemname() {

        return armor_decorator::itemname() + " (Bronze)";
    }
};

class platinum_armor: public armor_decorator{
public:
    platinum_armor(armor& decorator):armor_decorator(decorator)
    {

    }

    virtual int health()
    {
        return armor_decorator::health() + 50;
    }

    virtual string itemname() {

        return armor_decorator::itemname() + " (Platinum)";
    }
};


class diamond_armor: public armor_decorator{
public:
    diamond_armor(armor& decorator):armor_decorator(decorator)
    {

    }

    virtual int health()
    {
        return armor_decorator::health() + 100;
    }

    virtual string itemname() {

        return armor_decorator::itemname() + " (Diamond)";
    }
};


class armor_large_plate : public armor_decorator {

public:
    armor_large_plate(armor& decorator):armor_decorator(decorator)
    {

    }

    virtual int health()
    {
        return armor_decorator::health() + 20;
    }

    virtual string itemname()
    {
        return armor_decorator::itemname() + " (Large Plate)";
    }

};

class armor_medium_plate : public armor_decorator {

public:
    armor_medium_plate(armor& decorator):armor_decorator(decorator)
    {

    }

    virtual int health()
    {
        return armor_decorator::health() + 10;
    }

    virtual string itemname()
    {
        return armor_decorator::itemname() + " (Medium Plate)";
    }

};

class sword {

public:

    virtual int gainz() = 0;
    virtual string itemname() = 0;
    virtual ~sword() {}

private:


};

class base_sword: public sword
{
public:
    virtual int gainz()
    {
        return 10;
    }

    virtual string itemname (){
        return "Basic Sword";
    }
};

class sword_decorator: public sword
{
public:
    sword_decorator(sword& decorator):s_Decorator(decorator)
    {

    }

    virtual int gainz(){
        return s_Decorator.gainz();
    }

    virtual string itemname() {
        return s_Decorator.itemname();
    }
private:
    sword& s_Decorator;
};

class rusty_sword: public sword_decorator{
public:
    rusty_sword(sword& decorator):sword_decorator(decorator)
    {

    }

    virtual int gainz()
    {
        return sword_decorator::gainz() - 5;
    }

    virtual string itemname() {

        return sword_decorator::itemname() + " (Rusty)";
    }
};

class bronze_sword: public sword_decorator{
public:
    bronze_sword(sword& decorator):sword_decorator(decorator)
    {

    }

    virtual int gainz()
    {
        return sword_decorator::gainz() + 30;
    }

    virtual string itemname() {

        return sword_decorator::itemname() + " (Bronze)";
    }
};

class platinum_sword: public sword_decorator{
public:
    platinum_sword(sword& decorator):sword_decorator(decorator)
    {

    }

    virtual int gainz()
    {
        return sword_decorator::gainz() + 50;
    }

    virtual string itemname() {

        return sword_decorator::itemname() + " (Platinum)";
    }
};

class diamond_sword: public sword_decorator{
public:
    diamond_sword(sword& decorator):sword_decorator(decorator)
    {

    }

    virtual int gainz()
    {
        return sword_decorator::gainz() + 100;
    }

    virtual string itemname() {

        return sword_decorator::itemname() + " (Diamond)";
    }
};











