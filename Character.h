#ifndef RPG_POO_CHARACTER_H
#define RPG_POO_CHARACTER_H
#include "string"
#include "Inventory.h"
using namespace std;
class Character{
    Inventory playerInventory;
    string name;
    int level=5;
    int strength=10;
    int defense=10;
    int health=10;
    int money=2500;
public:
    Character(string nameChoose);
    string getName();
    void setLevel(int newStat);
    int getLevel();
    void setStrength(int newStat);
    int getStrength();
    void setDefense(int newStat);
    int getDefense();
    void setHealth(int newStat);
    int getHealth();
    void setMoney(int newStat);
    int getMoney();
    void openShop(int choice);
    void earnMoneyandExp();
    void showInventory();
    void equipStuff(int choice);
    void unequipStuff(int choice);
    void buyWeapon(string weaponName, int weaponPrice, int levelRequierd, int weaponStats);
    void buyArmor(string armorName, int armorPrice, int levelRequierd, int armorStats);
    void buyTalisman(string talismanName, int talismanPrice, int levelRequierd, int talismanStats);
    void getStats();
};
#endif //RPG_POO_CHARACTER_H
