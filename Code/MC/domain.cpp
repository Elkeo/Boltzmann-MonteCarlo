#include "domain.hpp"

Domain::Domain() {};

Domain::Domain(const int& nbDim, const std::valarray<Vecteur>& Om) : d(nbDim), Omega(Om)
{
};

Domain::~Domain()
{
};

// Here a general function for the application of arbitrary boundary conditions
void Domain::applyBoundaryConditions(const Vecteur& xp, const double& sp, const Vecteur& vp)
{
};

double Domain::u0(const Vecteur& xp, const Vecteur& vp)
{
   double u_0(5.0);
   return u_0;
};

double Domain::sigmaS(const Vecteur& xp, const double& t, const Vecteur& vp)
{
   double sigmas(1.0);
   return sigmas;
};

double Domain::sigmaT(const Vecteur& xp, const double& t, const Vecteur& vp)
{
   double sigmat(1.0);
   return sigmat;
};


// Sample the velocity V′ of particle p from P_V'^s(xp, sp, τ, vp, v′)dv′
Vecteur Domain::sampleVprime(const Vecteur& xp, const double& sp, const double& tau, const Vecteur& vp)
{
   double normV = 1.0;
   Vecteur vprime(vp.size(), 0.0);

   // Création du générateur de nombre aléatoires
   std::default_random_engine generator;

   if (d == 1)
   {
      // tirage uniforme sur [-1, 1]
      std::uniform_real_distribution<double> distribution(-1, 1);

      vprime = { normV * distribution(generator) };
   }
   else if (d == 2)
   {
      // tirage uniforme sur le cercle unité
      std::uniform_real_distribution<double> distribution(0, 2 * M_PI);
      double theta = distribution(generator);
      vprime = { normV * cos(theta), normV * sin(theta) };
   }
   else if (d == 3)
   {
      // tirage uniforme sur la sphère unité (composition de loi normales)
      // voir Daniel Saada - lois uniformes sur la sphère
      std::normal_distribution<double> distribution(0, 1);

      vprime[0] = distribution(generator);
      vprime[1] = distribution(generator);
      vprime[2] = distribution(generator);
      vprime = vprime / sqrt((pow(vprime, 2)).sum());
      vprime = normV * vprime;
   }

   return vprime;
};

// Sample τ from the distribution having probability measure fτ(xp, sp, s, vp)ds
double Domain::sampleTau(const Vecteur& xp, const double& sp, const Vecteur& vp)
{
   double tau(0.5);

   return tau;
};
