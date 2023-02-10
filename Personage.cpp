//
// Created by adanl on 2/3/2023.
//

#include "Personage.h"
#include "Items.h"
#include <string>

using namespace std;

Personage::Personage(string name, int level, int strength, int defense, int health, int money) {
    m_money = money, m_name = name, m_level = level, m_strength = strength, m_defense = defense, m_health = health;
}

int Personage::getMoneyPerso() {
    return m_money;
}

int Personage::getLevelPerso() {
    return m_level;
}

void Personage::addItem(Items *item) {
    inventory.push_back(item);
}

void Personage::equipItem(Items *item) {
    equiped.push_back(item);
}

void Personage::showCaracteristics() {
    cout << "Name: " << m_name << endl;
    cout << "Level: " << m_level << endl;
    cout << "Money: " << m_money << endl;
    cout << "Strength: " << m_strength << endl;
    cout << "Defense: " << m_defense << endl;
    cout << "Health: " << m_health << endl;
}

void Personage::showInventory() {
    cout << "Inventory: " << endl;
    for (int i = 0; i < size(inventory); i++) {
        cout << inventory[i] << ", ";
    }
}