#include "main.hpp"


/* CLASSE DÉFINISSANT LE DOMAINE DANS LEQUEL LE PAQUET DE PARTICULE ÉVOLUE */
class Domain
{
protected:
   int d;
   std::valarray<Vecteur> Omega;

   void applyBoundaryConditions(const Vecteur&, const double&, const Vecteur&);
   void applyInitialCondition();
   double sigmaS(const Vecteur&, const double&, const Vecteur&);
   double sigmaT(const Vecteur&, const double&, const Vecteur&);
   double sampleTau(const Vecteur&, const double&, const Vecteur&);
   Vecteur sampleVprime(const Vecteur&, const double&, const double&, const Vecteur&);

public:
   double u0(const Vecteur&, const Vecteur&);
   Domain(const int& nbDim, const std::valarray<Vecteur>& Om);
   Domain();
   ~Domain();
};
