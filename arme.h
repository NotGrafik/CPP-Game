#ifndef ARME
#define ARME

#include <string>
#include <iostream>

#include "item.h"

using namespace std;

class Arme : public Item {
public:
    Arme(string name, int lvl, int price, int strenght): Item(name, lvl, price){m_Strenght = strenght;}

    void equip(){
        Item::equipped = true;
        cout << "Equipement de l'arme " << getName() << endl;
    }

    void unequip(){
        Item::equipped = false;
        cout << "Desequipement de l'arme " << getName() << endl;
    }

    int getStrength(){
        return m_Strenght;
    }

private:
    int m_Strenght{0};
};

#endif