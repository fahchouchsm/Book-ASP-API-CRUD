#ifndef VECTEUR3_H
#define VECTEUR3_H

#include "Vecteur.h"

class Vecteur3 : public Vecteur
{
private:
    float h;

public:
    Vecteur3();
    Vecteur3(const float &, const float &, const float &, const char *nom, const float &);
    ~Vecteur3();
    Vecteur3(const Vecteur3 &);
    void initialise3(const float x, const float y, const float z, const float h);
    void affiche3();
    Vecteur3 &operator=(const Vecteur3 &);
};

#endif