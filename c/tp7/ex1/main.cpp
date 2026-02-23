#include "person.h" vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

int main(int argc, char const *argv[])
{
    const Personne a;
    Personne b("AA", "BB", 20);
    a.affiche();
    b.affiche();
    return 0;
}
