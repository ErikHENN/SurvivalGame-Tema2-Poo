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

    //this->POZ.resize(4, vector<int>(4));
}

Map::Map(int rows, int cols)  {
    this->POZ = new int*[rows];
    int i, j;
    for(i = 0; i < rows; i++)
        this->POZ[i] = new int[cols];
    for (i=0; i < rows; i++)
        for (j=0; j < cols; j++)
            this->POZ[i][j] = 0;

    //this->POZ.resize(rows, vector<int>(cols));
    nr_rows = rows;
    nr_cols = cols;
}
/*
Map::~Map() {
    for(int i = 0; i < nr_rows; ++i) {
        delete[] this->POZ[i];
    }
    delete[] this->POZ;
}*/


void Map::spawnAllAgents(int nr_of_agents) {
    int i;

    AgentBruce bruce;
    AgentKevin kevin;
    AgentBond bond;
    for (i = 0; i < nr_of_agents / 3; i++) {
        this->agents.push_back(&bruce);
        placeAgent(*agents[i]);
       // cout << "Agent " << i << "= PosX: "<<agents[i]->getPositionX()<< " PosY: " << agents[i]->getPositionY() << "\n";
    }
    for (i = nr_of_agents / 3; i < 2 * nr_of_agents / 3; i++) {
        this->agents.push_back(&kevin);
        placeAgent(*agents[i]);
       // cout << "Agent " << i << "= PosX: "<<agents[i]->getPositionX()<< " PosY: " << agents[i]->getPositionY() << "\n";
    }
    for (i = 2 * nr_of_agents / 3; i < nr_of_agents; i++) {
        this->agents.push_back(&bond);
        placeAgent(*agents[i]);
       // cout << "Agent " << i << "= PosX: "<<agents[i]->getPositionX()<< " PosY: " << agents[i]->getPositionY() << "\n";
    }
}

void Map::spawnAllItems(int nr_of_items) {
    int i;
    Sword sword;
    //cout << "\nA ajuns aici";
    Armor armor;
    Shoes shoes;

    for (i = 0; i < nr_of_items / 3; i++) {
        this->items.push_back(&sword);
        placeItem(*items[i]);
        //cout << "Item " << i << "= SpawnX: "<<items[i]->getPositionX()<< " SpawnY: " << items[i]->getPositionY() << "\n";
    }
    for (i = nr_of_items / 3; i < 2 * nr_of_items / 3; i++) {
        this->items.push_back(&armor);
        placeItem(*items[i]);
        //cout << "Item " << i << "= SpawnX: "<<items[i]->getPositionX()<< " SpawnY: " << items[i]->getPositionY() << "\n";
    }
    for (i = 2 * nr_of_items / 3; i < nr_of_items; i++) {
        this->items.push_back(&shoes);
        placeItem(*items[i]);
       // cout << "Item " << i << "= SpawnX: "<<items[i]->getPositionX()<< " SpawnY: " << items[i]->getPositionY() << "\n";
    }
}
void Map::placeAgent (Agents& Ag, int poz1, int poz2)    {
    srand(time(nullptr));
    int row, col;

    if (poz1 == -1 && poz2 == -1) {
        row = rand() % this->nr_rows;
        col = rand() % this->nr_cols;

        while (this->POZ[row][col] != 0) {
            row = rand() % this->nr_rows;
            col = rand() % this->nr_cols;
        }
        if (this->POZ[row][col] == 0) {//IF-ul nu este neaparat necesar insa il adaug pentru posibil debugging
            Ag.setPosition(row, col);
            cout << "Intra in if (" << row << "|" << col << ")";
        }
        else
            cout << "Nu intra in if";


    }
    else {
        row = poz1;
        col = poz2;
    }
    Ag.setAgentNumber();
    cout << "Ajung in placeAgent(): " <<Ag.getAgentNumber();
    this->POZ[row][col] = Ag.getAgentNumber();
}

void Map::placeItem(Items& item)   {
    srand(time(nullptr));
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


    item.setItemID();
    cout << "placeItem():" << item.getID() << "\n";
    this->POZ[row][col] = item.getID();
}

