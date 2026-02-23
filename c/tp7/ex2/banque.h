#include "compte.h"

class Banque
{
public:
    Banque(int = 2000);
    ~Banque();
    void add(Compte);
    void ddelete(int);
    Compte getCompte(int) const;
    void afficheAg() const;

private:
    Compte *agence;
    int Nbrecl;
    int nbreLimite;
};