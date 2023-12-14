#include "main.hpp"
#include "particles.hpp"

// Constructeur par défaut : on initialise les vecteurs avec leur nombre de dimensions.
Particle::Particle(const GenericDomain* Domain, const int& nMC, const Vecteur& x, const double& t, const Vecteur& v) :
   _Domain(Domain),
   _sp(t),
   _wp(1.0 / nMC),
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
   for (int i = 0; i < _Domain->get_d(); i++)
   {
      if (not ((_Domain->get_Omega()[i][0] <= _xp[i]) and (_xp[i] <= _Domain->get_Omega()[i][1])))
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
         // La condition de test est redondante
         _Domain->applyBoundaryConditions(_xp, _sp, _vp);
      }
      tau = _Domain->sampleTau(_xp, _sp, _vp);
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
         u += _wp * _Domain->initialCondition(_xp, _vp);
      }
      else
      {
         // See the recursive treatment in factor of 1[0, t](τ) in (9.24)
         // Change the particle weight
         _wp *= _Domain->sigmaS(_xp, _sp - tau, _vp) / _Domain->sigmaT(_xp, _sp - tau, _vp);

         // Sample the velocity V′ of particle p from P_V'^s(xp, sp, τ, vp, v′)dv′
         _vp = _Domain->sampleVprime(_xp, _sp, tau, _vp);

         // Move the particle
         _xp += _vp * tau;

         // Set the life time of particle
         _sp -= tau;
      }

   }
}