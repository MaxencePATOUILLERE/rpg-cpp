#include "Armor.h"
#include "Character.h"
Armor::Armor(string armorName) {
    name=armorName;
}

string Armor::showName() {
    return name;
}

void Armor::setlevel(int addlevel) {
    level=addlevel;
}

void Armor::setStat(int stat) {
    defense=stat;
}
void Armor::equipItem() {
    if (!Armor::equiped()){
        equip=true;
    }
}

bool Armor::equiped() {
    if (equip=true){
        equip=true;
    }
    return false;
}

void Armor::unequip() {
    if (Armor::equiped()){
        equip=false;
    }
}

int Armor::getLevel() {
    return level;
}

int Armor::getStat() {
    return defense;
}
