//
// Created by Erik on 4/24/2018.
//

#ifndef SURVIVALGAME_TEMA2_POO_MAP_H
#define SURVIVALGAME_TEMA2_POO_MAP_H

#include <vector>
#include "Agents.h"
using namespace std;

class Map {
public:
    Map();
    Map(int, int);
    ~Map();
    void placeAgent(Agents&);
    void Fight (Agents&, Agents&);

    int **POZ;
    vector <Agents> agents;
    int nr_rows = 15, nr_cols = 15;
};


#endif //SURVIVALGAME_TEMA2_POO_MAP_H
