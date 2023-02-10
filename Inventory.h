#ifndef RPG_POO_INVENTORY_H
#define RPG_POO_INVENTORY_H
#include "string"
#include "vector"
#include "Item.h"
using namespace std;

class Inventory {
    vector<Item*> playerInventory;
public:
    Inventory();
    void showInventory();
    void addStuffToInventory(Item* itemName);
    Item* getItem(int choice);
    void equip(int choice);
};
#endif //RPG_POO_INVENTORY_H
