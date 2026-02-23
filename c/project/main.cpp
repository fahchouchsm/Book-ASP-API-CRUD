#include "point.h"

int main()
{
    Point a, *b;
    a.saisie();
    a.affich();

    b = new Point;
    b->saisie();
    b->affich();
    delete b;

    Point::affichNbSaisies();
    return 0;
}
