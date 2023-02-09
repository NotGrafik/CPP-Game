#ifndef SELLER
#define SELLER

#include <string>
#include <iostream>
#include <vector>

#include "item.h"

using namespace std;

class Seller{
public:
    Seller(string name): m_Name(name){};

    void addItem(Item* item){
        m_Items.push_back(item);
    }

    void rmItem(Item* item){
        for (int i = 0; i < m_Items.size(); i++){
            if (m_Items[i] == item){
                m_Items.erase(m_Items.begin() + i);
            }
        }
    }

    void show(){
        cout << "---- SHOP ----" << endl;
        if (!m_Items.empty()) {
            for(int i = 0; i < m_Items.size(); i++){
                m_Items[i]->show();
                cout << endl;
            }
            cout << "--------------"<< endl;
            return;
        }
        cout << "I dont have more items than that" << endl;
        cout << "--------------" << endl;
    }

private:
    string m_Name{"Seller"};
    vector<Item*> m_Items;
};

#endif