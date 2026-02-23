#ifndef COMPTE_H
#define COMPTE_H

class Compte
{
public:
    void initialiser();
    void consulter();
    void retrait(const float &);
    void depot(const float &);
    int getNumCompte();

private:
    int numCompte;
    char numCl[50];
    float solde;
};

#endif