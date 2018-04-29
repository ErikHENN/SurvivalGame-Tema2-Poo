//
// Created by Erik on 4/23/2018.
//
#include <iostream>
#include "Items.h"
using namespace std;

Items::Items()  {
    throw invalid_argument("If you are declaring a custom Item object please note the parameters Name, Power, Dexterity, Defence");
}
Items::Items(int BonusPow, int BonusDex, int BonusDef)  {
    this->BonusPow = BonusPow;
    this->BonusDex = BonusDex;
    this->BonusDef = BonusDef;
    this->itemID = itemID;

}
void Items::setItemID() {
    this->itemID = -1 * (this->spawnX + 1) * (this->spawnY + 1) * 7 - 1;
    //this->itemID = itemID;
}
void Items::spawnItem(int posX, int posY)   {
    this->spawnX = posX;
    this->spawnY = posY;

}

int Items::getPositionX() {
    return this->spawnX;
}

int Items::getPositionY() {
    return this->spawnY;
}

int Items::getID() {
    return this->itemID;
}

int Items::getItemBonusPow() {
    return this->BonusPow;
}

int Items::getItemBonusDex() {
    return this->BonusDex;
}

int Items::getItemBonusDef() {
    return this->BonusDef;
}

