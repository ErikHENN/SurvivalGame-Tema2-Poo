//
// Created by Erik on 4/24/2018.
//

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