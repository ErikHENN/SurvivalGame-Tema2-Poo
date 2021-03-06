//
// Created by Erik on 4/23/2018.
//
#include <iostream>
#include <stdexcept>
#include "Game.h"
#include "Agents.h"
using namespace std;


Agents::Agents(int Pow, int Dex, int Def) {
    this->Power = Pow;
    this->Dexterity = Dex;
    this->Defence = Def;

}
Agents::Agents()    {
    throw invalid_argument("If you are declaring a custom Agent object please note the parameters Power, Dexterity, Defence");
}
/**
 * Atribui agentului un ID unic in functie de pozitia pe care se afla.
 */
 void Agents::setAgentNumber() {
    this->AgentNumber = (this->positionX + 1) * (this->positionY + 1) * 31 + 1; //Numarul cu care vom identifica agentul pe harta, incepand de la 1 pana la nr_rows * nr_cols
 }

int Agents::getPositionX() {
    return this->positionX;
}

int Agents::getPositionY() {
    return this->positionY;
}

/**
 *
 * @param posX - linie
 * @param posY  - coloana
 * Seteaza pozitia agentului.
 */
void Agents::setPosition(int posX, int posY) {
    this->positionX = posX;
    this->positionY = posY;
}
/**
 *
 * @param id
 * Seteaza id-ul agentului (in caz de se doreste o setare manuala)
 */
void Agents::setID(int id)  {
    this->AgentNumber = id;
}

/**
 * Sterge agentul de pe harta dandu-i ID-ul 0 (pozitie libera)
 */
void Agents::removeAgent() {
    this->AgentNumber = 0;
}

/**
 *
 * @param item - itemul gasit
 * Adauga atributiile itemului la puterile agentului
 */
void Agents::collectItem(Items item) {
    this->Power += item.getItemBonusPow();
    this->Dexterity += item.getItemBonusDex();
    this->Defence += item.getItemBonusDef();
}

/**
 *
 * @return numarul agentului
 */
int Agents::getAgentNumber() {
    return this->AgentNumber;
}

/**
 *
 * @return puterea agentului
 */
int Agents::getAgentPower() {
    return this->Power;
}
/**
 *
 * @return dexteritatea agentului
 */
int Agents::getAgentDexterity() {
    return this->Dexterity;
}

/**
 *
 * @return defensiva agentului
 */
int Agents::getAgentDefence() {
    return this->Defence;
}
/**
 * Daca nu am item sau alt agent in pozitiile din imediata vecinatate ma mut random in stanga sau in dreapta (in caz ca nu ies din harta)
 * @direction reprezinta directa si avem urmatoarele codari: 1 = sus ; 2 = stanga ; 3 = jos ; 4 = dreapta
 * Itemele le voi coda pe harta cu valoare < 0, pozitia libera cu 0, pozitiile ocupate de agenti cu numere > 0
 */
void AgentBruce::Move(Map A) {
    int direction = 0;
    //srand(time(nullptr));
    int max_rows = 4;
    int max_cols = 4;
    int moved = 0;
    if (this->positionX - 1 >= 0 && !moved)
        if (A.POZ[this->positionX -1][this->positionY] != 0) {
            this->positionX = this->positionX - 1; //Se duce in sus
            moved = 1;
        }

    if (this->positionY - 1 >= 0 && !moved)
        if (A.POZ[this->positionX][this->positionY -1] != 0 ) {
            this->positionY = this->positionY - 1; //Se duce in sus
            moved = 1;
        }
    if (this->positionX + 1 < max_rows)
        if (A.POZ[this->positionX + 1][this->positionY] != 0) {
            this->positionX = this->positionX + 1;
            moved = 1;
        }
    if (this->positionY + 1 < max_cols)
        if (A.POZ[this->positionX][this->positionY + 1] != 0) {
            this->positionY = this->positionY + 1;
            moved = 1;
        }
    if (moved == 0) {
        direction = rand() % 4 + 1; //Generez numar random intre 1 si 4 ce reprezinta directia
        cout << "Directie: ===== " << direction << "\n";
        if (direction == 1) {
            if (this->positionX - 1 >= 0) {
                this->positionX = this->positionX - 1;
                cout << "\nAgentul se muta DEASUPRA\n";
            }
        }
        else if (direction == 2) {
            if (this->positionY - 1 >= 0) {
                this->positionY = this->positionY - 1;
                cout << "\nAgentul se muta STANGA\n";
            }
        }
        else if (direction == 3) {
            if (this->positionX + 1 < max_rows) {
                this->positionX = this->positionX + 1;
                cout << "\nAgentul se muta JOS\n";
            }
        }
        else if (direction == 4) {
            if (this->positionY + 1 < max_cols) {
                this->positionY = this->positionY + 1;
                cout << "\nAgentul se muta DREAPTA\n";
            }
        }
    }
}
/**
 * Daca nu am item sau alt agent in pozitiile din imediata vecinatate ma mut random in stanga sau in dreapta (in caz ca nu ies din harta)
 * @direction reprezinta directa si avem urmatoarele codari: 1 = sus ; 2 = stanga ; 3 = jos ; 4 = dreapta
 * Itemele le voi coda pe harta cu valoare < 0, pozitia libera cu 0, pozitiile ocupate de agenti cu numere > 0
 */
