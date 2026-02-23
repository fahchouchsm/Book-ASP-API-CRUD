#define CHAINE_H
#ifdef CHAINE_H
#include <iostream>

using namespace std;

class Chaine
{
private:
    char *adr;

public:
    Chaine();
    Chaine(const char *);
    Chaine(const Chaine &);
    ~Chaine();
    int taille() const;
    void affiche() const;
    void ajout(char, int);
    void supp(int);
    Chaine &inv();
    bool appart(char) const;
    Chaine &operator=(const Chaine &);
    bool operator==(const Chaine &) const;
    Chaine &operator+(const Chaine &);
    char operator[](int) const;
    friend ostream &operator<<(ostream &, Chaine &);
    friend istream &operator>>(istream &, Chaine &);
};

#endif