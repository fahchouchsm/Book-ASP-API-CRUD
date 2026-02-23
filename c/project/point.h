#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;

class Point
{
private:
    float x;
    float y;
    char nom;
    static int nbSaisies;

public:
    void saisie();
    void affich()
    {
        cout << this->nom << "(" << this->x << "," << this->y << ")" << endl;
        cout << "nombre de saisies: " << Point::nbSaisies << endl;
    }
    inline static void affichNbSaisies();
};

inline void Point::affichNbSaisies()
{
    cout << "nombre de saisies: " << Point::nbSaisies << endl;
}

#endif
