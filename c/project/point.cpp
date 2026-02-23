#include "point.h"

int Point::nbSaisies = 0;

void Point::saisie()
{
    cout << "entrer x, y et nom" << endl;
    cin >> this->x >> y >> this->nom;
    Point::nbSaisies++;
}
