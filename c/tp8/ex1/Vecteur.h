#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>

using namespace std;

class Vecteur
{
protected:
    float x, y, z;
    char *nom;

public:
    Vecteur(const float = 0, const float = 0, const float = 0, const char * = "f");
    // constructeure de copy
    Vecteur(const Vecteur &);
    // operateur d'affectation
    Vecteur &operator=(const Vecteur &);
    // operateur de +
    Vecteur &operator+(const Vecteur &);
    // operateur de *
    Vecteur &operator*(const float &);
    friend Vecteur &operator*(const float &, const Vecteur &);
    // operator cout << and cin >> (istream and ostream)
    friend istream &operator>>(istream &, Vecteur &);
    friend ostream &operator<<(ostream &, Vecteur &);
    // disctructeur
    ~Vecteur();
    void declacrede(const float &, const float &, const float &);
    bool compare(Vecteur &) const;
    bool compare(Vecteur *) const;
    // ex2
    Vecteur oppose() const;
    Vecteur *opposep() const;
    Vecteur &opposer() const;

    Vecteur &normMax(Vecteur &);
    Vecteur &normMax(Vecteur *);
    Vecteur *normMaxP(Vecteur &);
    void affiche() const;
    int getNbrVecteur() const;
    static int nbrVecteur;
};

#endif