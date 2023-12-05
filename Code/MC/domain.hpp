#include "main.hpp"


/* CLASSE DÉFINISSANT LE DOMAINE DANS LEQUEL LE PAQUET DE PARTICULE ÉVOLUE */
class Domain
{
protected:
   int d;
   std::valarray<std::valarray<double>> Omega;

   void applyBoundaryConditions(std::valarray<double>, double, std::valarray<double>);
   void applyInitialCondition();
   double u0(std::valarray<double>, std::valarray<double>);
   double sigmaS(std::valarray<double>, double, std::valarray<double>);
   double sigmaT(std::valarray<double>, double, std::valarray<double>);

public:
   Domain(const int& nbDim, const std::valarray<std::valarray<double>>& Om);
   Domain();
   ~Domain();
};
