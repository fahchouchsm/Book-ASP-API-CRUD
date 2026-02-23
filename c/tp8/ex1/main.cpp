#include "Vecteur3.h"
#include <iostream>

using namespace std;

int main()
{
    Vecteur3 b(1, 2, 3, "simo", 4), c = b;
    b.affiche3();
    return 0;
}
