#include "person.h"
#include <cstring>
#include <iostream>

using namespace std;

Personne::Personne()
{
    nom = new char[20];
    prenom = new char[20];
    strcpy(prenom, "BB");
    age = 20;
    cout << "constructeur par defaut" << endl;
};

Personne::Personne(const char *n, const char *p, const int &a)
{
    nom = new char[strlen(n) + 1];
    strcpy(nom, n);
    prenom = new char[strlen(p) + 1];
    strcpy(prenom, p);
    age = a;
    cout << "constructeur par parametre" << endl;
};

Personne::~Personne()
{
    delete[] nom;
    delete[] prenom;
    cout << "destructeur" << endl;
}

void Personne::affiche() const
{
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "Age: " << age << endl;
};