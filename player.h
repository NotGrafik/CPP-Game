#ifndef PLAYER
#define PLAYER

#include <string>
#include <iostream>
#include <vector>

#include "item.h"

using namespace std;

class Player {
public:

    vector<Item*> m_Inventory;

    Player(string name): m_Name(name){};

    void setStrength(int strength){
        m_Strenght += strength;
    }

    void setDefense(int defense){
        m_Defense += defense;
    }

    void setHealth(int health){
        m_Health += health;
    }

    void buyItem(Item* item){
        if (item->getPrice() <= m_Money){
            m_Money -= item->getPrice();
            m_Inventory.push_back(item);
            cout << "You bought " << item->getName() << endl;
        }
        else {
            cout << "Pas assez d'argent" << endl;
        }
    }

    void sellItem(Item* item){
        for (int i = 0; i < m_Inventory.size(); i++){
            if (m_Inventory[i] == item){
                m_Money += item->getPrice();
                m_Inventory.erase(m_Inventory.begin() + i);
                cout << "You sold " << item->getName() << endl;
            }
        }
    }

    void equip(Item* ITEMS){
        if(ITEMS->getLevel() <= m_level){
            ITEMS->equip();
        }
        else{
            cout << "Niveau trop faible" << endl;
        }
    }

    void unequip(Item* ITEMS){
        if(m_Inventory.empty()){
            cout << "Vous n'avez pas d'item" << endl;
        }
        else{https://github.com/NotGrafik/CPP-Game.git
            ITEMS->unequip();
        }
    }

    /*void showEquipped(){
        for (int i = 0; i < m_Inventory.size(); i++){
            if (m_Inventory[i]->getEquipped()){
                m_Inventory[i]->show();
            }
        }
    }*/

    void showInventory(){
        cout << "---- INVENTORY ----" << endl;
        if (!m_Inventory.empty()) {
            for(int i = 0; i < m_Inventory.size(); i++){
                m_Inventory[i]->show();
                cout << endl;
            }
            cout << "--------------"<< endl;
            return;
        }
        cout << "I dont have more items than that" << endl;
        cout << "--------------" << endl;
    }

    void showStats(){
        cout << "---- STATS ----" << endl;
        cout << "Level: " << m_level << endl;
        cout << "Health: " << m_Health << endl;
        cout << "Strength: " << m_Strenght << endl;
        cout << "Defense: " << m_Defense << endl;
        cout << "Money: " << m_Money << endl;
        cout << "---------------" << endl;
    }

private:
    string m_Name{"Player"};
    int m_Strenght{10};
    int m_Defense{10};
    int m_Health{10};
    int m_level{5};
    int m_Money{ 2500 };

};

#endif