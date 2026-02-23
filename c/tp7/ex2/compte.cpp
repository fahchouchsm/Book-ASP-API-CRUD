#include "compte.h"
#include <cstring>
#include <iostream>

int Compte::nombreClient = 0;

Compte::Compte()
{
    nom = new char[strlen("pas de nom")];
    strcpy(nom, "pas de nom");
    solde = 0;
    numClient = nombreClient;
    nombreClient++;
}

Compte::Compte(int limite)
{
    nom = new char[strlen("pas de nom")];
    strcpy(nom, "pas de nom");
    solde = 0;
    numClient = nombreClient;
    nombreClient++;
    this->limite = limite;
}

Compte::Compte(const char *nom, const float &solde)
{
    this->nom = new char[strlen(nom)];
    strcpy(this->nom, nom);
    this->solde = solde;
    numClient = nombreClient;
    nombreClient++;
}

Compte::~Compte()
{
    delete[] nom;
}

int Compte::getNombreCLient() const
{
    return nombreClient;
}

float Compte::getSold() const
{
    return solde;
}

void Compte::depot(const float &solde)
{
    if (solde < 0)
    {
        std::cerr << "Erreur: le montant du dépôt ne peut pas être négatif." << std::endl;
        return;
    }

    this->solde += solde;
}

void Compte::afficherInfo() const
{
    std::cout << "Nom: " << nom << std::endl;
    std::cout << "Solde: " << solde << std::endl;
    std::cout << "Numero de client: " << numClient << std::endl;
}