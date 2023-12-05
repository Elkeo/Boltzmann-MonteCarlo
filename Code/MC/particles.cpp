#include "main.hpp"
#include "particles.hpp"

// Constructeur par défaut : on initialise les vecteurs avec leur nombre de dimensions.
Particle::Particle(const int& nMC, const std::valarray<double>& x, const double& t, const std::valarray<double>& v) :
   _sp(0.0),
   _wp(1.0 / nMC),
   _t(t),
   _xp(x),
   _vp(v)
{
};

// Destructeur par défaut
Particle::~Particle()
{
};

bool Particle::notInDomain()
{
   for (int i = 0; i < d; i++)
   {
      if (not ((Omega[i][1] <= _xp[i]) and (_xp[i] <= Omega[i][2])))
      {
         return true;
      }
   }
   return false;
};

void Particle::move(double& u)
{
   double tau;
   while ((_sp > 0) and (_wp > 0))
   {
      if (Particle::notInDomain())
      {
         Domain::applyBoundaryConditions(_xp, _sp, _vp);
      }
      tau = sampleTau(_xp, _sp, _vp);
      if (tau > _sp)
      {
         // See the treatment in factor of 1[t, ∞[(τ)in (9.24)
         // Move the particle
         _xp += _sp * _vp;

         // Set the life time of particle p to zero
         _sp = 0;

         // Do not change the velocity of particle
         // Do not change the weight of particle
         // Tally the contribution of particle
         u += _wp * u0(_xp, _vp);

      }
      else
      {
         // See the recursive treatment in factor of 1[0, t](τ) in (9.24)
         // Change the particle weight
         _wp *= sigmaS(_xp, _sp - tau, _vp) / sigmaT(_xp, _sp - _t, _vp);

         // Sample the velocity V′ of particle p from P_V'^s(xp, sp, τ, vp, v′)dv′
         _vp = sampleVprime(_xp, _sp, tau, _vp);

         // Move the particle
         _xp += _vp * tau;

         // Set the life time of particle
         _sp -= tau;
      }

   }
}

// Sample the velocity V′ of particle p from P_V'^s(xp, sp, τ, vp, v′)dv′
std::valarray<double> Particle::sampleVprime(std::valarray<double> xp, double sp, double tau, std::valarray<double> vp)
{
   std::valarray<double> vprime(xp.size(), 1.0);

   return vprime;
};

// Sample τ from the distribution having probability measure fτ(xp, sp, s, vp)ds
double Particle::sampleTau(std::valarray<double> xp, double sp, std::valarray<double> vp)
{
   double tau(1.0);

   return tau;
};
