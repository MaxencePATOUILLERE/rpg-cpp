//
// Created by adanl on 2/3/2023.
//

#ifndef EVALUATION_JEU_TALISMAN_H
#define EVALUATION_JEU_TALISMAN_H

#include "Items.h"
#include <iostream>

using namespace std;

class Talisman : public Items {
    int m_health;
public:
    Talisman(string name, int health, int level, int price) : Items(name,level,price){
        m_health = health;
    };
};


#endif //EVALUATION_JEU_TALISMAN_H
