#ifndef RPG_POO_WEAPON_H
#define RPG_POO_WEAPON_H
#include "Item.h"
#include "string"
using namespace std;
class Weapon : public Item{
    string name;
    bool equip=false;
    int level;
    int strength;
public:
    Weapon(string weaponName);
    virtual string showName();
    virtual void setlevel(int addlevel);
    virtual void setStat(int stat);
    virtual void equipItem();
    virtual bool equiped();
    virtual void unequip();
    virtual int getLevel();
    virtual int getStat();
};

#endif //RPG_POO_WEAPON_H
