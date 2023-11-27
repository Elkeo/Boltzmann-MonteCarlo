#include <iostream>
#include <vector>

//#include "fonctions_g.hpp"
//#include "fonctions_f.hpp"
#include "integrale.hpp"

int main()
{
  double amplitude = 1.0;
  double pulsation = 1.0;
  double ordorig = 0.0;
  double pente = 1.0;
  double min = 0.0;
  double max = 1.0;

  double * param = (double*)malloc(2*sizeof(double));

  param[0] = amplitude;
  param[1] = pulsation;

  fonction_g * fonction_a_integrer = new fonction_g_sin(param);

  fonction_f_unif * fonction_f_unif_1 = new fonction_f_unif(min, max);

  integrale integrale1(fonction_a_integrer, fonction_f_unif_1);

  int nombre_tirages = 10000;
  double res = integrale1.calc_int_n(nombre_tirages);
  
  std::cout << "L'intégrale de g calculée avec " << nombre_tirages << " donne la valeur  " << res << " !!" <<std::endl;

  return 0;
};
