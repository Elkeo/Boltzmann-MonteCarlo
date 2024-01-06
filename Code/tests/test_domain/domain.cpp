#include "domain.hpp"
#include "parametres.hpp"

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
   double u_0(0.0);
   return u_0;
};

double Domain::sigmaS(const Vecteur& xp, const double& t, const Vecteur& vp)
{
   double sigmas = Parametres::SigmaS;
   return sigmas;
};

double Domain::sigmaT(const Vecteur& xp, const double& t, const Vecteur& vp)
{
   double sigmat = Parametres::SigmaT;
   return sigmat;
};


// Sample the velocity V′ of particle p from P_V'^s(xp, sp, τ, vp, v′)dv′
Vecteur Domain::sampleVprime(const Vecteur& xp, const double& sp, const double& tau, const Vecteur& vp)
{
   Vecteur vprime(xp.size(), 1.0);

   return vprime;
};

// Sample τ from the distribution having probability measure fτ(xp, sp, s, vp)ds
double Domain::sampleTau(const Vecteur& xp, const double& sp, const Vecteur& vp)
{
   double tau(1.0);

   return tau;
};
