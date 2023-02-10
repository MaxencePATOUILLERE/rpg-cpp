#include "Talisman.h"
#include "Character.h"
#include "iostream"
Talisman::Talisman(string talismanName) {
    name=talismanName;
}

string Talisman::showName() {
    return name;
}

void Talisman::setlevel(int addlevel) {
    level = addlevel;
}

void Talisman::setStat(int stat) {
    health=stat;
}

void Talisman::equipItem() {
    if (!Talisman::equiped()){
        equip=true;
    }
}

bool Talisman::equiped() {
    if (equip=true){
        return true;
    }
    return false;
}

void Talisman::unequip() {
    if (Talisman::equiped()){
        equip=false;
    }
}

int Talisman::getLevel() {
    return level;
}

int Talisman::getStat() {
    return health;
}



