#ifndef RPG_POO_TALISMAN_H
#define RPG_POO_TALISMAN_H
#include "Item.h"
#include "string"
using namespace std;
class Talisman : public Item{
    string name;
    bool equip=false;
    int level;
    int health;
public:
    Talisman(string talismanName);
    virtual string showName();
    virtual void setlevel(int addlevel);
    virtual void setStat(int stat);
    virtual void equipItem();
    virtual bool equiped();
    virtual void unequip();
    virtual int getLevel();
    virtual int getStat();
};

#endif //RPG_POO_TALISMAN_H
