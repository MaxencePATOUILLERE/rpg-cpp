#include "iostream"
#include "Inventory.h"
#include "vector"
Inventory::Inventory() {
}

void Inventory::addStuffToInventory(Item* itemName) {
    playerInventory.push_back(itemName);
}

void Inventory::showInventory() {
    cout<<":::::::::::::::::::::::::::::::::::INVENTORY::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"[";
    for (int i = 0; i < size(playerInventory); i++){
        cout << playerInventory[i]->showName()<<",";
    }
    cout<<"]"<<endl;
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
}

void Inventory::equip(int choice) {
    playerInventory[choice-1]->equipItem();
}

Item* Inventory::getItem(int choice) {
    return playerInventory[choice-1];
}
