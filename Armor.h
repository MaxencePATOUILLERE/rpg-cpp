#ifndef RPG_POO_ARMOR_H
#define RPG_POO_ARMOR_H
#include "Item.h"
#include "string"
using namespace std;
class Armor : public Item{
    string name;
    bool equip=false;
    int level;
    int defense;
public:
    Armor(string armorName);
    virtual string showName();
    virtual void setlevel(int addlevel);
    virtual void setStat(int stat);
    virtual void equipItem();
    virtual bool equiped();
    virtual void unequip();
    virtual int getLevel();
    virtual int getStat();
};

#endif //RPG_POO_ARMOR_H
