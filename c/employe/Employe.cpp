#include "Employe.h"
#include <cstring>
#include <iostream>

using namespace std;

Employe::Employe() {
  nom = new char[20];
  prenom = new char[20];
  age = 0;
  anc = 0;
}

Employe::Employe(char *nom, const char *prenom, int age, int anc) {
  nom = new char[strlen(nom) + 1];
  strcpy(this->nom, nom);
  this->prenom = new char[strlen(prenom) + 1];
  strcpy(this->prenom, prenom);
  this->age = age;
  this->anc = anc;
}

Employe::Employe(const Employe &v) {
  nom = new char[strlen(v.nom) + 1];
  strcpy(nom, v.nom);
  prenom = new char[strlen(v.prenom) + 1];
  strcpy(prenom, v.prenom);
  age = v.age;
  anc = v.anc;
}

Employe::~Employe() {
  delete[] nom;
  delete[] prenom;
}

Employe &Employe::operator=(const Employe &v) {
  delete[] nom;
  nom = new char[strlen(v.nom) + 1];
  strcpy(nom, v.nom);
  delete[] prenom;
  prenom = new char[strlen(v.prenom) + 1];
  strcpy(prenom, v.prenom);
  age = v.age;
  anc = v.anc;
  return *this;
}

double Employe::calcSalaire() const {
  double s = calcBaseSalaire();
  for (int i = 0; i < anc; ++i) {
    s += s * 0.1;
  }
  return s;
}

void Employe::afficher() const {
  cout << "Nom: " << nom << endl;
  cout << "Prenom: " << prenom << endl;
  cout << "Age: " << age << endl;
  cout << "Anciennete: " << anc << endl;
  cout << "Salaire: " << calcSalaire() << endl;
}