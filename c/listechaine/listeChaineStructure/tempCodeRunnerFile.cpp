
#include <cstddef>
#include <cstring>
#include <iostream>

using namespace std;

struct Element {
  char *donnee;
  Element *suivant;
};

void afficher(Element *liste) {
  Element *courant = liste;
  cout << "la liste contient : " << endl;
  while (courant != NULL) {
    cout << courant->donnee << endl;
    courant = courant->suivant;
  }
};

void afficherReverse(Element *liste) {
  Element *courant = liste;
  cout << "la liste contient : " << endl;
  while (courant != NULL) {
    afficherReverse(liste->suivant);
    cout << courant->donnee << endl;
  }
};

// Element *insInNull(Element *liste, const char *d) {
//   Element *nouveau = new Element;

//   nouveau->donnee = new char[strlen(d) + 1];
//   strcpy(nouveau->donnee, d);

//   liste->suivant = nouveau;

//   return liste;
// };

Element *insBegin(Element *liste, const char *d) {
  Element *nouveau = new Element;
  nouveau->suivant = liste;
  nouveau->donnee = new char[strlen(d) + 1];
  strcpy(nouveau->donnee, d);

  return nouveau;
};

Element *insEnd(Element *liste, const char *d) {
  Element *nouveau = new Element;
  Element *dernier = liste;
  nouveau->donnee = new char[strlen(d) + 1];
  strcpy(nouveau->donnee, d);

  while (dernier->suivant != NULL) {
    dernier = dernier->suivant;
  }

  dernier->suivant = nouveau;
  nouveau->suivant = NULL;
  return liste;
}

Element *insMid(Element *liste, const char *d, const int pos) {
  Element *nouveau, *courant;
  nouveau = new Element;
  nouveau->donnee = new char[strlen(d) + 1];
  strcpy(nouveau->donnee, d);

  courant = liste;
  for (int i = 0; i < pos; i++) {
    courant = courant->suivant;
  }

  nouveau->suivant = courant->suivant;
  courant->suivant = nouveau;

  return liste;
};

int main() {
  Element *liste = NULL;
  liste = insBegin(liste, "hello");
  liste = insEnd(liste, "!");
  liste = insMid(liste, "world", 1);
  afficher(liste);
  return 0;
};
