//
// Created by Erik on 4/23/2018.
//
#include <iostream>
#include <stdexcept>
#include "Game.h"
#include "Agents.h"
using namespace std;


Agents::Agents(int Pow, int Dex, int Def) {
    srand(time(nullptr));
    this->Power = Pow;
    this->Dexterity = Dex;
    this->Defence = Def;

}
Agents::Agents()    {
    throw invalid_argument("If you are declaring a custom Agent object please note the parameters Power, Dexterity, Defence");
}
/**
 * Daca nu am item sau alt agent in pozitiile din imediata vecinatate ma mut random in stanga sau in dreapta (in caz ca nu ies din harta)
 * @direction reprezinta directa si avem urmatoarele codari: 1 = sus ; 2 = stanga ; 3 = jos ; 4 = dreapta
 * Itemele le voi coda pe harta cu valoare < 0, pozitia libera cu 0, pozitiile ocupate de agenti cu numere > 0
 */
 void Agents::setAgentNumber() {
    this->AgentNumber = this->positionX * this->positionY * 31 + 1; //Numarul cu care vom identifica agentul pe harta, incepand de la 1 pana la nr_rows * nr_cols
    cout << "Test:= "<<this->AgentNumber << " ";
 }
void Agents::Move() {
    srand(time(nullptr));
    int max_rows = 15;
    int max_cols = 15;
    if (this->positionX -1 != 0)
        this->positionX = this->positionX - 1; //Se duce in sus
    else if (this->positionY -1 != 0)
        this->positionY = this->positionY - 1; //Se duce in sus
    else if (this->positionX + 1 != 0)
        this->positionX = this->positionX + 1;
    else if (this->positionY + 1 != 0)
        this->positionY = this->positionY + 1;
    else {
        int direction = rand() % 4 + 1; //Generez numar random intre 1 si 4 ce reprezinta directia
        switch (direction) {
            case 1:
                if (this->positionX - 1 >= 0)
                    this->positionX = this->positionX - 1;
            case 2:
                if (this->positionY - 1 >= 0)
                    this->positionY = this->positionY - 1;
            case 3:
                if (this->positionX + 1 <= max_rows)
                    this->positionX = this->positionX + 1;
            case 4:
                if (this->positionY + 1 <= max_cols)
                    this->positionY = this->positionY + 1;
        }
    }
}

int Agents::getPositionX() {
    //cout << "Apelez getPositionX";
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


void Agents::removeAgent() {
    setID(0);
}

void Agents::collectItem(Items& item) {
    this->Power = item.getItemBonusPow();
    this->Dexterity = item.getItemBonusDex();
    this->Defence = item.getItemBonusDef();
}

int Agents::getAgentNumber() {
     return this->AgentNumber;
 }

int Agents::getAgentPower() {
    return this->Power;
}
int Agents::getAgentDexterity() {
    return this->Dexterity;
}
int Agents::getAgentDefence() {
    return this->Defence;
}

void AgentBruce::Move() {
    cout << "Se apeleaza move";
    srand(time(nullptr));
    int max_rows = 15;
    int max_cols = 15;
    if (this->positionX -1 != 0)
        this->positionX = this->positionX - 1; //Se duce in sus
    else if (this->positionY -1 != 0)
        this->positionY = this->positionY - 1; //Se duce in sus
    else if (this->positionX + 1 != 0)
        this->positionX = this->positionX + 1;
    else if (this->positionY + 1 != 0)
        this->positionY = this->positionY + 1;
    else {
        int direction = rand() % 4 + 1; //Generez numar random intre 1 si 4 ce reprezinta directia
        switch (direction) {
            case 1:
                if (this->positionX - 1 >= 0)
                    this->positionX = this->positionX - 1;
            case 2:
                if (this->positionY - 1 >= 0)
                    this->positionY = this->positionY - 1;
            case 3:
                if (this->positionX + 1 <= max_rows)
                    this->positionX = this->positionX + 1;
            case 4:
                if (this->positionY + 1 <= max_cols)
                    this->positionY = this->positionY + 1;
        }
    }
    cout << "Se executa move";
}

void AgentKevin::Move() {
    cout << "Se apeleaza move";
    srand(time(nullptr));
    int max_rows = 15;
    int max_cols = 15;
    if (this->positionX -1 != 0)
        this->positionX = this->positionX - 1; //Se duce in sus
    else if (this->positionY -1 != 0)
        this->positionY = this->positionY - 1; //Se duce in sus
    else if (this->positionX + 1 != 0)
        this->positionX = this->positionX + 1;
    else if (this->positionY + 1 != 0)
        this->positionY = this->positionY + 1;
    else {
        int direction = rand() % 4 + 1; //Generez numar random intre 1 si 4 ce reprezinta directia
        switch (direction) {
            case 1:
                if (this->positionX - 1 >= 0)
                    this->positionX = this->positionX - 1;
            case 2:
                if (this->positionY - 1 >= 0)
                    this->positionY = this->positionY - 1;
            case 3:
                if (this->positionX + 1 <= max_rows)
                    this->positionX = this->positionX + 1;
            case 4:
                if (this->positionY + 1 <= max_cols)
                    this->positionY = this->positionY + 1;
        }
    }
    cout << "Se executa move";
}

void AgentBond::Move() {
    cout << "Se apeleaza move";
    srand(time(nullptr));
    int max_rows = 15;
    int max_cols = 15;
    if (this->positionX -1 != 0)
        this->positionX = this->positionX - 1; //Se duce in sus
    else if (this->positionY -1 != 0)
        this->positionY = this->positionY - 1; //Se duce in sus
    else if (this->positionX + 1 != 0)
        this->positionX = this->positionX + 1;
    else if (this->positionY + 1 != 0)
        this->positionY = this->positionY + 1;
    else {
        int direction = rand() % 4 + 1; //Generez numar random intre 1 si 4 ce reprezinta directia
        switch (direction) {
            case 1:
                if (this->positionX - 1 >= 0)
                    this->positionX = this->positionX - 1;
            case 2:
                if (this->positionY - 1 >= 0)
                    this->positionY = this->positionY - 1;
            case 3:
                if (this->positionX + 1 <= max_rows)
                    this->positionX = this->positionX + 1;
            case 4:
                if (this->positionY + 1 <= max_cols)
                    this->positionY = this->positionY + 1;
        }
    }
    cout << "Se executa move";
}