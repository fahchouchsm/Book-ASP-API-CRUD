#include "pile.h"

int main()
{
    Pile p(5);

    p.empile(10);
    p.empile(20);
    p.empile(30);
    p.empile(40);
    p.empile(50);
    p.empile(60);

    p.afficherP();

    p.depile();
    p.depile();
    p.afficherP();
    p.depile();

    return 0;
}
