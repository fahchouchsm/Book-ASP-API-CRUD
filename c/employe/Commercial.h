#ifndef COMMERCIAL_H
#define COMMERCIAL_H
#include "Employe.h"

class Commercial : public Employe {
public:
  Commercial();
  Commercial(const char *, const char *, int, int, double);
  virtual ~Commercial();
  Commercial(const Commercial &);
  Commercial &operator=(const Commercial &);
  virtual double calcBaseSalaire() const;
  void afficher() const;
};

#endif