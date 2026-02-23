#include "commercial.h"
#include "employe.h"
#include <cstring>
#include <iostream>

double Commercial::base = 0;
double Commercial::part = 0;
double Commercial::gain = 0;

Commercial::Commercial() : Employe(), Persone() { this->grade = new char[20]; };

Commercial::Commercial(const char *grade, const int &nbrUnite, const char *nom,
                       const char *prenom, const int &age, const int &ancienete)
    : Employe(nom, prenom, age, ancienete) {
  this->grade = new char[strlen(grade) + 1];
  strcpy(this->grade, grade);
  this->nbrUnite = nbrUnite;
}

Commercial::Commercial(const Commercial &c) : Employe(c) {
  this->grade = new char[strlen(c.grade) + 1];
  strcpy(this->grade, c.grade);
  this->nbrUnite = c.nbrUnite;
};

Commercial &Commercial::operator=(const Commercial &c) {
  if (this != &c) {
    Employe::operator=(c);
    delete[] grade;
    this->grade = new char[strlen(c.grade) + 1];
    strcpy(this->grade, c.grade);
    this->nbrUnite = c.nbrUnite;
  }
  return *this;
}

bool Commercial::operator==(const Commercial &c) {
  if (Employe::operator==(c)) {
    return false;
  }
  if (this->grade != c.grade) {
    return false;
  }
  if (this->nbrUnite != c.nbrUnite) {
    return false;
  }
  return true;
}

void Commercial::afficher() {
  Employe::afficher();
  cout << "le grade est" << this->grade << endl;
  cout << "le nbr unite" << this->nbrUnite << endl;
}

float Commercial::calcBaseSalaire() const {
  return base + nbrUnite * part * gain;
}