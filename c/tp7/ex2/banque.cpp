
#include <iostream>
#include "banque.h"
#include "compte.h"

using namespace std;

Banque::Banque(int nl)
{
    nbreLimite = nl;
    agence = new Compte[nbreLimite];
    Nbrecl = 0;
}

Banque::~Banque()
{
    delete[] agence;
}

void Banque::add(Compte c)
{
    agence[Nbrecl] = c;
    Nbrecl++;
}

void Banque::ddelete(int numc)
{
    int i;
    for (i = 0; i < Nbrecl; i++)
    {
        if (agence[i].getNumClient() == numc)
        {
            break;
        }
    }

    if (i < Nbrecl)
    {
        for (int j = i; j < Nbrecl - 1; j++)
        {
            agence[j] = agence[j + 1];
        }
        Nbrecl--;
    }
}

Compte Banque::getCompte(int numc) const
{
    int i;
    for (i = 0; i < Nbrecl; i++)
    {
        if (agence[i].getNumClient() == numc)
        {
            break;
        }
    }
    return agence[i];
}

void Banque::afficheAg() const
{
    int i;
    for (i = 0; i < Nbrecl; i++)
    {
        cout << "Compte " << i + 1 << endl;
        agence[i].afficherInfo();
        cout << "************************" << endl;
    }
}