#include <iostream>
#include <string.h>

using namespace std;

struct Element
{
    char *donne;
    Element *suivant;
};

void affiche(Element *);
Element *insDebutList(Element *, char *);
Element *insFinList(Element *, char *);
Element *insList(Element *, char *, int);
Element *suppDebut(Element *);
Element *suppAilleur(Element *, int);

int main()
{
    Element *liste = NULL;
    liste = insDebutList(liste, "aaa");
    affiche(liste);
    return 0;
};

void affiche(Element *liste)
{
    Element *courant;
    courant = liste;
    cout << "liste contient" << endl;
    while (courant != NULL)
    {
        cout << courant->donne << endl;
        courant = courant->suivant;
    }
};

Element *insDebutList(Element *liste, char *d)
{
    Element *nouveauElement;
    if ((nouveauElement = new Element) == NULL)
    {
        return liste;
    }
    if ((nouveauElement->donne = new char[strlen(d) + 1]) == NULL)
    {
        return liste;
    }
    strcpy(nouveauElement->donne, d);
    nouveauElement->suivant = liste;
    liste = nouveauElement;
    return liste;
};

Element *insFinList(Element *liste, char *d)
{
    Element *nouveauElement;
    Element *dernierElement;
    if ((nouveauElement = new Element) == NULL)
    {
        return liste;
    }
    if ((nouveauElement->donne = new char[strlen(d) + 1]) == NULL)
    {
        return liste;
    }
    strcpy(nouveauElement->donne, d);
    dernierElement = liste;
    while (dernierElement->suivant != NULL)
    {
        dernierElement = dernierElement->suivant;
        nouveauElement->suivant = nouveauElement;
        nouveauElement->suivant = NULL;
        return liste;
    }
}

Element *insList(Element *liste, char *d, int pos)
{
    Element *courant, *nouveauElement;
    if ((nouveauElement = new Element) == NULL)
    {
        return liste;
    }
    if ((nouveauElement->donne = new char[strlen(d) + 1]) == NULL)
    {
        return liste;
    }
    courant = liste;
    for (int i = 0; i < pos; i++)
    {
        courant = courant->suivant;
    }
    if (courant->suivant != NULL)
    {
        strcpy(nouveauElement->donne, d);
        nouveauElement->suivant = courant->suivant;
        courant->suivant = nouveauElement;
    }
    return liste;
}

Element *suppDebut(Element *liste)
{
    Element *suppElement;
    if (liste == NULL)
    {
        return NULL;
    }
    suppElement = new Element;
    suppElement->donne = new char[50];
    suppElement = liste;
    liste = liste->suivant;
    delete[] suppElement->donne;
    delete suppElement;
    return liste;
}

Element *suppAilleur(Element *liste, int pos)
{
    Element *suppElement, *courant;
    courant = liste;
    suppElement = new Element;
    suppElement->donne = new char[50];
    for (int i = 0; i < pos; i++)
    {
        courant = courant->suivant;
    }
    suppElement = courant->suivant;
    if (suppElement->suivant == NULL)
    {
        courant->suivant = NULL;
        delete[] suppElement->donne;
        delete suppElement;
        cout << "Vous avez fait une suppression a la fin de la liste" << endl;
        return liste;
    }
    else
    {
        Element *ps;
        ps = courant->suivant;
        courant->suivant = ps->suivant;
        delete[] suppElement->donne;
        delete suppElement;
        cout << "Vous avez fait une suppression alleurs dans la liste" << endl;
        return liste;
    }
}