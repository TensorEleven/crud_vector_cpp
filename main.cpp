#include <iostream>
#include "annuaire.h"
#include "contact.h"
#include "menu.h"

using namespace std;

int main(){
    Contact p1("Koto", "0344018932", "p1@gmail.com");
    Contact p2("Lita", "0331018923", "p2@gmail.com");
    Contact p3("Rabe", "0325533132", "p3@gmail.com");
    //p1.afficher_contact();

//ajout
    Annuaire annuaire;
    annuaire.ajout_fin(p1);
    annuaire.ajout_debut(p2);
    annuaire.ajout_debut(p3);
    cout << "Annuaire: " << endl;
    annuaire.lister();

//recherche
    //string recherche = "p3@gmail.com";
    cout << endl << "Resultat de recherche "/*pour \""<< recherche <<"\":" */<< endl;

//    annuaire.rechercher();

//charger donnée
    annuaire.charger("contact_in.txt");
    cout << "\nApres chargement :\n"; 
//   annuaire.lister();

//enregistrer
    cout << endl << "Sauvegarde :\n";
//    annuaire.enregistrer("annuaire.txt");

//modification
    cout << endl;
//    annuaire.modifier();
//    annuaire.lister();
    cout << endl;

//suppression
    cout << "Suppression :\n";
//    annuaire.supprimer();

//annuaire final    
//    annuaire.lister();

    Menu menu;
    int choice;
    while(menu.getChoix()!=0)
    {
        menu.display();
        choice = 12;
        cout << "votre choix >"; cin >> choice;
        menu.setChoix(choice);

        annuaire.effecteur(menu.getChoix());
    }
    return 0;
}