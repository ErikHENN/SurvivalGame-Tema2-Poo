//
// Created by Erik on 4/23/2018.
//
#include <string>
#include "Items.h"
#include "Map.h"
using namespace std;


Items::Items(string name, int Pow, int Dex, int Def)  {
    this->BonusPow = Pow;
    this->BonusDex = Dex;
    this->BonusDef = Def;

    if (this->itemID == 0)
        this->itemID = -1 * (rand() % 50 * 50 + 1); //Numarul cu care vom identifica agentul pe harta, incepand de la -1 pana la - (nr_rows * nr_cols) . Se va defini doar pentru iteme custom
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