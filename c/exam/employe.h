#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <iostream>

using namespace std;

class Employe {
private:
  char *nom;
  char *prenom;
  int age;
  int ancienete;

public:
  static int nbrEmp;
  Employe();
  Employe(const char *, const char *, const int &, const int &);
  Employe(const Employe &);
  virtual ~Employe();
  virtual float calcBaseSalaire() const = 0;
  virtual float calcSalaire(const float &);
  virtual void afficher();
  virtual Employe &operator=(const Employe &);
  virtual bool operator==(const Employe &);
  friend ostream operator<<(const ostream, const Employe &);
  friend istream operator>>(const istream, const Employe &);
};

#endif
