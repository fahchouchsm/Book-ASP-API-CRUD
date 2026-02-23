#ifndef PILE_H
#define PILE_H

class Pile
{
public:
    Pile(int t = 10);
    ~Pile();
    void empile(int);
    void depile();
    bool vide() const;
    bool pleine() const;
    void afficherP() const;

private:
    int dim;
    int taille;
    int *adr;
};

#endif
