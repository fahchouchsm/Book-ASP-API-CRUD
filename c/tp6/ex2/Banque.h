#ifndef BANQUE_H
#define BANQUE_H
#include "Compte.h";

class Banque
{
public:
    Banque();
    void inisialiser();
    void afficherBanque();
    void addCompte(Compte);
    void surpprimer(int);
    Compte getCompte(int);

private:
    Compte agence[1000];
    int nbrCompte;
};

#endif
