#include "employe.h"
#include <cstring>
#include <iostream>

using namespace std;

int Employe::nbrEmp = 0;

Employe::Employe() {
  this->nom = new char[30];
  this->prenom = new char[30];
  nbrEmp++;
};

Employe::Employe(const char *nom, const char *prenom, const int &age,
                 const int &ancienete) {
  this->nom = new char[strlen(nom) + 1];
  this->prenom = new char[strlen(prenom) + 1];
  strcpy(this->nom, nom);
  strcpy(this->prenom, prenom);
  this->age = age;
  this->ancienete = ancienete;
};

Employe::Employe(const Employe &e) {
  nom = new char[strlen(e.nom) + 1];
  prenom = new char[strlen(e.prenom) + 1];
  age = e.age;
  ancienete = e.ancienete;
};

Employe::~Employe() {
  delete[] nom;
  delete[] prenom;
};

float Employe::calcSalaire(const float &base) {
  return +(0.1f * ancienete * base);
};

void Employe::afficher() {
  cout << "Nom: " << nom << endl;
  cout << "Prenom: " << prenom << endl;
  cout << "Age: " << age << endl;
  cout << "Ancienete: " << ancienete << endl;
};

Employe &Employe::operator=(const Employe &e) {
  if (this == &e)
    return *this;
  delete[] nom;
  delete[] prenom;
  nom = new char[strlen(e.nom) + 1];
  prenom = new char[strlen(e.prenom) + 1];
  strcpy(nom, e.nom);
  strcpy(prenom, e.prenom);
  age = e.age;
  ancienete = e.ancienete;
  return *this;
};

bool Employe::operator==(const Employe &e) {
  return strcmp(nom, e.nom) == 0 && strcmp(prenom, e.prenom) == 0 &&
         age == e.age && ancienete == e.ancienete;
}
