//
// Created by Erik on 4/23/2018.
//
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "Agents.h"
#include "Map.h"
using namespace std;

Map A;

Agents::Agents(int Pow, int Dex, int Def) {
    this->Power = Pow;
    this->Dexterity = Dex;
    this->Defence = Def;

    do {
        this->positionX = rand() % A.nr_rows;
        this->positionY = rand() % A.nr_cols;
    } while(A.POZ[this->positionX][this->positionY] != 0);

    this->AgentNumber = rand() % A.nr_rows * A.nr_cols + 1; //Numarul cu care vom identifica agentul pe harta, incepand de la 1 pana la nr_rows * nr_cols
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

void Agents::Fight(Agents Enemy) {
    float aptitudesAgent1, aptitudesAgent2;
    aptitudesAgent1 = 0.5 * this->Power + 0.7 * this->Dexterity + 0.35 * this->Defence;
    aptitudesAgent2 = 0.5 * Enemy.Power + 0.7 * Enemy.Dexterity + 0.35 * Enemy.Defence;

    if (aptitudesAgent1 < aptitudesAgent2)
        this->AgentNumber = 0; //Scot agentul de pe harta
}

