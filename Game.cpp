//
// Created by Erik on 4/25/2018.
//

#include <iostream>
#include <vector>
#include "Game.h"
using namespace std;

void Game::run()    {
    int map_rows = 15, map_cols = 15, nr_agents = 7, nr_items = 3, optiune;
    cout << "Dati configuratiile hartii, completand informatiile de mai jos: \n";

    cout << "Numar de linii: "; cin >> map_rows;
    cout << "Numar de coloane: "; cin >> map_cols;
    cout << "Numar de agenti: "; cin >> nr_agents;
    cout << "Numar de iteme: "; cin >> nr_items;


    Map A(map_rows, map_cols);
    A.setTotalNumberOfAgents(nr_agents);
    A.setTotalNumberOfItems(nr_items);

    A.spawnAllAgents(nr_agents);

    A.spawnAllItems(nr_items);


    cout << "Harta la inceputul jocului: \n";
    A.display();
    int nrRunda = 1, rundaOprire;
    cout << "Doriti sa rulati jocul pana la final sau pana la o anumita runda? [1 = final / 2 = runda";
    cin >> optiune;
    if (optiune == 2)   {
        cout << "Selectati runda de oprire: ";
        cin >> rundaOprire;
        while (nrRunda <= rundaOprire)  {
            cout << "==RUNDA " << nrRunda << "==\n";
            A.playRound();
            nrRunda++;
        }
    }
    else {
        while (A.getTotalNrOfAgents() > 0) {
            cout << "==RUNDA " << nrRunda << "==\n";
            A.playRound();
            nrRunda++;
        }
    }
    cout << "\nHarta la SFARSITUL jocului: \n";
    A.display();
}