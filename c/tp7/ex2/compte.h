#ifndef COMPTE_H
#define COMPTE_H

class Compte
{
public:
    Compte();
    Compte(const char *, const float &);
    Compte(int);
    ~Compte();
    int getNombreCLient() const;
    float getSold() const;
    void depot(const float &);
    void afficherInfo() const;
    int getNumClient() const { return numClient; }

private:
    int numClient;
    static int nombreClient;
    char *nom;
    float solde;
    int limite;
};

#endif