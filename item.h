#ifndef ITEM
#define ITEM

#include <string>
#include <iostream>

using namespace std;

class Item {
public:
    bool equipped{false};

    Item(string name, int lvl, int price): m_Name(name), m_Level(lvl), m_Price(price) {}

    virtual void equip() = 0;

    virtual void unequip() = 0;

    string getName(){
        return m_Name;
    }

    bool getEquipped(){
        return equipped;
    }


    int getLevel(){
        return m_Level;
    }

    int getPrice(){
        return m_Price;
    }

    void show(){
        cout << "Name: " << m_Name << endl;
        cout << "Level: " << m_Level << endl;
        cout << "Price: " << m_Price << endl;
    }

private:
    string m_Name{"Item"};
    int m_Level{1};
    int m_Price{0};
};

#endif
