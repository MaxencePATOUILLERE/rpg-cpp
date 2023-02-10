//
// Created by adanl on 2/3/2023.
//

#ifndef EVALUATION_JEU_ITEMS_H
#define EVALUATION_JEU_ITEMS_H

#include <iostream>
#include "Personage.h"
#include <string>

using namespace std;

class Items {
    string m_name;
    int m_level;
    int m_price;
public:
    Items(string name, int level, int price);

    void buy(Personage* personage);

    void equip(Personage* personage);

    int getPriceItem();

    int getLevelItem();
};


#endif //EVALUATION_JEU_ITEMS_H
