#include "domain.hpp"

Domain::Domain() {};

Domain::Domain(const int& nbDim, const std::valarray<std::valarray<double>>& Om) : d(nbDim), Omega(Om)
{
};

Domain::~Domain()
{
};

// Here a general function for the application of arbitrary boundary conditions
void Domain::applyBoundaryConditions(std::valarray<double> xp, double sp, std::valarray<double> vp)
{
};

double Domain::u0(std::valarray<double> xp, std::valarray<double> vp)
{
   double u_0(0.0);
   return u_0;
};

double Domain::sigmaS(std::valarray<double>xp, double t, std::valarray<double> vp)
{
   double sigmas(1.0);
   return sigmas;
};

double Domain::sigmaT(std::valarray<double> xp, double t, std::valarray<double> vp)
{
   double sigmat(1.0);
   return sigmat;
};