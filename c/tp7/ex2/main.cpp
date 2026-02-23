#include "compte.h"
#include "banque.h"

int main(int argc, char const *argv[])
{
    Compte c1;
    c1.depot(100);
    Compte c2("simo", 900);
    c1.afficherInfo();
    c2.afficherInfo();

    Banque b(20);
    b.add(c1);
    b.add(c2);
    b.afficheAg();

    return 0;
}