#include <iostream>
#include "string"
#include "Character.h"
using namespace std;

int main() {
    bool finish = false;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    Character player("Maxou");
    cout << "Good luck for your adventure "<< player.getName() <<" !!"<<endl;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    player.getStats();
    int choice = 0;
    for (int i = 0; i < 10;i++){
        player.earnMoneyandExp();
    }
    player.openShop(6);
    player.showInventory();
    player.equipStuff(1);
    player.getStats();
    player.unequipStuff(1);
    player.getStats();
    player.openShop(1);
    player.equipStuff(1);
    player.equipStuff(2);
    player.showInventory();
    player.getStats();
    player.unequipStuff(1);
    player.unequipStuff(2);
    player.openShop(1);
    player.getStats();
    return 0;
}
