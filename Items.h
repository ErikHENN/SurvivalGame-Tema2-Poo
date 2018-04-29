//
// Created by Erik on 4/23/2018.
//
#include <string>
#include <ctime>
using namespace std;
#ifndef SURVIVALGAME_TEMA2_POO_ITEMS_H
#define SURVIVALGAME_TEMA2_POO_ITEMS_H

class Items {
public:
    Items();
    Items(int, int, int);
    void spawnItem(int, int);
    int getPositionX();
    int getPositionY();
    int getID();
    int getItemBonusPow();
    int getItemBonusDex();
    int getItemBonusDef();
    void setItemID();
public:
    int itemID = 0;
    int BonusPow, BonusDex, BonusDef;
    int spawnX, spawnY;
};

class Sword : public Items  {
public:
    Sword() : Items(50, -10, 5) { }

    int itemID = -1;
};

class Armor : public Items  {
public:
    Armor() : Items(0,-50, 85) {}

    int itemID = -2;
};

class Shoes : public Items  {
public:
    Shoes() : Items(0, 70, 5) {}

    int itemID = -3;
};


#endif //SURVIVALGAME_TEMA2_POO_ITEMS_H
