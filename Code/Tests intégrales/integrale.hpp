#ifndef _INTEGRALE_HPP

#include <iostream>
#include <vector>

#include "fonctions_g.hpp"
#include "fonctions_f.hpp"

class integrale {
 private:
  //fonction g
  fonction_g * _fonction_g;
  //fonction f
  fonction_f_unif * _fonction_f;

 public:
  //Constructeurs :
  integrale(fonction_g * fonction_g, fonction_f_unif * fonction_f);

  //Calcul de l'intégrale
  double calc_int_n(const int num_tirages);
};

#define _INTEGRALE_HPP
#endif 
