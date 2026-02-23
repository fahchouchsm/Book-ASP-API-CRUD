#ifndef COMMERCIAL_H
#define COMMERCIAL_H
#include "employe.h"

class Commercial : virtual public Employe {
private:
  char *grade;
  int nbrUnite;
  static double base;
  static double part;
  static double gain;

public:
  Commercial();
  Commercial(const char *grade, const int &nbrUnite, const char *nom,
             const char *prenom, const int &age, const int &ancienete);
  Commercial(const Commercial &);
  ~Commercial();
  Commercial &operator=(const Commercial &);
  bool operator==(const Commercial &);
  void afficher() override;
  float calcBaseSalaire() const override;
};

#endif