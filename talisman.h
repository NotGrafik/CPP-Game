#ifndef TALISMAN
#define TALISMAN

#include <string>
#include <iostream>

#include "item.h"

using namespace std;

class Talisman : public Item {
public:
    Talisman(string name, int lvl, int price, int health): Item(name, lvl, price){ m_Health = health; }

    void equip(){
        cout << "Equipement du talisman " << getName() << endl;
    }

    void unequip(){
        cout << "Desequipement du talisman " << getName() << endl;
    }

    int getHealth(){
        return m_Health;
    }

private:
    int m_Health{0};
};

#endif