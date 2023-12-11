#include <iostream>
#include <vector>
#include <cmath>

#include "fonctions_f.hpp"

fonction_f_unif::fonction_f_unif(const double val_min, const double val_max):
  _min(val_min),
  _max(val_max)
{
}

fonction_f_unif::fonction_f_unif(const fonction_f_unif& fonction):
  _min(fonction.getMin()),
  _max(fonction.getMax())
{
}

double fonction_f_unif::compute_f_x(const double var_x)
{
  return this->_min + var_x*(this->_max-this->_max);
}
