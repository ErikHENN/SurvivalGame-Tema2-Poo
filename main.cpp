#include <iostream>
#include <ctime>
#include "Game.h"
using namespace std;

int main() {
    srand(time(NULL));
    Game g;
    //AgentBruce b;
    //Sword s;
    //AgentBruce bruce;
    /*AgentBruce b;
    cout << b.Power;
    Sword s;
    cout << s.BonusPow;*/
    g.run();
    return 0;
}