#include "Character.h"
#include <iostream>
#include "Item.h"
#include "Inventory.h"
#include "Weapon.h"
#include "Armor.h"
#include "Talisman.h"

Character::Character(string nameChoose) {
    name = nameChoose;
}

string Character::getName() {
    return name;
}
void Character::setStrength(int newStat) {
    strength=newStat;
}

int Character::getStrength() {
    return strength;
}

void Character::setDefense(int newStat) {
    defense=newStat;
}

int Character::getDefense() {
    return defense;
}

void Character::setHealth(int newStat) {
    health=newStat;
}

int Character::getHealth() {
    return health;
}

void Character::setMoney(int newStat) {
    money = newStat;
}

int Character::getMoney() {
    return money;
}

void Character::openShop(int choice) {
    cout<<"::::::::::::::::::::::::::::::::::::::::SHOP::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout<<"1. Epee de la mort (arme) : force + 10, niveau 10, prix 1000"<<endl;
    cout<<"2. Epee de base (arme) : force + 2, niveau 2, prix 200"<<endl;
    cout<<"3. Armure de la mort (armure) : defense + 10, niveau 4, prix 1000"<<endl;
    cout<<"4. Armure de peon (armure) : defense + 1, niveau 1, prix 100"<<endl;
    cout<<"5. Talisman de la mort (talisman) : soins + 10, niveau 3, prix 1000"<<endl;
    cout<<"6. Talisman de la regeneration totale (talisman) : soins + 50, niveau 5, prix 2000"<<endl;
    cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    switch (choice) {
        case 1:
            Character::buyWeapon("Epee de la mort",1000,10,10);
            break;
        case 2:
            Character::buyWeapon("Epee de base",200,2,2);
            break;
        case 3:
            Character::buyArmor("Armure de la mort",1000,4, 10);
            break;
        case 4:
            Character::buyArmor("Armure de base",100, 1, 1);
            break;
        case 5:
            Character::buyTalisman("Talisman de la mort", 1000,3,10);
            break;
        case 6:
            Character::buyTalisman("Talisman de la regeneration totale", 2000,5,50);
            break;
    }
}

void Character::earnMoneyandExp() {
    int addMoney = (rand() % 100) + 20;
    int addExp= (rand() % 2)+1;
    Character::setMoney(money+addMoney);
    Character::setLevel(level+addExp);
    cout <<"You have now "<<money<<" and you are now level "<<level<<endl;
}

void Character::showInventory() {
    playerInventory.showInventory();
}

void Character::equipStuff(int choice) {
    cout << "what do you want equip: ";
    Item *test = playerInventory.getItem(choice);
    cout << test->showName()<<endl;
    Weapon *maybeWeapon = dynamic_cast<Weapon *>(test);
    int test2 = test->getLevel();
    if (level >= test2) {
        playerInventory.equip(choice);
        if (maybeWeapon) {
            Character::setStrength(strength + test->getStat());
        } else {
            Talisman *maybeTal = dynamic_cast<Talisman *>(test);
            if (maybeTal) {
                Character::setHealth(health + test->getStat());
            }else{
                Character::setDefense(defense + test->getStat());
            }
        }
    } else {
        cout << "you are too low level to equip this" << endl;
    }
}

void Character::unequipStuff(int choice) {
    cout << "what do you want unequip: ";
    Item *test = playerInventory.getItem(choice);
    cout << test->showName()<<endl;
    Weapon *maybeWeapon = dynamic_cast<Weapon *>(test);
    if(test->equiped()){
        test->unequip();
    }
    if (maybeWeapon) {
        Character::setStrength(strength - test->getStat());
    } else {
        Talisman *maybeTal = dynamic_cast<Talisman *>(test);
        if (maybeTal) {
            Character::setHealth(health - test->getStat());
        }else{
            Character::setDefense(defense - test->getStat());
        }
    }
}

void Character::setLevel(int newStat) {
    level=newStat;
}

int Character::getLevel(){
    return level;
}

void Character::buyWeapon(string weaponName, int weaponPrice, int levelRequierd, int weaponStats){
    if (Character::getMoney()<weaponPrice){
        cout<<"You don't have enough money"<< endl;
    }else{
        cout<<"You paid "<< weaponPrice <<" golds for "<< weaponName <<endl;
        Character::setMoney(money-weaponPrice);
        cout<<"You have now: "<<Character::getMoney()<< " golds"<< endl;
        Weapon* pointeur = new Weapon(weaponName);
        pointeur->setlevel(levelRequierd);
        pointeur->setStat(weaponStats);
        playerInventory.addStuffToInventory(pointeur);

    }
}

void Character::buyArmor(string armorName, int armorPrice, int levelRequierd, int armorStats) {
    if (Character::getMoney()<armorPrice){
        cout<<"You don't have enough money"<< endl;
    }else{
        cout<<"You paid "<< armorPrice <<" golds for "<< armorName <<endl;
        Character::setMoney(money-armorPrice);
        cout<<"You have now: "<<Character::getMoney()<< " golds"<< endl;
        Armor* pointeur = new Armor(armorName);
        pointeur->setlevel(levelRequierd);
        pointeur->setStat(armorStats);
        playerInventory.addStuffToInventory( pointeur);
    }
}

void Character::buyTalisman(string talismanName, int talismanPrice, int levelRequierd, int talismanStats) {
    if (Character::getMoney()<talismanPrice){
        cout<<"You don't have enough money"<< endl;
    }else{
        cout<<"You paid "<< talismanPrice <<" golds for "<< talismanName <<endl;
        Character::setMoney(money-talismanPrice);
        cout<<"You have now: "<<Character::getMoney()<< " golds"<< endl;
        Talisman* pointeur = new Talisman(talismanName);
        pointeur->setlevel(levelRequierd);
        pointeur->setStat(talismanStats);
        playerInventory.addStuffToInventory( pointeur);
    }
}

void Character::getStats() {
    cout << "::::::::::::::::::::::::::::::::::STATS:::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    cout << "level: "<<level<< " strength: "<< strength << " defence: "<< defense <<" health: "<< health <<" money: "<< money <<endl;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
}


