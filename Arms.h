//
// Created by adanl on 2/3/2023.
//

#ifndef EVALUATION_JEU_ARMS_H
#define EVALUATION_JEU_ARMS_H

#include "Items.h"
#include <iostream>

using namespace std;

class Arms : public Items {
    int m_strength;
public:
    Arms(string name, int strength, int level, int price) : Items(name,level,price){
        m_strength = strength;
    };
};



#endif //EVALUATION_JEU_ARMS_H
