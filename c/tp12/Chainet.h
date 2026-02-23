#define CHAINET_H
#ifdef CHAINET_H
#include "Chaine.h"

class Chainet : public Chaine
{
public:
    Chainet();
    Chainet(const char *);
    ~Chainet();
    Chainet(const Chainet &);
    Chaine &operator=(const Chainet &);
    void affiche() const;
    void calcul() const;

private:
    bool type;
    float val;
};

#endif