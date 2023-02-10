#include <iostream>
#include <vector>
using namespace std;
class Stat {
    int m_level = 0;
    int m_force = 0;
    int m_defense = 0;
    int m_soin = 0;
public:
    Stat(int level, int force, int defense, int soin)
    :m_level(level), m_force(force), m_defense(defense), m_soin(soin) {
    }
    void show() {
        cout << m_level << ", " << m_force << ", " << m_defense << ", " << m_soin << endl;
    }
    int getLevel() {
        return m_level;
    }
    void add(Stat* stat) {
        m_force += stat->m_force;
        m_defense += stat->m_defense;
        m_soin += stat->m_soin;
    }
};
class Item {
    string m_name;
    int price;
    Stat* statP = nullptr;
public:
    Item(string name, int pognon, int level, int force, int defense, int soin)
    :statP(new Stat(level, force, defense, soin)), price(pognon), m_name(name) {
    }
    int getPrice() {
        return price;
    }
    void show() {
        cout << m_name << ", " << price << endl;
        statP->show();
    }
    int getLevel() {
        return statP->getLevel();
    }
    Stat* getStat(){
        return statP;
    }
};

class Epee: public Item {
public:
    Epee(string name, int level, int pognon, int force)
    :Item(name, level, pognon, force, 0, 0) {
    }
};

class Armure: public Item {
public:
    Armure(string name, int level, int pognon, int defense)
    :Item(name, level, pognon, 0, defense, 0) {
    }
};

class Talisman: public Item {
public:
    Talisman(string name, int level, int pognon, int soin)
    : Item(name, level, pognon, 0, 0, soin) {

    }
};

class Vendeur {
    string m_name;
    vector<Item*>inventaire;
public:
    Vendeur(string name)
    :m_name(name) {
    }
    void addItem(Item *item) {
        inventaire.push_back(item);
    }

};
class Joueur {
    Stat* statP = nullptr;
    vector<Item*>inventaire;
    string m_name;
    int m_pognon;
    Epee* rightHand = nullptr;
    Armure* m_chest = nullptr;
    Talisman* m_neck = nullptr;
public:
    Joueur(string name, int level, int pognon , int force, int defense, int soin)
    : statP(new Stat(level, force, defense, soin)), m_name(name), m_pognon(pognon){
    }
    void buyItem(Item *item) {
        if (m_pognon > item->getPrice()){
            inventaire.push_back(item);
            m_pognon-=item->getPrice();
            return;
        }
        cout << "pas assez de bling !!!" << endl;
    }
    void equip(Epee* epee) {
        if (rightHand == nullptr && canEquip(epee)) {
            rightHand = epee;
        }
    }
    void equip(Armure* chest) {
        if (m_chest == nullptr && canEquip(chest)) {
            m_chest = chest;
        }
    }
    void equip(Talisman* neck) {
        if (m_neck == nullptr && canEquip(neck)) {
            m_neck = neck;
        }
    }
    bool canEquip(Item* item) {
        if (item->getLevel() < statP->getLevel()) {
            return true;
        }
    }
    void displayInventory() {
        for (auto item : inventaire) {
            item->show();
            cout << "eq : " << (canEquip(item) ? "equipable" : "non equipable");
            cout << endl;
        }
    }
    void displayStat() {
        Stat stat(0, 0, 0, 0);
        stat.add(this->statP);
        if (rightHand != nullptr) stat.add(rightHand->getStat());
        if (m_chest != nullptr) stat.add(m_chest->getStat());
        if (m_neck != nullptr) stat.add(m_neck->getStat());
        stat.show();
    }
};
int main()
{
    Epee* epeeDeLaMort = new Epee("Epee de la mort", 10, 1000, 10);
    Epee* epeeDuDebutant = new Epee("Epee du debutant", 1, 10, 5);

    Armure* armureDeLaMort = new Armure("Armure de la mort", 10, 1000, 10);
    Armure* armureDuDebutant = new Armure("Armure du debutant", 1, 10, 5);

    Talisman* talismanDeLaMort = new Talisman("Talisman de la mort", 10, 1000, 10);
    Talisman* talismanDuDebutant = new Talisman("Talisman de regen", 1, 10, 5);

    Vendeur* joLeVendeur = new Vendeur("Jo le vendeur");

    joLeVendeur->addItem(epeeDeLaMort);
    joLeVendeur->addItem(epeeDuDebutant);

    joLeVendeur->addItem(armureDeLaMort);
    joLeVendeur->addItem(armureDuDebutant);

    joLeVendeur->addItem(talismanDeLaMort);
    joLeVendeur->addItem(talismanDuDebutant);

    Joueur* arthur = new Joueur("Arthur le modeste", 9, 2500, 10, 10, 10);

    arthur->buyItem(epeeDuDebutant);
    arthur->buyItem(armureDuDebutant);
    arthur->buyItem(talismanDuDebutant);
    arthur->buyItem(talismanDeLaMort);

    arthur->equip(epeeDuDebutant);
    arthur->equip(armureDuDebutant);
    arthur->equip(talismanDuDebutant);
    arthur->equip(talismanDeLaMort);

    arthur->displayInventory();
    arthur->displayStat();

    return 0;
}
