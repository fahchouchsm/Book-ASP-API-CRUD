#include <iostream>
#include "pile.h"

using namespace std;

Pile::Pile(int n)
{
    dim = n;
    adr = new int[dim];
    taille = 0;
}

Pile::~Pile()
{
    delete[] adr;
}

bool Pile::vide() const
{
    return taille == 0;
}

bool Pile::pleine() const
{
    return taille == dim;
}

void Pile::empile(int p)
{
    if (!pleine())
    {
        adr[taille] = p;
        taille++;
    }
    else
    {
        cout << "Impossible d'empiler, la pile est pleine!" << endl;
    }
}

void Pile::depile()
{
    if (!vide())
    {
        taille--;
    }
    else
    {
        cout << "Impossible de dépiler, la pile est vide!" << endl;
    }
}

void Pile::afficherP() const
{
    if (!vide())
    {
        for (int i = 0; i < taille; i++)
        {
            cout << " " << adr[i] << " ";
        }
        cout << endl;
    }
}