void AgentKevin::Move(Map A) {
    int direction = 0;
    //srand(time(nullptr));
    int max_rows = 4;
    int max_cols = 4;
    int moved = 0;
    if (this->positionX - 1 >= 0 && !moved)
        if (A.POZ[this->positionX -1][this->positionY] != 0) {
            this->positionX = this->positionX - 1; //Se duce in sus
            moved = 1;
        }

    if (this->positionY - 1 >= 0 && !moved)
        if (A.POZ[this->positionX][this->positionY -1] != 0 ) {
            this->positionY = this->positionY - 1; //Se duce in sus
            moved = 1;
        }
    if (this->positionX + 1 < max_rows)
        if (A.POZ[this->positionX + 1][this->positionY] != 0) {
            this->positionX = this->positionX + 1;
            moved = 1;
        }
    if (this->positionY + 1 < max_cols)
        if (A.POZ[this->positionX][this->positionY + 1] != 0) {
            this->positionY = this->positionY + 1;
            moved = 1;
        }
    if (moved == 0) {
        direction = rand() % 4 + 1; //Generez numar random intre 1 si 4 ce reprezinta directia
        cout << "Directie: ===== " << direction << "\n";
        if (direction == 1) {
            if (this->positionX - 1 >= 0) {
                this->positionX = this->positionX - 1;
                cout << "\nAgentul se muta DEASUPRA\n";
            }
        }
        else if (direction == 2) {
            if (this->positionY - 1 >= 0) {
                this->positionY = this->positionY - 1;
                cout << "\nAgentul se muta STANGA\n";
            }
        }
        else if (direction == 3) {
            if (this->positionX + 1 < max_rows) {
                this->positionX = this->positionX + 1;
                cout << "\nAgentul se muta JOS\n";
            }
        }
        else if (direction == 4) {
            if (this->positionY + 1 < max_cols) {
                this->positionY = this->positionY + 1;
                cout << "\nAgentul se muta DREAPTA\n";
            }
        }
    }
}
/**
 * Daca nu am item sau alt agent in pozitiile din imediata vecinatate ma mut random in stanga sau in dreapta (in caz ca nu ies din harta)
 * @direction reprezinta directa si avem urmatoarele codari: 1 = sus ; 2 = stanga ; 3 = jos ; 4 = dreapta
 * Itemele le voi coda pe harta cu valoare < 0, pozitia libera cu 0, pozitiile ocupate de agenti cu numere > 0
 */
void AgentBond::Move(Map A) {
    int direction = 0;
    //srand(time(nullptr));
    int max_rows = 4;
    int max_cols = 4;
    int moved = 0;
    if (this->positionX - 1 >= 0 && !moved)
        if (A.POZ[this->positionX -1][this->positionY] != 0) {
            this->positionX = this->positionX - 1; //Se duce in sus
            moved = 1;
        }

    if (this->positionY - 1 >= 0 && !moved)
        if (A.POZ[this->positionX][this->positionY -1] != 0 ) {
            this->positionY = this->positionY - 1;
            moved = 1;
        }
    if (this->positionX + 1 < max_rows)
        if (A.POZ[this->positionX + 1][this->positionY] != 0) {
            this->positionX = this->positionX + 1;
            moved = 1;
        }
    if (this->positionY + 1 < max_cols)
        if (A.POZ[this->positionX][this->positionY + 1] != 0) {
            this->positionY = this->positionY + 1;
            moved = 1;
        }
    if (moved == 0) {
        direction = rand() % 4 + 1; //Generez numar random intre 1 si 4 ce reprezinta directia
        if (direction == 1) {
            if (this->positionX - 1 >= 0) {
                this->positionX = this->positionX - 1;
                cout << "\nAgentul se muta DEASUPRA\n";
            }
        }
        else if (direction == 2) {
            if (this->positionY - 1 >= 0) {
                this->positionY = this->positionY - 1;
                cout << "\nAgentul se muta STANGA\n";
            }
        }
        else if (direction == 3) {
            if (this->positionX + 1 < max_rows) {
                this->positionX = this->positionX + 1;
                cout << "\nAgentul se muta JOS\n";
            }
        }
        else if (direction == 4) {
            if (this->positionY + 1 < max_cols) {
                this->positionY = this->positionY + 1;
                cout << "\nAgentul se muta DREAPTA\n";
            }
        }
    }
}