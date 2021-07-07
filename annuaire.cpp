#include "annuaire.h"
#include "contact.h"
#include <fstream>

using namespace std;


void Annuaire::ajout_debut(Contact contact){
    contacts.insert(contacts.begin(), contact);
}

void Annuaire::ajout_fin(Contact contact){
    contacts.push_back(contact);
}

void Annuaire::lister()
{
    vector<Contact>::iterator it;
    for(it = contacts.begin();it<contacts.end();it++)
    {
        it->afficher_contact();
    }
}

void Annuaire::rechercher()
{
    vector<Contact>::iterator it;
    string recherche;

    cout << "rechercher ? > ";cin >> recherche;

    for(it = contacts.begin();it<contacts.end();it++)
    {
        if(it->getName()==recherche||it->getTel()==recherche||it->getEmail()==recherche)
            it->afficher_contact();
    }
}

void Annuaire::charger(string fichier)
{

    ifstream infile(fichier);
    string name = "";
    string number = "";
    string email = "";

    while (infile)
    {
        infile >> name;
        infile >> number;
        infile >> email;
    }

    Contact newContact(name,number,email);
    contacts.push_back(newContact);

    infile.close();
}

void Annuaire::enregistrer(string fichier)
{
    ofstream outfile(fichier);

    vector<Contact>::iterator it;

    outfile << "NOM       Tel       mail"<< endl;
    outfile << "------------------------"<< endl;
    if(outfile)
    {
        for(it = contacts.begin();it<contacts.end();it++)
        {
            outfile << it->getName() << " "<< it->getTel() << " " << it->getEmail();
            outfile << endl;
        }
        outfile.close();
        /*if(outfile!=NULL)
            cout << "Sauvegarde effectué avec succes!\n";
        */
    }
    else
        cout << "erreur lors de l'enregistrement\n";
}

void Annuaire::modifier()
{
    //rechercher le nom
    vector<Contact>::iterator it;
    string recherche ="", nom="", tel="", mail="";

    cout << "Nom, Tel ou E-mail du contact a modifier: ";
    cin >> recherche;

    for(it = contacts.begin();it<contacts.end();it++)
    {
        if(it->getName()==recherche||it->getTel()==recherche||it->getEmail()==recherche)
            break;
    }
    it->afficher_contact();
    //demander les nouvelles informations
    cout << endl << "Entrer les nouvelles infos\n";
    cout << "> nom: "; cin >> nom;
    cout << "> tel: "; cin >> tel;
    cout << "> mail: "; cin >> mail;

    //effectuer les modification
    it->setName(nom);
    it->setTel(tel);
    it->setEmail(mail);
}

void Annuaire::supprimer()
{
    vector<Contact>::iterator it;
    string recherche ="";
    
    cout << "Contact a supprimer > ";
    cin >> recherche;

    for(it = contacts.begin();it<contacts.end();it++)
    {
        if(it->getName()==recherche||it->getTel()==recherche||it->getEmail()==recherche)
            break;
    }
    contacts.erase(it);
}

void Annuaire::effecteur(int choix)
{
    switch (choix)
    {
    case 1:
        lister();
        cout << endl;
        break;
    case 2:
        rechercher();
        cout << endl;
        break;
    case 3:
        charger("contact_in.txt");
        cout << endl;
        break;
    case 4:
        enregistrer("annuaire.txt");
        cout << endl;
        break;
    case 5:
        modifier();
        cout << endl;
        break;
    case 6:
        supprimer();
        cout << endl;
    default:
        break;
    }
}