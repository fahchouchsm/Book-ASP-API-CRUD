#include "Compte.h";
#include <iostream>;

using namespace std;

void Compte::initialiser()
{
    cout << "Entrez le numero de compte: ";
    cin >> numCompte;
    // cout << "Entrez le numero de client: ";
    // cin >> numCl;
    cout << "Entrez le solde: ";
    cin >> solde;
};

void Compte::consulter()
{
    cout << "Compte N " << numCompte << " le numero de client : " << numCl << endl
         << "Votre solde est " << solde << endl;
};

void Compte::depot(const float &x)
{
    solde += x;
};

void Compte::retrait(const float &x)
{
    if (x <= solde)
    {
        solde -= x;
    }
};

int Compte::getNumCompte()
{
    return numCompte;
};
