//
// Created by Erik on 4/23/2018.
//
#ifndef SURVIVALGAME_TEMA2_POO_AGENTS_H
#define SURVIVALGAME_TEMA2_POO_AGENTS_H

#include "Items.h"
#include <cstdlib>

class Map;

class Agents {
public:
    Agents();
    Agents(int, int, int);
    virtual void Move(Map) = 0;
    int getPositionX();
    int getPositionY();
    void setPosition(int, int);
    void setID(int);
    void removeAgent();
    void collectItem(Items);
    void setAgentNumber();

    int getAgentNumber();
    int getAgentPower();
    int getAgentDexterity();
    int getAgentDefence();
    friend class Map;
protected:
    int positionX, positionY;
private:
    int Power, Dexterity, Defence;
    int AgentNumber = 0;
};

class AgentBruce: public Agents {
public:
    AgentBruce() : Agents(100, 40, 10) { }
    void Move(Map);

};

class AgentKevin: public Agents {
public:
    AgentKevin() : Agents(50, 1, 100) { }
    void Move(Map);


};

class AgentBond: public Agents  {
public:
    AgentBond() : Agents(20, 100, 30) { }
    void Move(Map);

};


#endif //SURVIVALGAME_TEMA2_POO_AGENTS_H
