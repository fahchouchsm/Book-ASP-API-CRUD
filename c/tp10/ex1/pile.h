#ifndef Pile H
#define Pile H
#include <iostream>

using namespace std;

class Pile
{
private:
    int dim;
    int taille;
    int *adr;

public:
    Pile(int t = 10);
    Pile(const Pile &);
    ~Pile();
    void empile(const int &);
    void depile();
    int donnetaille() const;
    bool pleinne() const;
    bool vide() const;
    void affichep() const;
    // les operateur
    int operator[](const int &) const;
    Pile &operator=(const Pile &);
    bool operator==(const Pile &) const;
    void operator<(const int &);
    void operator--();
    Pile &operator+(const Pile &) const;
    Pile &operator+(const int &);
    // friends
    friend Pile &operator+(const int &, Pile &);
    friend ostream &operator<<(ostream &str, Pile &);
    friend istream &operator>>(istream &, Pile &);
};
#endif