void Map::Fight (Agents& agent1, Agents& agent2)    {
    float aptitudesAgent1, aptitudesAgent2;
    aptitudesAgent1 = 0.5 * agent1.getAgentPower() + 0.7 * agent1.getAgentDexterity() + 0.35 * agent1.getAgentDefence();
    aptitudesAgent2 = 0.5 * agent2.getAgentPower() + 0.7 * agent2.getAgentDexterity() + 0.35 * agent2.getAgentDefence();

    if (aptitudesAgent1 < aptitudesAgent2) {
        agent1.removeAgent(); //Scot agentul de pe harta
        this->nr_of_agents --;
        cout << "Agentul cu numarul " << agent2.getAgentNumber() << " a castigat lupta";
    }
    else if (aptitudesAgent1 > aptitudesAgent2) {
        agent2.removeAgent();
        this->nr_of_agents --;
        cout << "Agentul cu numarul " << agent1.getAgentNumber() << " a castigat lupta";
    }
    else    {
        agent1.removeAgent();
        agent2.removeAgent();
        this->nr_of_agents = this->nr_of_agents - 2;
        cout << "Intre cei 2 agenti a fost egalitate";
    }

}
Agents& Map::getAgentByID(int id) {
    int i;
    for (i=0; i < this->nr_of_agents; i++)
        if (agents[i]->getAgentNumber() == id)
            return *agents[i];
}

Items& Map::getItemByID(int id)   {
    int i;
    for (i=0; i < this->nr_of_agents; i++)
        if (items[i]->getID() == id)
            return *items[i];
}
void Map::playRound() {
    int i, j, newPositionContent;
    cout << "\n-----------Harta inainte de inceperea rundei: -----------\n";
    i = 0;
    //agents[1]->Move();
    //this->display();
    int posX = agents[i]->getPositionX();
    int posY = agents[i]->getPositionY();
    cout << "---" << agents[i]->getPositionX() << " --- ";
    newPositionContent = this->POZ[posX][posY];
    cout << "Ajung si aici\n";
    cout << "Agentul " << agents[i]->getAgentNumber() << " s-a mutat pe pozitia (" << agents[i]->getPositionX() << ", " << agents[i]->getPositionY() << ") \n";
    cout << newPositionContent << "\n";
    if (newPositionContent > 0) {
        cout << "A cazut pe adversar";
        cout << "\nAgentul cu id " << agents[i]->getAgentNumber() << " s-a luptat cu agentul cu numarul " << getAgentByID(newPositionContent).getAgentNumber();
        Fight(*agents[i], getAgentByID(newPositionContent));
    }
    else if (newPositionContent < 0)    {
        cout << "A cazut pe item";
        Items item = getItemByID(newPositionContent);
        cout << "\nAgentul cu id " << agents[i]->getAgentNumber() << " a colectat itemul cu id-ul " << item.getID();
        agents[i]->collectItem(item);
    }
    else    {
        placeAgent(*agents[i], agents[i]->getPositionX(), agents[i]->getPositionY());
        cout << "\nPozitia a fost libera\n";
    }
    /*
    agents[2]->setPosition(5, 1);
    cout << "---" << (agents[2]->getPositionX());
    for (i=0;i<this->nr_of_agents;i++) {

        cout << "Ajung inainte de Move()\n";
        //agents[i]->Move();
        cout << "Ajung dupa Move()\n";
        int posX = agents[i]->getPositionX();
        int posY = agents[i]->getPositionY();
        cout << "---" << agents[i]->getPositionX() << " --- ";
        newPositionContent = this->POZ[posX][posY];
        cout << "Ajung si aici\n";
        cout << "Agentul " << agents[i]->getAgentNumber() << " s-a mutat pe pozitia (" << agents[i]->getPositionX() << ", " << agents[i]->getPositionY() << ") \n";
        cout << newPositionContent << "\n";
        if (newPositionContent > 0) {
            cout << "\nAgentul cu id " << agents[i]->getAgentNumber() << " s-a luptat cu agentul cu numarul " << getAgentByID(newPositionContent).getAgentNumber();
            Fight(*agents[i], getAgentByID(newPositionContent));
        }
        else if (newPositionContent < 0)    {
            Items item = getItemByID(newPositionContent);
            cout << "\nAgentul cu id " << agents[i]->getAgentNumber() << " a colectat itemul cu id-ul " << item.getID();
            agents[i]->collectItem(item);
        }
        else    {
            placeAgent(*agents[i], agents[i]->getPositionX(), agents[i]->getPositionY());
            cout << "\nPozitia a fost libera\n";
        }

    }
*/
    cout << "\n-----------Harta la finalul rundei: -----------\n";
    this->display();
}

void Map::display() {
    int i, j;
    for (i=0;i<this->nr_rows; i++)  {
        for (j=0;j<this->nr_cols; j++)
            cout << this->POZ[i][j] << " ";
        cout << "\n";
    }
}

int Map::getTotalNrOfAgents() {
    return this->nr_of_agents;
}

void Map::setTotalNumberOfAgents(int nr) {
    this->nr_of_agents = nr;
}

void Map::setTotalNumberOfItems(int nr) {
    this->nr_of_items = nr;
}