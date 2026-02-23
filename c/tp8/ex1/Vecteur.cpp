#include "Vecteur.h"
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int Vecteur::nbrVecteur = 0;

Vecteur::Vecteur(const float x, const float y, const float z, const char *nom)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->nom = new char[strlen(nom) + 1];
    strcpy(this->nom, nom);
    nbrVecteur++;
    cout << "constructeur par defaut mere" << endl;
};

Vecteur::~Vecteur()
{
    delete[] nom;
    cout << "destructeur mere" << endl;
}

int Vecteur::getNbrVecteur() const
{
    return nbrVecteur;
}

bool Vecteur::compare(Vecteur &v) const
{
    if (this->x == v.x && this->y == v.y && this->z == v.z)
    {
        return true;
    }
    return false;
}

bool Vecteur::compare(Vecteur *v) const
{
    if (this->x == v->x && this->y == v->y && this->z == v->z)
    {
        return true;
    }
    return false;
}
// Oppose by Value
Vecteur Vecteur::oppose() const
{
    return Vecteur(-x, -y, -z, nom);
}

// return par pointeur
Vecteur *Vecteur::opposep() const
{
    return new Vecteur(-x, -y, -z, nom);
}

// return par ref
Vecteur &Vecteur::opposer() const
{
    static Vecteur v;
    v.x = -x;
    v.y = -y;
    v.z = -z;
    v.nom = new char[strlen(nom) + 1];
    strcpy(v.nom, nom);
    return v;
}

Vecteur &Vecteur::normMax(Vecteur &v)
{
    float norm1 = sqrt(x * x + y * y + z * z);
    float norm2 = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    if (norm1 >= norm2)
    {
        return *this;
    }
    return v;
}

void Vecteur::affiche() const
{
    cout << this->nom << "(" << x << ", " << y << ", " << z << ") de class mere." << endl;
}
// opperateur d'affectation
Vecteur &Vecteur::operator=(const Vecteur &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    delete[] nom;
    nom = new char[strlen(v.nom) + 1];
    strcpy(nom, v.nom);
    cout << "opperation d'affectation" << endl;
    return *this;
}
// opperateur de clonage
Vecteur::Vecteur(const Vecteur &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    this->nom = new char[strlen(v.nom) + 1];
    strcpy(this->nom, v.nom);
    cout << "opperateur de clonage" << endl;
}
// operateur de plus
Vecteur &Vecteur::operator+(const Vecteur &v)
{
    static Vecteur rs;
    rs.x = x + v.x;
    rs.y = y + v.y;
    rs.z = z + v.z;
    strcpy(rs.nom, nom);
    strcat(rs.nom, v.nom);
    cout << "operateur +" << endl;
    return rs;
}
// operateur de *
Vecteur &Vecteur::operator*(const float &h)
{
    static Vecteur rs;
    rs.x = x * h;
    rs.y = y * h;
    rs.z = z * h;
    strcpy(rs.nom, nom);
    cout << "operateur *" << endl;
    return rs;
}
// operator friend to manage 100* vecteur
Vecteur &operator*(const float &f, const Vecteur &v)
{
    static Vecteur rs;
    rs.x = f * v.x;
    rs.y = f * v.y;
    rs.z = f * v.z;
    strcpy(rs.nom, v.nom);
    cout << "fonction friend" << endl;
    return rs;
}
// istream cin
istream &operator>>(istream &ist, Vecteur &v)
{
    cout << "Entrer x, y,z, nom" << endl;
}