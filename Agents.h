//
// Created by Erik on 4/23/2018.
//
#ifndef SURVIVALGAME_TEMA2_POO_AGENTS_H
#define SURVIVALGAME_TEMA2_POO_AGENTS_H


class Agents {
public:
    Agents();
    Agents(int, int, int);
    virtual void Move();
    void Fight(Agents);

    int positionX, positionY;
    int Power, Dexterity, Defence;
    int AgentNumber;

};

class AgentBruce: public Agents {
public:
    AgentBruce() : Agents(Power, Dexterity, Defence) { }
    void Move() {};

    int Power = 100;
    int Dexterity = 40;
    int Defence = 10;
};

class AgentKevin: public Agents {
public:
    AgentKevin() : Agents(Power, Dexterity, Defence) { }
    void Move() {};

    int Power = 50;
    int Dexterity = 1;
    int Defence = 100;
};

class AgentBond: public Agents  {
public:
    AgentBond() : Agents(Power, Dexterity, Defence) { }
    void Move();

    int Power = 20;
    int Dexterity = 100;
    int Defence = 30;
};


#endif //SURVIVALGAME_TEMA2_POO_AGENTS_H
