#include "Chaine.h"
#include <cstring>
#include <iostream>

using namespace std;

Chaine::Chaine()
{
    adr = new char[20];
    adr[0] = '\0';
}

Chaine::Chaine(const char *c)
{
    int len = 0;
    while (c[len] != '\0')
    {
        len++;
    }

    adr = new char[len];
    for (int i = 0; i < len; i++)
    {
        adr[i] = c[i];
    }
}

Chaine::Chaine(const Chaine &v)
{
    adr = new char[v.taille() + 1];
    for (int i = 0; i < v.taille(); i++)
    {
        adr[i] = v.adr[i];
    }

    cout << "----- constructeur de recopie -----";
}

Chaine::~Chaine()
{
    delete[] adr;
}

int Chaine::taille() const
{
    int len = 0;
    while (adr[len] != '\0')
    {
        len++;
    }
    return len;
}

void Chaine::affiche() const
{
    cout << adr << endl;
}

// REVIEW -
void Chaine::ajout(char c, int p)
{
    if (p >= 0 && p <= taille())
    {
        for (int i = taille(); i >= p; i--)
        {
            adr[i + 1] = adr[i];
        }
        adr[p] = c;
    }
}

void Chaine::supp(int p)
{
    if (p >= 0 && p < taille())
    {
        for (int i = p; i < taille(); i++)
        {
            adr[i] = adr[i + 1];
        }
    }
}

Chaine &Chaine::inv()
{
    static Chaine res(adr);
    for (int i = 0; i < taille(); i++)
    {
        res.adr[i] = adr[taille() - 1 - i];
        res.adr[taille()] = '\0';
    }
    return res;
}

bool Chaine::appart(char c) const
{
    for (int i = 0; i < taille(); i++)
    {
        if (adr[i] == c)
        {
            return true;
        }
    }
    return false;
}
Chaine &Chaine::operator=(const Chaine &v)
{
    delete[] adr;
    adr = new char[v.taille() + 1];
    for (int i = 0; i < v.taille(); i++)
    {
        adr[i] = v.adr[i];
    }
    cout << "----- operateur d'affectation -----" << endl;
    return *this;
}

bool Chaine::operator==(const Chaine &v) const
{
    if (v.taille() == taille())
    {
        for (int i = 0; i < taille(); i++)
        {
            if (adr[i] != v.adr[i])
            {
                return false;
            }
        }
    }
    return false;
}

Chaine &Chaine::operator+(const Chaine &v)
{
    static Chaine res;
    delete[] res.adr;
    res.adr = new char[v.taille() + taille() + 1];

    for (int i = 0; i < taille(); i++)
    {
        for (i = taille(); i <= taille() + v.taille(); i++)
        {
            res.adr[i] = v.adr[i - taille()];
        }
    }
    return res;
}

char Chaine::operator[](int i) const
{
    return adr[i];
}

ostream &operator<<(ostream &ostr, Chaine &v)
{
    ostr << v.adr << endl;
    return ostr;
}

istream &operator>>(istream &istr, Chaine &v)
{
    istr >> v.adr;
    return istr;
}