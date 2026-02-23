#include "Technicien.h"
#include "Employe.h"
#include <iostream>

using namespace std;

const double Technicien::base = 15;
const double Technicien::part = 20;
const double Technicien::gainUnite = 5;

Technicien::Technicien() { nbUniteProduit = 0; }

Technicien::Technicien(const char *no, const char *pre, int ag, int agec, int x)
    : Employe(no, pre, ag, agec) {
  nbUniteProduit = x;
}

void Technicien::afficher() const {
  Employe::afficher();
  cout << "Nombre d'unites produites: " << nbUniteProduit << endl;
}

double Technicien::calcBaseSalaire() const {
  return base + (nbUniteProduit * gainUnite);
}