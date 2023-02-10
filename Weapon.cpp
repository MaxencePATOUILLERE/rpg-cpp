#include "Weapon.h"
#include "Character.h"
Weapon::Weapon(string weaponName) {
    name=weaponName;
}

string Weapon::showName() {
    return name;
}

void Weapon::setlevel(int addlevel) {
    level=addlevel;
}

void Weapon::setStat(int stat) {
    strength=stat;
}
void Weapon::equipItem() {
    if (!Weapon::equiped()){
        equip=true;
    }
}

bool Weapon::equiped() {
    if (equip=true){
        return true;
    }
    return false;
}

void Weapon::unequip() {
    if (Weapon::equiped()){
        equip=false;
    }
}

int Weapon::getLevel() {
    return level;
}

int Weapon::getStat() {
    return strength;
}
