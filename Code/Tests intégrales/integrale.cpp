#include <iostream>
#include <vector>
#include <cmath>
#include <random>

#include "integrale.hpp"

integrale::integrale(fonction_g * fonction_g, fonction_f_unif * fonction_f):
  _fonction_g(fonction_g),
  _fonction_f(fonction_f)
{
};

double integrale::calc_int_n(const int num_tirage)
{
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(0.0,1.0);
  double res_int = 0;
  double num_rand_x;
  for(int i=0; i<num_tirage; i++){
    num_rand_x = distribution(generator);
    res_int += this->_fonction_g->calculer_g_x(num_rand_x);    
  }
  return res_int/num_tirage;
};

  
