//
// Created by adanl on 2/3/2023.
//

#ifndef EVALUATION_JEU_ARMOR_H
#define EVALUATION_JEU_ARMOR_H

#include "Items.h"
#include <iostream>

using namespace std;

class Armor : public Items {
    int m_defense;
public:
    Armor(string name, int defense, int level, int price) : Items(name,level,price){
        m_defense = defense;
    };

};


#endif //EVALUATION_JEU_ARMOR_H
