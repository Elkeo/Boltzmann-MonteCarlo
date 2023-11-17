#include <iostream>
#include <vector>
#include <cmath>

#include "MonteCarlo.hpp"

fonction_g_sin::fonction_g_sin(const double val_amplitude, const double val_pulsation):
  _amplitude(val_amplitude),
  _pulsation(val_pulsation)
{
}

fonction_g_sin::fonction_g_sin(const fonction_g_sin& fonction):
  _amplitude(fonction.getAmplitude()),
  _pulsation(fonction.getPulsation())
{
}

double fonction_g_sin::compute_g_x(const double var_x)
{
  return this->_amplitude*sin(this->_pulsation*var_x);
}
