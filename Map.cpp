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


Map::Map() {

    this->POZ = new int*[15];
    int i, j;
    for (i = 0; i < 15; i++)
        this->POZ[i] = new int[15];
    for (i = 0; i < 15; i++)
        for (j = 0; j < 15; j++)
            this->POZ[i][j] = 0;

    this->agents = new Agents*[10];
    this->items = new Items*[3];
}

Map::Map(int rows, int cols) {
    this->POZ = new int*[rows];
    int i, j;
    for (i = 0; i < rows; i++)
        this->POZ[i] = new int[cols];
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            this->POZ[i][j] = 0;

    this->agents = new Agents*[10];//extind cand citesc numarul daca e nevoie
    this->items = new Items*[3];//extind cand citesc numarul
    nr_rows = rows;
    nr_cols = cols;
}

/**
 *
 * @param nr_of_agents  - numarul total de agenti ce trebuie spawnati
 * Metoda spawneaza in mod APROXIMATIV egal agenti de fiecare dintre cele 3 tipuri
 */

void Map::spawnAllAgents(int nr_of_agents) {
    int i;

    for (i = 0; i < nr_of_agents / 3; i++) {
        this->agents[i] = new AgentBruce;
        spawnAgent(*agents[i]);
    }
    for (i = nr_of_agents / 3; i < 2 * nr_of_agents / 3; i++) {
        this->agents[i] = new AgentKevin;
        spawnAgent(*agents[i]);
    }
    for (i = 2 * nr_of_agents / 3; i < nr_of_agents; i++) {
        this->agents[i] = new AgentBond;
        spawnAgent(*agents[i]);
    }
}

/**
 *
 * @param nr_of_items - Numarul total de iteme ce trebuie spawnate
 * Metoda functioneaza pe acelasi principiu ca cea pentru agenti
 */
void Map::spawnAllItems(int nr_of_items) {
    int i;

    for (i = 0; i < nr_of_items / 3; i++) {
        this->items[i] = new Sword;
        placeItem(*items[i]);
    }
    for (i = nr_of_items / 3; i < 2 * nr_of_items / 3; i++) {
        this->items[i] = new Armor;
        placeItem(*items[i]);
    }
    for (i = 2 * nr_of_items / 3; i < nr_of_items; i++) {
        this->items[i] = new Shoes;
        placeItem(*items[i]);
    }
}
/**
 *
 * @param Ag - Agentul ce se spawneaza
 * @param poz1 - Pozitia X pe care se spawneaza (linie)
 * @param poz2 - Pozitia Y pe care se spawneaza  (coloana)
 * Metoda spawneaza pe pozitiile alese de utilizator sau pe pozitii random agentul transmis ca parametru
 */
void Map::spawnAgent(Agents& Ag, int poz1, int poz2) {
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
        }
        else
            cout << "Nu intra in if";


    }
    else {
        row = poz1;
        col = poz2;
        Ag.setPosition(row, col);
    }
    Ag.setAgentNumber();
    //cout << "Ajung in spawnAgent(): " << Ag.getAgentNumber();
    this->POZ[row][col] = Ag.getAgentNumber();
}
/**
 *
 * @param item - itemul ce se spawneaza
 * Metoda spawneaza random itemul pe harta
 */
void Map::placeItem(Items& item) {
    //srand(time(nullptr));
    int row = rand() % this->nr_rows;
    int col = rand() % this->nr_cols;

    while (this->POZ[row][col] != 0) {
        row = rand() % this->nr_rows;
        col = rand() % this->nr_cols;
    }
    if (this->POZ[row][col] == 0) //IF-ul nu este neaparat necesar insa il adaug pentru posibil debugging
        item.spawnItem(row, col);

    else
        throw ("In functia placeItem() ai iesit din while cu row si col nealese cum trebuie");


    item.setItemID();
    this->POZ[row][col] = item.getID();
}
/**
 *
 * @param agent1
 * @param agent2
 * Metoda Fight calculeaza aptitudinele agentilor dupa formula evidenta mai jos. Va castiga agentul care va avea aptitudini mai puternice per total, sau in cazul
 * in care amandoi vor fi la fel de puternici vor muri amandoi.
 * Cand un agent moare ID-ul sau va deveni 0 - pozitie libera - (removeAgent) si va fi plasat pe harta cu acest id.
 *
 */
void Map::Fight(Agents& agent1, Agents& agent2) {
    float aptitudesAgent1, aptitudesAgent2;
    aptitudesAgent1 = 0.5 * agent1.getAgentPower() + 0.7 * agent1.getAgentDexterity() + 0.35 * agent1.getAgentDefence();
    aptitudesAgent2 = 0.5 * agent2.getAgentPower() + 0.7 * agent2.getAgentDexterity() + 0.35 * agent2.getAgentDefence();

    if (aptitudesAgent1 < aptitudesAgent2) {
        agent1.removeAgent(); //Scot agentul de pe harta
        this->nr_of_agents--;
        cout << "Agentul cu numarul " << agent2.getAgentNumber() << " a castigat lupta\n";
        placeAgent(agent2, agent2.getPositionX(), agent2.getPositionY());
    }
    else if (aptitudesAgent1 > aptitudesAgent2) {
        agent2.removeAgent();
        this->nr_of_agents--;
        cout << "Agentul cu numarul " << agent1.getAgentNumber() << " a castigat lupta\n";
        placeAgent(agent1, agent1.getPositionX(), agent1.getPositionY());
    }
    else if (aptitudesAgent1 == aptitudesAgent2){
        agent1.removeAgent();
        agent2.removeAgent();
        this->nr_of_agents = this->nr_of_agents - 2;
        cout << "Intre cei 2 agenti a fost egalitate\n";
        placeAgent(agent1, agent1.getPositionX(), agent1.getPositionY());
    }

}
/**
 *
 * @param id
 * @return - indicele agentului cu id-ul @id in vectorul agents
 */
