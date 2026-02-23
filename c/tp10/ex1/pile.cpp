#include "pile.h"
#include <iostream>
#include <cstring>

using namespace std;

Pile::Pile(int t)
{
    dim = t;
    taille = 0;
    adr = new int[dim];
};

Pile::Pile(const Pile &p)
{
    dim = p.dim;
    taille = p.taille;
    adr = new int[p.dim];
};

Pile::~Pile()
{
    delete[] adr;
};

void Pile::affichep() const
{
    cout << "La pile conteinne : " << taille << " elements" << endl;
    cout << "La taille maximale est : " << dim << endl;
    for (int i = 0; i < taille; i++)
    {
        cout << adr[i] << endl;
    }
}

bool Pile::vide() const
{
    if (dim == 0)
    {
        return true;
    }
    return false;
};

bool Pile ::pleinne() const
{
    if (taille == dim)
    {
        cout << "le tableau est pleinne !";
        return true;
    }
    return false;
}

int Pile::donnetaille() const
{
    return taille;
}

void Pile::empile(const int &e)
{
    if (pleinne())
    {
        return;
    }
    adr[taille - 1] = e;
    taille++;
}

void Pile::depile()
{
    if (vide())
    {
        return;
    }
    taille--;
}
// les operator
Pile &Pile::operator=(const Pile &obj)
{
    int i;
    dim = obj.dim;
    taille = obj.taille;
    adr = new int[obj.dim];
    for (int i = 0; i < obj.taille; i++)
    {
        adr[i] = obj.adr[i];
    }
    cout << "operator =" << endl;
    return *this;
}

bool Pile::operator==(const Pile &p) const
{
    cout << "operator ==" << endl;
    if (taille == p.taille)
    {
        for (int i = 0; i < taille; i++)
        {
            if (adr[i] != p.adr[i])
                return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}

int Pile::operator[](const int &i) const
{
    if (i + 1 > taille || i < 0)
    {
        cout << "Operator[] Out of Index" << endl;
        return NULL;
    }
    return adr[i];
}

void Pile::operator<(const int &taille)
{
    empile(taille);
}

void Pile::operator--()
{
    taille--;
}

// Pile &operator+(const Pile &p)
// {
//     static Pile res(p.dim);
//     res.taille == p.taille;
//     for (int i = 0; i < taille; i++)
//     {
//         res.adr[i] = p.adr[i] + adr[i];
//     }
//     return res;
// }

Pile &Pile::operator+(const int &p)
{
    static Pile res(dim);
    res.taille == taille;
    for (int i = 0; i < taille; i++)
    {
        res.adr[i] = adr[i] + p;
    }
    return res;
}

// in out friends
ostream &operator<<(ostream &str, Pile &p)
{
    str << "[";
    for (int i = 0; i < p.taille; i++)
    {
        str << " " << p.adr[i];
    }
    str << "]";
    return str;
}

istream &operator>>(istream &istr, Pile &p)
{
    cout << "Entrer le nombre del de votre pile" << endl;
    istr >> p.taille;
    cout << "Enrer votre pile" << endl;
    for (int i = 0; i < p.taille; i++)
    {
        istr >> p.adr[i];
    }
    return istr;
}