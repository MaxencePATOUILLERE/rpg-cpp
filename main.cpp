#include "Personage.h"
#include "Items.h"
#include "Arms.h"
#include "Armor.h"
#include "Talisman.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Personage *perso = new Personage("Ichigo", 5, 10, 10, 10, 2500);

    Items *arm1 = new Arms("Death sword", 10, 10, 1000);
    Items *arm2 = new Arms("Basic sword", 2, 2, 200);
    Items *armor1 = new Armor("Death armor", 10, 4, 1000);
    Items *armor2 = new Armor("Peon armor", 1, 1, 100);
    Items *talisman1 = new Talisman("Death talisman", 10, 3, 1000);
    Items *talisman2 = new Talisman("Talisman of the total regeneration", 50, 5, 2000);

    perso->showCaracteristics();

    cout << "We enter in the shop to buy items..." << endl;

    arm1->buy(perso);
    armor2->buy(perso);
    talisman1->buy(perso);

    cout << "Let's go to equip my new Item!" << endl;

    arm1->equip(perso);
    armor2->equip(perso);
    talisman1->equip(perso);

    perso->showCaracteristics();
    perso->showInventory();
    return 0;
}
