#include <iostream>
#include <vector>

#include "fonctions_g.hpp"
#include "fonctions_f.hpp"

int main()
{
  double amplitude = 25.0;
  double pulsation = 3.0;
  double x = 0.25;

  fonction_g_sin fonction_sinus1(amplitude, pulsation);

  fonction_g_sin fonction_sinus2(fonction_sinus1);

  double res = fonction_sinus2.compute_g_x(x);

  std::cout << "Le résultat de "<< x << " par la fonction est " << res << " !! " << std::endl;

  return 0;
}
