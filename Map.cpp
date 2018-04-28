//
// Created by Erik on 4/24/2018.
//
#include <cstdlib>
#include "Map.h"

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

void Map::placeAgent (Agents& Ag)    {
    do {
        Ag.setPosition(rand() %  this->nr_rows, rand() % this->nr_cols);
    } while(this->POZ[Ag.getPositionX()][Ag.getPositionY()] != 0);

    this->POZ[Ag.getPositionX()][Ag.getPositionX()] = Ag.getAttributes().AgentNumber;
}

void Map::Fight (Agents& agent1, Agents& agent2)    {
    float aptitudesAgent1, aptitudesAgent2;
    aptitudesAgent1 = 0.5 * agent1.getAttributes().Power + 0.7 * agent1.getAttributes().Dexterity + 0.35 * agent1.getAttributes().Defence;
    aptitudesAgent2 = 0.5 * agent2.getAttributes().Power + 0.7 * agent2.getAttributes().Dexterity + 0.35 * agent2.getAttributes().Defence;

    if (aptitudesAgent1 < aptitudesAgent2)
        agent1.setID(0); //Scot agentul de pe harta
    else if (aptitudesAgent1 > aptitudesAgent2)
        agent2.setID(0);
    else    {
        agent1.setID(0);
        agent2.setID(0);
    }

}

