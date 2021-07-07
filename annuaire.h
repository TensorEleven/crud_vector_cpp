#ifndef ANNUAIRE
#define ANNUAIRE


#include <iostream>
#include <vector>
#include <fstream>
#include "contact.h"

using namespace std;

class Annuaire
{
	public:
		Annuaire(){}
		void lister();
		void ajout_debut(Contact contact);
		void ajout_fin(Contact contact);
		void rechercher();
		void charger(string fichier);
		void enregistrer(string fichier);
		void modifier();
		void supprimer();	//rechercher et supprimer

		void effecteur(int choix);
	private:
		std::vector<Contact> contacts;
};

#endif