#ifndef RPG_POO_ITEM_H
#define RPG_POO_ITEM_H
#include "Item.h"
#include "string"


using namespace std;

class Item{
public:
    virtual string showName()=0;
    virtual void setlevel(int addlevel)=0;
    virtual void setStat(int stat)=0;
    virtual void equipItem()=0;
    virtual bool equiped()=0;
    virtual void unequip()=0;
    virtual int getLevel()=0;
    virtual int getStat()=0;
};

#endif //RPG_POO_ITEM_H
