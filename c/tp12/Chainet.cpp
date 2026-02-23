#include "Chainet.h";
#include <iostream>

using namespace std;

Chainet::Chainet()
{
    this->type = false;
    this->val = 0;
};

Chainet::Chainet(const char *c) : Chaine(c)
{
    this->type = false;
    this->val = 0;
};

Chainet::~Chainet() {
};

Chainet::Chainet(const Chainet &v) : Chainet(v)
{
    type = v.type;
    val = v.val;
    cout << "constructeur par recopie de la classe file" << endl;
};

Chaine &Chainet::operator=(const Chainet &v)
{
    Chaine::operator=(v);
    type = v.type;
    val = v.val;
    cout << "operator d'affectation classe fille" << endl;
    return *this;
};

void Chainet::affiche() const
{
    Chaine::affiche();
    cout << "type : " << type << endl;
    cout << "valeur : " << val << endl;
};

void Chainet::calcul() const
{
    if (type)
    {
        cout << "Calculating with type true: " << val * 2 << endl;
    }
    else
    {
        cout << "Calculating with type false: " << val + 10 << endl;
    }
}