//
// Created by Erik on 4/24/2018.
//

#ifndef SURVIVALGAME_TEMA2_POO_MAP_H
#define SURVIVALGAME_TEMA2_POO_MAP_H


class Map {
public:
    Map();
    Map(int, int);
    ~Map();

    int **POZ;
    int nr_rows = 15, nr_cols = 15;
};


#endif //SURVIVALGAME_TEMA2_POO_MAP_H
