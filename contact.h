#ifndef CONTACT
#define CONTACT

#include <iostream>
#include <string>

using namespace std;

class Contact
{
	public: 
		Contact(string nom, string tel,string e_mail);
		void afficher_contact();
		void set(Contact contact);
		void setName(string nom);
		void setTel(string tel);
		void setEmail(string email);
		string getName();
		string getTel();
		string getEmail();
	private:
		string _nom;
		string _tel;
		string _email;
};

#endif
