#include "Compte.h"
#include "Banque.h"
#include <iostream>;

using namespace std;

Banque::Banque()
{
    nbrCompte = 0;
    cout << "constructeur par defaut";
}

void Banque::inisialiser()
{
    nbrCompte = 0;
};

void Banque::afficherBanque()
{
    if (nbrCompte == 0)
    {
        cout << "Il y a aucun compte";
    }
    else
    {
        cout << "Les compte de la banque : " << endl;
        for (int i = 0; i < nbrCompte; i++)
        {
            agence[i].consulter();
        }
    }
};

void Banque::addCompte(Compte c)
{
    agence[nbrCompte] = c;
    nbrCompte++;
};

void Banque::surpprimer(int x)
{
    int i;
    for (i = 0; i < nbrCompte; i++)
    {
        if (agence[i].getNumCompte() == x)
        {
            break;
        }
    }
    if (i < nbrCompte)
    {
        for (int j = i; j < nbrCompte - 1; j++)
        {
            agence[j] = agence[j + 1];
        }
        this->nbrCompte--;
    }
};

Compte Banque::getCompte(int x)
{
    for (int i = 0; i < nbrCompte; i++)
    {
        if (agence[i].getNumCompte() == x)
        {
            return agence[i];
        }
    }
};
