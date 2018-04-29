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
/**
 * Seteaza un ID unic pt item
 */
void Items::setItemID() {
    this->itemID = -1 * (this->spawnX + 1) * (this->spawnY + 1) * 7 - 1;
}
/**
 *
 * @param posX
 * @param posY
 * Spawneaza itemul pozitia posX, posY (linie, col)
 */
void Items::spawnItem(int posX, int posY)   {
    this->spawnX = posX;
    this->spawnY = posY;

}
/**
 *
 * @return pozitia X (linia) a itemului
 */
int Items::getPositionX() {
    return this->spawnX;
}

/**
 *
 * @return pozitia Y (coloana) itemului
 */
int Items::getPositionY() {
    return this->spawnY;
}

/**
 *
 * @return ID-ul itemului
 */
int Items::getID() {
    return this->itemID;
}

/**
 *
 * @return Puterea oferita de item
 */
int Items::getItemBonusPow() {
    return this->BonusPow;
}

/**
 *
 * @return Dexteritatea oferita de item
 */
int Items::getItemBonusDex() {
    return this->BonusDex;
}

/**
 *
 * @return Defensiva oferita de item
 */
int Items::getItemBonusDef() {
    return this->BonusDef;
}

