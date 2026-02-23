#ifndef EMPLOYE_H
#define EMPLOYE_H

class Employe {

public:
  Employe();
  Employe(const char *, const char *, int, int);
  Employe(const Employe &);
  virtual ~Employe();
  virtual double calcBaseSalaire() const = 0;
  virtual void afficher() const;
  double calcSalaire() const;
  Employe &operator=(const Employe &);

protected:
  char *nom;
  char *prenom;
  int age;
  int anc;
};

#endif