#ifndef MENU
#define MENU

#include <iostream>
#include <string>

using namespace std;

class Menu
{
    public:
    void display(){
        for(int i=0;i<nmbrChoix;i++)
        {
            cout << list[i] << endl;
        }
    }

    void setChoix(int newChoix){choix=newChoix;}
    int getChoix(){return choix;}

    private:
    int choix = 12;
    int nmbrChoix = 8;
    string list[8]={
                    "1 - Annuaire",
                    "2 - Rechercher",
                    "3 - Charger contact",
                    "4 - Enregistrer",
                    "5 - modifier un contact",
                    "6 - supprimer un contact",
                    "------------------------",
                    "0 - quitter"};
};

#endif