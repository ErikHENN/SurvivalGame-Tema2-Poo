//
// Created by Erik on 4/25/2018.
//

#include <iostream>
#include <vector>
#include "Game.h"
using namespace std;

void Game::run()    {
    int map_rows = 4, map_cols = 4, nr_agents = 7, nr_items = 3;
    cout << "Dati configuratiile hartii, completand informatiile de mai jos: \n";
    /*
    cout << "Numar de linii: "; cin >> map_rows;
    cout << "Numar de coloane: "; cin >> map_cols;
    cout << "Numar de agenti: "; cin >> nr_agents;
    cout << "Numar de iteme: "; cin >> nr_items;
    */
    srand(time(nullptr));
    cout << "Test1\n";
    Map A(map_rows, map_cols);
    A.setTotalNumberOfAgents(nr_agents);
    A.setTotalNumberOfItems(nr_items);
    cout << "Test2\n";
    A.spawnAllAgents(nr_agents);
    cout << "Test3\n";
    A.spawnAllItems(nr_items);
    cout << "Test4\n";

    cout << "Harta la inceputul jocului: \n";
    A.display();
    int nrRunda = 1;

    cout << A.getTotalNrOfAgents();
    while (A.getTotalNrOfAgents() > 1)  {
        cout << "==RUNDA " << nrRunda << "==\n";
        A.playRound();
        nrRunda++;

    }
    cout << "\nHarta la SFARSITUL jocului: \n";
    A.display();
}