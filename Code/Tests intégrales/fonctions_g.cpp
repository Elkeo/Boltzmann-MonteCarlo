#include <iostream>
#include <vector>
#include <cmath>

#include "fonctions_g.hpp"

fonction_g::fonction_g(double * vecteur_parametres):
  _vecteur_parametres(vecteur_parametres)
{
}

fonction_g::fonction_g(fonction_g& fonction):
  _vecteur_parametres(fonction.getParameters())
{
}

fonction_g::~fonction_g()
{
}

double fonction_g_sin::calculer_g_x(double valeur_x)
{
  double amplitude = this->_vecteur_parametres[0];
  double pulsation = this->_vecteur_parametres[1]; 
  return amplitude*sin(pulsation*valeur_x);
}

//double fonction_lin::calculer_g_x(const double valeur_x)
//{
//this->_pente = _vecteur_parametres;
//this->_ordorig = _vecteur_parametres;
//return this->_pente*valeur_x + _ordorigfonction_g& fonction_g;
//}
