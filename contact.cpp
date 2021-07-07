#include <string>
#include <iostream>
#include "contact.h"

using namespace std;

Contact::Contact(string nom, string tel, string e_mail)
{
    _nom = nom;
    _tel = tel;
    _email = e_mail;
}

void Contact::afficher_contact(){
    cout << "nom : " << _nom << " | tel: " << _tel << " | mail: "<< _email<< endl;
}

string Contact::getName(){
    return _nom;
}

string Contact::getTel()
{
    return _tel;
}

string Contact::getEmail()
{
    return _email;
}


//mutator

void Contact::setName(string nom)
{
    _nom = nom;
}

void Contact::setTel(string tel)
{
    _tel = tel;
}

void Contact::setEmail(string email)
{
    _email = email;
}