int Map::getAgentIndexByID(int id) {
    int i;
    for (i = 0; i < this->nr_of_agents; i++) {
        if (this->agents[i]->getAgentNumber() == id) {
            return i;
        }
    }
}
/**
 *
 * @param id
 * @return - Functioneaza la fel ca metoda de mai sus
 */
int Map::getItemIndexByID(int id) {
    int i;
    for (i = 0; i < this->nr_of_items; i++)
        if (items[i]->getID() == id)
            return i;
}
/**
 *
 * @param Ag
 * @param poz1
 * @param poz2
 * Plaseaza agentul @Ag pe pozitiile indicate, se foloseste in mijlocul jocului, nu la spawnare
 */
void Map::placeAgent(Agents& Ag, int poz1, int poz2) {
    Ag.setPosition(poz1, poz2);
    this->POZ[poz1][poz2] = Ag.getAgentNumber();
}
/**
 *
 * @param Ag
 * Sterge agentul @Ag de pe pozitia veche (marcand-o cu 0). Se apeleaza cand se muta agentul
 */
void Map::removeAgentFromOldPosition(Agents& Ag) {
    int poz1, poz2;
    poz1 = Ag.getPositionX();
    poz2 = Ag.getPositionY();
    this->POZ[poz1][poz2] = 0;
}

/**
 *  Metoda playRound() este responsabila de afisarea actiunilor ce se intampla pe harta si desfasurarea jocului.
 *  Astfel pentru fiecare agent in viata (agentNumber != 0) se va apela functia de miscare.
 *  In functie de noua pozitie a agentului acesta are 3 actiuni posibile:
 *  1) Pentru newPosContent > 0 (a intalnit alt agent) acesta se va lupta cu respectivul agent pentru acea pozitie
 *  2) Pentru newPosContent < 0 (a intalnit item) acesta va lua itemul si atributele lui vor deveni mai puternice in functie de tipul de item pe care l-a luat
 *  3) Pentru newPosContent = 0 (spatiu liber) acesta pur si simplu se va misca
 */
void Map::playRound() {
    int i, j, newPositionContent, enemyIndex, prevPositionX, prevPositionY;
    cout << "\n-----------Harta inainte de inceperea rundei: -----------\n";
    i = 0;
    cout << "Nr agenti ramasi: " << nr_of_agents << " || Numar agenti initiali: " << initial_nr_of_agents << "\n";
    for (i = 0; i < initial_nr_of_agents; i++) {
        if (agents[i]->getAgentNumber() != 0) {
            cout << "\n---------\n";
            prevPositionX = agents[i]->getPositionX();
            prevPositionY = agents[i]->getPositionY();
            removeAgentFromOldPosition(*agents[i]);
            agents[i]->Move(*this);
            int posX = agents[i]->getPositionX();
            int posY = agents[i]->getPositionY();
            newPositionContent = this->POZ[posX][posY];
            cout << "Agentul " << agents[i]->getAgentNumber() << " s-a mutat de pe POZITIA (" << prevPositionX  << ", "<< prevPositionY << ") pe pozitia (" << agents[i]->getPositionX() << ", " << agents[i]->getPositionY() << ") \n";
            cout << newPositionContent << "\n";
            if (newPositionContent > 0) {
                cout << "A cazut pe adversar";
                cout << "\nAgentul cu id " << agents[i]->getAgentNumber() << " s-a luptat cu agentul cu numarul " << newPositionContent << "\n";
                enemyIndex = getAgentIndexByID(newPositionContent);
                Fight(*agents[i], *agents[enemyIndex]);
            }
            else if (newPositionContent < 0) {
                cout << "A cazut pe item";
                cout << "\nAgentul cu id " << agents[i]->getAgentNumber() << " a colectat itemul cu id-ul " << newPositionContent << "\n";
                agents[i]->collectItem(*items[getItemIndexByID(newPositionContent)]);
            }
            else {
                placeAgent(*agents[i], posX, posY);
                cout << "\nPozitia a fost libera\n";
            }
            placeAgent(*agents[i], agents[i]->getPositionX(), agents[i]->getPositionY());
        }
    }
    cout << "\n-----------AU mai ramas: " << nr_of_agents << " agenti ------------\n";
    cout << "\n-----------Harta la finalul rundei: -----------\n";
    this->display();
}

/**
 * Afisez harta
 */
void Map::display() {
    int i, j;
    for (i = 0; i < this->nr_rows; i++) {
        for (j = 0; j < this->nr_cols; j++)
            cout << this->POZ[i][j] << " ";
        cout << "\n";
    }
}

int Map::getTotalNrOfAgents() {
    return this->nr_of_agents;
}

void Map::setTotalNumberOfAgents(int nr) {
    this->nr_of_agents = nr;
    this->initial_nr_of_agents = nr;
    this->agents = new Agents*[nr];
}

void Map::setTotalNumberOfItems(int nr) {
    this->nr_of_items = nr;
    this->items = new Items*[nr];
}