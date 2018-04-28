//
// Created by Erik on 4/23/2018.
//
#include <string>
using namespace std;
#ifndef SURVIVALGAME_TEMA2_POO_ITEMS_H
#define SURVIVALGAME_TEMA2_POO_ITEMS_H

class Items {
public:
    Items();
    Items(string, int, int, int);
    void spawnItem(int, int);
    int getPositionX();
    int getPositionY();
    int getID();
private:
    string itemName;
    int itemID = 0;
    int BonusPow, BonusDex, BonusDef;
    int spawnX, spawnY;
};

class Sword : public Items  {
public:
    Sword() : Items(itemName, BonusPow, BonusDex, BonusDef) {}

    string itemName = "Diamond Sword";
    int itemID = -1;
    int BonusPow = 50, BonusDex = -10, BonusDef = 5;
};

class Armor : public Items  {
public:
    Armor() : Items(itemName, BonusPow, BonusDex, BonusDef) {}

    string itemName = "Diamond Suit";
    int itemID = -2;
    int BonusPow = 0, BonusDex = -50, BonusDef = 85;
};

class Shoes : public Items  {
public:
    Shoes() : Items(itemName, BonusPow, BonusDex, BonusDef) {}

    string itemName = "Flying Shoes";
    int itemID = -3;
    int BonusPow = 0, BonusDex = 70, BonusDef = 5;
};


#endif //SURVIVALGAME_TEMA2_POO_ITEMS_H
