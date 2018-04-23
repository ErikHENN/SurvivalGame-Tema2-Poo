//
// Created by Erik on 4/23/2018.
//
#include <string>
#include "Items.h"
#include "Map.h"
using namespace std;

Map A1;

Items::Items(string name, int Pow, int Dex, int Def)  {
    this->BonusPow = Pow;
    this->BonusDex = Dex;
    this->BonusDef = Def;

    do {
        this->spawnX = rand() % A1.nr_rows;
        this->spawnY = rand() % A1.nr_cols;
    } while(A1.POZ[this->spawnX][this->spawnY] != 0);

    if (this->itemID == 0)
        this->itemID = -1 * (rand() % A1.nr_rows * A1.nr_cols + 1); //Numarul cu care vom identifica agentul pe harta, incepand de la -1 pana la - (nr_rows * nr_cols) . Se va defini doar pentru iteme custom
}
