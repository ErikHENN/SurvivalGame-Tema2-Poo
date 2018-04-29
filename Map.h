//
// Created by Erik on 4/24/2018.
//

#ifndef SURVIVALGAME_TEMA2_POO_MAP_H
#define SURVIVALGAME_TEMA2_POO_MAP_H

#include <vector>
#include <ctime>
#include "Agents.h"

using namespace std;

class Map {
public:
    Map();
    Map(int, int);

    void spawnAgent(Agents&, int poz1 = -1, int poz2 = -1);
    void placeAgent(Agents&, int poz1 = -1, int poz2 = -1);
    void removeAgentFromOldPosition(Agents&);
    void placeItem(Items&);
    void spawnAllAgents(int);
    void spawnAllItems(int);
    void Fight(Agents&, Agents&);
    void display();
    int getTotalNrOfAgents();
    int getAgentIndexByID(int);
    int getItemIndexByID(int);
    void playRound();
    void stopRound();

    void setTotalNumberOfAgents(int);
    void setTotalNumberOfItems(int);
    int **POZ;
private:
    //vector < vector<int> > POZ ;
    Agents* *agents;
    Items* *items;
    //vector <Agents*> agents;
    //vector <Items*> items;
    int nr_rows = 15, nr_cols = 15;
    int nr_of_agents, nr_of_items, initial_nr_of_agents;
};


#endif //SURVIVALGAME_TEMA2_POO_MAP_H
