//
// Created by Erik on 4/24/2018.
//
#include <iostream>
#include <cstdlib>
#include "Items.h"
#include "Map.h"
using namespace std;

/**
 * Aloc memorie pentru dimensiunea minima a hartii, adica 15 x 15
 */


Map::Map()  {
    this->POZ = new int*[15];
    int i, j;
    for(i = 0; i < 15; i++)
        this->POZ[i] = new int[15];
    for (i=0; i < 15; i++)
        for (j=0; j < 15; j++)
            this->POZ[i][j] = 0;

}

Map::Map(int rows, int cols)  {
    this->POZ = new int*[rows];
    int i, j;
    for(i = 0; i < rows; i++)
        this->POZ[i] = new int[cols];
    for (i=0; i < rows; i++)
        for (j=0; j < cols; j++)
            this->POZ[i][j] = 0;

    nr_rows = rows;
    nr_cols = cols;
}

Map::~Map() {
    for(int i = 0; i < nr_rows; ++i) {
        delete[] this->POZ[i];
    }
    delete[] this->POZ;
}


void Map::spawnAllAgents() {
    int i;
    cout << "Alegeti numarul de agenti de pe harta: ";
    cin >> nr_of_agents;
    AgentBruce bruce;
    AgentKevin kevin;
    AgentBond bond;
    for (i = 0; i < nr_of_agents / 3; i++) {
        this->agents.push_back(&bruce);
        placeAgent(*agents[i]);
    }
    for (i = nr_of_agents / 3; i < 2 * nr_of_agents / 3; i++) {
        this->agents.push_back(&kevin);
        placeAgent(*agents[i]);
    }
    for (i = 2 * nr_of_agents / 3; i < nr_of_agents; i++) {
        this->agents.push_back(&bond);
        placeAgent(*agents[i]);
    }
}

void Map::spawnAllItems() {
    int i;
    cout << "Alegeti numarul de iteme de pe harta: ";
    cin>>nr_of_items;
    Sword sword;
    Armor armor;
    Shoes shoes;
    for (i = 0; i < nr_of_items; i++) {
        this->items.push_back(&sword);
        placeItem(*items[i]);
    }
    for (i = nr_of_items / 3; i < 2 * nr_of_items / 3; i++) {
        this->items.push_back(&armor);
        placeItem(*items[i]);
    }
    for (i = 2 * nr_of_items / 3; i < nr_of_items; i++) {
        this->items.push_back(&shoes);
        placeItem(*items[i]);
    }
}
void Map::placeAgent (Agents& Ag, int poz1, int poz2)    {
    int row, col;
    if (poz1 == -1 && poz2 == -1) {
        row = rand() % this->nr_rows;
        col = rand() % this->nr_cols;

        while (this->POZ[row][col] != 0) {
            row = rand() % this->nr_rows;
            col = rand() % this->nr_cols;
        }
        if (this->POZ[row][col] == 0) //IF-ul nu este neaparat necesar insa il adaug pentru posibil debugging
            Ag.setPosition(row, col);
        else
            throw ("In functia placeAgent() ai iesit din while cu row si col nealese cum trebuie");


    }
    else {
        row = poz1;
        col = poz2;
    }
    this->POZ[row][col] = Ag.getAttributes().AgentNumber;
}

void Map::placeItem(Items& item)   {
    int row = rand() %  this->nr_rows;
    int col = rand() % this->nr_cols;

    while (this->POZ[row][col] != 0) {
        row = rand() %  this->nr_rows;
        col = rand() % this->nr_cols;
    }
    if (this->POZ[row][col] == 0) //IF-ul nu este neaparat necesar insa il adaug pentru posibil debugging
        item.spawnItem(row, col);
    else
        throw ("In functia placeItem() ai iesit din while cu row si col nealese cum trebuie");



    this->POZ[row][col] = item.getID();
}

void Map::Fight (Agents& agent1, Agents& agent2)    {
    float aptitudesAgent1, aptitudesAgent2;
    aptitudesAgent1 = 0.5 * agent1.getAttributes().Power + 0.7 * agent1.getAttributes().Dexterity + 0.35 * agent1.getAttributes().Defence;
    aptitudesAgent2 = 0.5 * agent2.getAttributes().Power + 0.7 * agent2.getAttributes().Dexterity + 0.35 * agent2.getAttributes().Defence;

    if (aptitudesAgent1 < aptitudesAgent2) {
        agent1.removeAgent(); //Scot agentul de pe harta
        cout << "Agentul cu numarul " << agent2.getAttributes().AgentNumber << " a castigat lupta";
    }
    else if (aptitudesAgent1 > aptitudesAgent2) {
        agent2.removeAgent();
        cout << "Agentul cu numarul " << agent1.getAttributes().AgentNumber << " a castigat lupta";
    }
    else    {
        agent1.removeAgent();
        agent2.removeAgent();
        cout << "Intre cei 2 agenti a fost egalitate";
    }

}
Agents& Map::getAgentByID(int id) {
    int i;
    for (i=0; i < this->nr_of_agents; i++)
        if (agents[i]->getAttributes().AgentNumber == id)
            return *agents[i];
}

Items& Map::getItemByID(int id)   {
    int i;
    for (i=0; i < this->nr_of_agents; i++)
        if (items[i]->getAttributes().itemID == id)
            return *items[i];
}
void Map::playRound() {
    int i, j, newPositionContent;
    cout << "\n-----------Harta inainte de inceperea rundei: -----------\n";
    for (i=0;i<this->nr_rows; i++)  {
        for (j=0;j<this->nr_cols; j++)
            cout << this->POZ[i][j];
        cout << "\n";
    }
    for (i=0;i<this->nr_of_agents;i++) {
        agents[i]->Move();
        newPositionContent = this->POZ[agents[i]->getPositionX()][agents[i]->getPositionY()];
        cout << "Agentul " << agents[i]->getAttributes().AgentNumber << " s-a mutat pe pozitia (" << agents[i]->getPositionX() << ", " << agents[i]->getPositionY() << ") \n";

        if (newPositionContent > 0) {
            cout << "\nAgentul cu id " << agents[i]->getAttributes().AgentNumber << " s-a luptat cu agentul cu numarul " << getAgentByID(newPositionContent).getAttributes().AgentNumber;
            Fight(*agents[i], getAgentByID(newPositionContent));
        }
        else if (newPositionContent < 0)    {
            Items item = getItemByID(newPositionContent);
            cout << "\nAgentul cu id " << agents[i]->getAttributes().AgentNumber << " a colectat itemul \'" << item.getAttributes().itemName << "\' cu id-ul " << item.getAttributes().itemID;
            agents[i]->collectItem(item);
        }
        else    {
            placeAgent(*agents[i], agents[i]->getPositionX(), agents[i]->getPositionY());
            cout << "\nPozitia a fost libera";
        }

    }

    cout << "\n-----------Harta la finalul rundei: -----------\n";
    for (i=0;i<this->nr_rows; i++)  {
        for (j=0;j<this->nr_cols; j++)
            cout << this->POZ[i][j];
        cout << "\n";
    }
}
