//
// Created by adanl on 2/3/2023.
//

#include "Items.h"

#include <utility>

int Items::getPriceItem() {
    return m_price;
}

int Items::getLevelItem() {
    return m_level;
}

void Items::buy(Personage* personage) {
    if (personage->getMoneyPerso() >= this->getPriceItem()) {
        personage->addItem();
    }
}

void Items::equip(Personage* perso) {
    if (perso->getLevelPerso() >= this->getLevelItem()) {
        perso->equipItem();
    }
}

Items::Items(string name, int level, int price) {
    m_name=name;
    m_level=level;
    m_price=price;
}
