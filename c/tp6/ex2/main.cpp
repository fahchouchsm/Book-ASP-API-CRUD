#include "Compte.h"
#include "Banque.h"
#include <iostream>

using namespace std;

int main()
{
    Compte fakeAcc, fake;
    fakeAcc.initialiser();
    fakeAcc.consulter();

    fake.initialiser();
    fake.consulter();

    Banque banque;
    banque.inisialiser();

    banque.addCompte(fake);
    banque.addCompte(fakeAcc);
    banque.afficherBanque();
    int temp;
    cout << endl
         << "entrer le compte a surpprimer avec num compte : " << endl;
    cin >> temp;
    banque.surpprimer(temp);
    banque.afficherBanque();
}