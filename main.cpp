#include <iostream>
#include <string>
#include <vector>

#include "item.h"
#include "arme.h"
#include "armure.h"
#include "talisman.h"
#include "player.h"
#include "seller.h"

using namespace std;

int main() {

    bool talismanEquipped = false;
    bool talismanEquipped2 = false;
    bool armureEquipped = false;
    bool armureEquipped2 = false;
    bool armeEquipped = false;
    bool armeEquipped2 = false;

    Seller seller("Seller");
    Arme* epeeBase = new Arme("Epee de base (1)", 2, 200, 2);
    Arme* epeeMort = new Arme("Epee de la Mort (2)", 10, 1000, 10);

    Armure* armureBase = new Armure("Armure de peon (3)", 1, 100, 1);
    Armure* armureMort = new Armure("Armure de la Mort (4)", 4, 1000, 10);

    Talisman* talismanRegen = new Talisman("Talisman de la regeneration totale (5)", 5, 2000, 50);
    Talisman* talismanMort = new Talisman("Talisman de la Mort (6)", 3, 1000, 10);

    seller.addItem(epeeBase);
    seller.addItem(epeeMort);

    seller.addItem(armureBase);
    seller.addItem(armureMort);

    seller.addItem(talismanRegen);
    seller.addItem(talismanMort);

    cout << " * Welcome To The CPP GAME * " << endl << "What's Your Name ?" << endl;
    string Name;
    getline(cin, Name);
    Player player(Name);

    cout << "Okay " << Name << " nice to met U\n" << endl;

    cout << "These are your Stats:" << endl;
    player.showStats();

    cout << "\nWhat do you want to do " << Name << " ?" << endl;
    cout << "- Show Inventory (I)\n- Show Stats(Z)\n- Buy equipment (B)\n- Sell equipment (S) \n- Equip Item (E)\n- Unequip Item (U)\n- Exit Game (exit)" << endl;
    string VALUE;
    getline(cin, VALUE);
    while(VALUE != "exit"){
        if(VALUE == "I" || VALUE == "i"){
            player.showInventory();
        }
        else if(VALUE == "Z" || VALUE == "z"){
            cout << "These are your Stats" << endl;
            player.showStats();
        }
        else if(VALUE == "B" || VALUE == "b"){
            seller.show();
            cout << "What do you want to buy ?" << endl;
            string VALUE;
            getline(cin, VALUE);
            if(VALUE == "Epee de base" || VALUE == "1"){
                player.buyItem(epeeBase);
                seller.rmItem(epeeBase);
            }
            else if(VALUE == "Epee de la Mort" || VALUE == "2"){
                player.buyItem(epeeMort);
                seller.rmItem(epeeMort);
            }
            else if(VALUE == "Armure de peon" || VALUE == "3"){
                player.buyItem(armureBase);
                seller.rmItem(armureBase);
            }
            else if(VALUE == "Armure de la Mort" || VALUE == "4"){
                player.buyItem(armureMort);
                seller.rmItem(armureMort);
            }
            else if(VALUE == "Talisman de la regeneration totale" || VALUE == "5"){
                player.buyItem(talismanRegen);
                seller.rmItem(talismanRegen);
            }
            else if(VALUE == "Talisman de la Mort" || VALUE == "6"){
                player.buyItem(talismanMort);
                seller.rmItem(talismanMort);
            }
            else if(VALUE == "exit"){
                break;
            }
            else{
                cout << "This item doesn't exist" << endl;
            }
        }
        else if(VALUE == "S" || VALUE == "s"){
            player.showInventory();
            cout << "What do you want to sell ?" << endl;
            string VALUE;
            getline(cin, VALUE);
            if(VALUE == "Epee de base" || VALUE == "1"){
                if (armeEquipped == true){
                    player.unequip(epeeBase);
                    player.setStrength(-epeeBase->getStrength());
                    armeEquipped = false;
                }
                player.sellItem(epeeBase);
                seller.addItem(epeeBase);
            }
            else if(VALUE == "Epee de la Mort"  || VALUE == "2"){
                if (armeEquipped2 == true){
                    player.unequip(epeeMort);
                    player.setStrength(-epeeMort->getStrength());
                    armeEquipped2 = false;
                }
                player.sellItem(epeeMort);
                seller.addItem(epeeMort);
            }
            else if(VALUE == "Armure de péon" || VALUE == "3"){
                if (armureEquipped == true){
                    player.unequip(armureBase);
                    player.setDefense(-armureBase->getDefense());
                    armureEquipped = false;
                }
                player.sellItem(armureBase);
                seller.addItem(armureBase);
            }
            else if(VALUE == "Armure de la Mort" || VALUE == "4"){
                if (armureEquipped2 == true){
                    player.unequip(armureMort);
                    player.setDefense(-armureMort->getDefense());
                    armureEquipped2 = false;
                }
                player.sellItem(armureMort);
                seller.addItem(armureMort);
            }
            else if(VALUE == "Talisman de la regeneration totale" || VALUE == "5"){
                if (talismanEquipped == true){
                    player.unequip(talismanRegen);
                    player.setHealth(-talismanRegen->getHealth());
                    talismanEquipped = false;
                }
                player.sellItem(talismanRegen);
                seller.addItem(talismanRegen);
            }
            else if(VALUE == "Talisman de la Mort" || VALUE == "6"){
                if (talismanEquipped2 == true){
                    player.unequip(talismanMort);
                    player.setHealth(-talismanMort->getHealth());
                    talismanEquipped2 = false;
                }
                player.sellItem(talismanMort);
                seller.addItem(talismanMort);
            }
            else if(VALUE == "exit"){
                break;
            }
            else{
                cout << "This item doesn't exist" << endl;
            }
        }
        else if(VALUE == "E" || VALUE == "e"){
            player.showInventory();
            cout << "What do you want to equip ?" << endl;
            string VALUE;
            getline(cin, VALUE);
            if(VALUE == "Epee de base" || VALUE == "1"){
                if(!armeEquipped2){
                    player.equip(epeeBase);
                    player.setStrength(epeeBase->getStrength());
                    armeEquipped = true;
                }
                else{
                    cout << "You already have an Arme equipped" << endl;
                }
            }
            else if(VALUE == "Epee de la Mort" || VALUE == "2"){
                if(!armeEquipped){
                    player.equip(epeeMort);
                    player.setStrength(epeeMort->getStrength());
                    armeEquipped2 = true;
                }
                else{
                    cout << "You already have an Arme equipped" << endl;
                }
            }
            else if(VALUE == "Armure de peon" || VALUE == "3"){
                if(!armureEquipped2){
                    player.equip(armureBase);
                    player.setDefense(armureBase->getDefense());
                    armureEquipped = true;
                }
                else{
                    cout << "You already have an Armure equipped" << endl;
                }
            }
            else if(VALUE == "Armure de la Mort" || VALUE == "4"){
                if(!armureEquipped){
                    player.equip(armureMort);
                    player.setDefense(armureMort->getDefense());
                    armureEquipped2 = true;
                }
                else{
                    cout << "You already have an Armure equipped" << endl;
                }
            }
            else if(VALUE == "Talisman de la regeneration totale" || VALUE == "5"){
                if(!talismanEquipped2){
                    player.equip(talismanRegen);
                    player.setHealth(talismanRegen->getHealth());
                    talismanEquipped = true;
                }
                else{
                    cout << "You already have a Talisman equipped" << endl;
                }
            }
            else if(VALUE == "Talisman de la Mort" || VALUE == "6"){
                if(!talismanEquipped){
                    player.equip(talismanMort);
                    player.setHealth(talismanMort->getHealth());
                    talismanEquipped2 = true;
                }
                else{
                    cout << "You already have a Talisman equipped" << endl;
                }
            }
            else if(VALUE == "exit"){
                break;
            }
            else{
                cout << "This item doesn't exist" << endl;
            }
        }
        else if (VALUE == "U" || VALUE == "u"){
            if(talismanEquipped || talismanEquipped2 || armureEquipped || armureEquipped2 || armeEquipped || armeEquipped2){
                cout << "What do you want to unequip ?" << endl;
                cout << "---- EQUIPPED ----" << endl;
                if(talismanEquipped){
                    cout << "Talisman de la regeneration totale" << endl;
                }
                if(talismanEquipped2){
                    cout << "Talisman de la Mort" << endl;
                }
                if(armureEquipped){
                    cout << "Armure de peon" << endl;
                }
                if(armureEquipped2){
                    cout << "Armure de la Mort" << endl;
                }
                if(armeEquipped){
                    cout << "Epee de base" << endl;
                }
                if(armeEquipped2){
                    cout << "Epee de la Mort" << endl;
                }
                cout << "------------------" << endl;
                string VALUE;
                getline(cin, VALUE);
                if(VALUE == "Epee de base" || VALUE == "1"){
                    player.unequip(epeeBase);
                    player.setStrength(-epeeBase->getStrength());
                    armeEquipped = false;
                }
                else if(VALUE == "Epee de la Mort" || VALUE == "2"){
                    player.unequip(epeeMort);
                    player.setStrength(-epeeMort->getStrength());
                    armeEquipped2 = false;
                }
                else if(VALUE == "Armure de peon" || VALUE == "3"){
                    player.unequip(armureBase);
                    player.setDefense(-armureBase->getDefense());
                    armureEquipped = false;
                }
                else if(VALUE == "Armure de la Mort" || VALUE == "4"){
                    player.unequip(armureMort);
                    player.setDefense(-armureMort->getDefense());
                    armureEquipped2 = false;
                }
                else if(VALUE == "Talisman de la regeneration totale" || VALUE == "5"){
                    player.unequip(talismanRegen);
                    player.setHealth(-talismanRegen->getHealth());
                    talismanEquipped = false;
                }
                else if(VALUE == "Talisman de la Mort" || VALUE == "6"){
                    player.unequip(talismanMort);
                    player.setHealth(-talismanMort->getHealth());
                    talismanEquipped2 = false;
                }
                else if(VALUE == "exit"){
                    break;
                }
                else{
                    cout << "This item doesn't exist" << endl;
                }
            } else {
                cout << "---- EQUIPPED ----" << endl;
                cout << "I dont have equipped item" << endl;
                cout << "------------------" << endl;
            }
        }
        else if(VALUE == "exit"){
            cout << "Thanks for playing ! See you soon ! :)" << endl;
            break;
        }
        else{
            cout << "This command doesn't exist" << endl;
        };
        cout << "\nWhat do you want to do " << Name << " ?" << endl;
        cout << "- Show Inventory (I)\n- Show Stats(Z)\n- Buy equipment (B)\n- Sell equipment (S) \n- Equip Item (E)\n- Unequip Item (U)\n- Exit Game (exit)" << endl;
        getline(cin, VALUE);
    }
}
