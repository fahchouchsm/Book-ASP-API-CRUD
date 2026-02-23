#ifndef TECHNICIEN_H
#define TECHNICIEN_H
#include "Employe.h"

class Technicien : public Employe {
public:
  Technicien();
  Technicien(const char *, const char *, int, int, int);
  virtual ~Technicien();
  Technicien(const Technicien &);
  Technicien &operator=(const Technicien &);
  virtual double calcBaseSalaire() const;
  void afficher() const;

private:
  int nbUniteProduit;
  static const double base;
  static const double part;
  static const double gainUnite;
};

#endif