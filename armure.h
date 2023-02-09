#ifndef ARMURE
#define ARMURE

#include <string>
#include <iostream>

#include "item.h"

using namespace std;

class Armure : public Item {
public:
    Armure(string name, int lvl, int price, int defense): Item(name, lvl, price){m_Def = defense;}

    void equip(){
        cout << "Equipement de l'armure " << getName() << endl;
    }

    void unequip(){
        cout << "Desequipement de l'armure " << getName() << endl;
    }

    int getDefense(){
        return m_Def;
    }

private:
    int m_Def{0};
};

#endif