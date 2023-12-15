#include "domain.hpp"
#include "parametres.hpp"

GenericDomain::GenericDomain(const int& nbDim, const std::valarray<Vecteur>& Om) : _d(nbDim), _Omega(Om)
{
};

GenericDomain::~GenericDomain()
{
};

ElasticDomain::~ElasticDomain()
{
};

PeriodicDomain::~PeriodicDomain()
{
};

// Here a general function for the application of arbitrary boundary conditions
void ElasticDomain::applyBoundaryConditions(Vecteur& xp, double& sp, Vecteur& vp) const
{
   // Choc élastique sur les parois
   for (int i = 0; i < _d; i++)
   {
      if (xp[i] < _Omega[i][0])
      {
         xp[i] = _Omega[i][0];
         vp[i] *= -1;
      }
      else if (xp[i] > _Omega[i][1])
      {
         xp[i] = _Omega[i][1];
         vp[i] *= -1;
      }
   }
};

void PeriodicDomain::applyBoundaryConditions(Vecteur& xp, double& sp, Vecteur& vp) const
{
   for (int i = 0; i < _d; i++)
   {
      if (xp[i] < _Omega[i][0])
      {
         xp[i] += (_Omega[i][1] - _Omega[i][0]);
      }
      else if (xp[i] > _Omega[i][1])
      {
         xp[i] -= (_Omega[i][1] - _Omega[i][0]);
      }
   }
};

double GenericDomain::initialCondition(const Vecteur& x, const Vecteur& v) const
{
   double u_0(5.0);
   return u_0;
};

double GenericDomain::sigmaS(const Vecteur& xp, const double& t, const Vecteur& vp) const
{
   double sigmas = Parametres::SigmaS;
   return sigmas;
};

double GenericDomain::sigmaT(const Vecteur& xp, const double& t, const Vecteur& vp) const
{
   double sigmat = Parametres::SigmaT;
   return sigmat;
};


// Sample the velocity V′ of particle p from P_V'^s(xp, sp, τ, vp, v′)dv′
Vecteur GenericDomain::sampleVprime(const Vecteur& xp, const double& sp, const double& tau, const Vecteur& vp) const
{
   double normV = 1.0;
   Vecteur vprime(vp.size(), 0.0);

   // Création du générateur de nombre aléatoires
   std::default_random_engine generator;

   if (_d == 1)
   {
      // tirage uniforme sur [-1, 1]
      std::uniform_real_distribution<double> distribution(-1, 1);

      vprime = { normV * distribution(generator) };
   }
   else if (_d == 2)
   {
      // tirage uniforme sur le cercle unité
      std::uniform_real_distribution<double> distribution(0, 2 * M_PI);
      double theta = distribution(generator);
      vprime = { normV * cos(theta), normV * sin(theta) };
   }
   else if (_d == 3)
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
double GenericDomain::sampleTau(const Vecteur& xp, const double& sp, const Vecteur& vp) const
{
   std::default_random_engine generator;
   std::uniform_real_distribution<double> distribution(0, 1);

   return -log(distribution(generator)) / sqrt((vp * vp).sum());
};
