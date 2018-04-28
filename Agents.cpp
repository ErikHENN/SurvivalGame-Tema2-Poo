//
// Created by Erik on 4/23/2018.
//
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "Game.h"
#include "Agents.h"
#include "Map.h"
using namespace std;

Map A;
Agents::Agents(int Pow, int Dex, int Def) {
    this->Power = Pow;
    this->Dexterity = Dex;
    this->Defence = Def;

    this->AgentNumber = rand() % 100 * 100 + 1; //Numarul cu care vom identifica agentul pe harta, incepand de la 1 pana la nr_rows * nr_cols
}
Agents::Agents()    {
    throw invalid_argument("If you are declaring a custom Agent object please note the parameters Power, Dexterity, Defence");
}
/**
 * @direction reprezinta directa si avem urmatoarele codari: 1 = sus ; 2 = stanga ; 3 = jos ; 4 = dreapta
 * Itemele le voi coda pe harta cu valoare < 0, pozitia libera cu 0, pozitiile ocupate de agenti cu numere > 0
 */
void Agents::Move() {
    int direction = rand() % 4 + 1; //Generez numar random intre 1 si 4 ce reprezinta directia
    switch (direction)  {
        case 1:
            if (this->positionX - 1 >= 0)
                this->positionX = this->positionX - 1;
        case 2:
            if (this->positionY - 1 >= 0)
                this->positionY = this->positionY - 1;
        case 3:
            if (this->positionX + 1 <= A.nr_rows)
                this->positionX = this->positionX + 1;
        case 4:
            if (this->positionY + 1 >= 0)
                this->positionY = this->positionY + 1;
    }
}

int Agents::getPositionX() {
    return this->positionX;
}

int Agents::getPositionY() {
    return this->positionY;
}


void Agents::setPosition(int posX, int posY) {
    this->positionX = posX;
    this->positionY = posY;
}

void Agents::setID(int id)  {
    this->AgentNumber = id;
}
Agents::attributes Agents::getAttributes()  {
    return this->a;
}

void Agents::removeAgent() {
    setID(0);
}
