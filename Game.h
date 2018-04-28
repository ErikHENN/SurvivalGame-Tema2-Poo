//
// Created by Erik on 4/25/2018.
//

#ifndef SURVIVALGAME_TEMA2_POO_GAME_H
#define SURVIVALGAME_TEMA2_POO_GAME_H
#include <vector>
#include "Map.h"

class Game {
public:
    void run(int map_rows, int map_cols, int nr_agents, int nr_items);


    friend class Agents;
    Map A;
};


#endif //SURVIVALGAME_TEMA2_POO_GAME_H
