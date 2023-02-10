//
// Created by adanl on 2/3/2023.
//

#ifndef EVALUATION_JEU_PERSONAGE_H
#define EVALUATION_JEU_PERSONAGE_H

#include "Items.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Personage {
    vector<Items*> inventory;
    vector<Items*> equiped;
    static int m_money;
    string m_name;
    int m_level, m_strength, m_defense, m_health;
public:
    Personage(string name, int level, int strength, int defense, int health, int money);

    int getMoneyPerso();

    int getLevelPerso();

    void addItem(Items *);

    void equipItem(Items *);

    void showCaracteristics();

    void showInventory();
};


#endif //EVALUATION_JEU_PERSONAGE_H
