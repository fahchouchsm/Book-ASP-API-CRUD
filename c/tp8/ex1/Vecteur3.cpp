#include "Vecteur3.h"
#include <iostream>

using namespace std;

Vecteur3::Vecteur3()
{
    h = 0.0;
    cout << "constructeur class fille" << endl;
}

Vecteur3::~Vecteur3()
{
    cout << "distructeur class fille" << endl;
}

Vecteur3::Vecteur3(const float &x, const float &y, const float &z, const char *nom, const float &h) : Vecteur(x, y, z, nom)
{
    this->h = h;
    cout << "constructeur par param fille" << endl;
}

void Vecteur3::affiche3()
{
    affiche();
    cout << "h : " << h << endl;
}
// REVIEW -
Vecteur3::Vecteur3(const Vecteur3 &v) : Vecteur(v)
{
    h = v.h;
    cout << "constructeur de recopie fille" << endl;
}

Vecteur3 &Vecteur3::operator=(const Vecteur3 &v)
{
    Vecteur::operator=(v);
    h = v.h;
    cout << "operateur d'affectation fille" << endl;
}