#include "main.hpp"
#include "particles.hpp"
#include "parameters.hpp"


// Constructeur par défaut : on initialise les vecteurs avec leur nombre de dimensions.
Particle::Particle(const GenericDomain* Domain, const struct_parameters& parameters, const Vecteur& x) :
   _Domain(Domain),
   _parameters(parameters),
   _sp(parameters.time),
   _wp(1.0 / parameters.nbMC),
   _xp(x),
   _vp(parameters.array_v)
{
};

// Destructeur par défaut
Particle::~Particle()
{
};

bool Particle::notInDomain()
{
   for (int i = 0; i < this->_Domain->get_d(); i++)
   {
      if (not ((this->_Domain->get_Omega()[i][0] <= _xp[i]) and (this->_xp[i] <= this->_Domain->get_Omega()[i][1])))
      {
         return true;
      }
   }
   return false;
};

void Particle::move(double& u)
{
   double tau;
   while ((this->_sp > 0) and (this->_wp > 0))
   {
      if (Particle::notInDomain())
      {
         // La condition de test est redondante
         this->_Domain->applyBoundaryConditions(this->_xp, this->_sp, this->_vp);
      }
      tau = this->_Domain->sampleTau(this->_xp, this->_sp, this->_vp);
      if (tau > this->_sp)
      {
         // See the treatment in factor of 1[t, ∞[(τ)in (9.24)
         // Move the particle
         this->_xp += this->_sp * this->_vp;

         // Set the life time of particle p to zero
         this->_sp = 0;

         // Do not change the velocity of particle
         // Do not change the weight of particle
         // Tally the contribution of particle
         u += this->_wp * this->_Domain->initialCondition(this->_xp, this->_vp);
      }
      else
      {
         // See the recursive treatment in factor of 1[0, t](τ) in (9.24)
         // Change the particle weight
         this->_wp *= this->_Domain->sigmaS(this->_xp, this->_sp - tau, this->_vp) / this->_Domain->sigmaT(this->_xp, this->_sp - tau, this->_vp);

         // Sample the velocity V′ of particle p from P_V'^s(xp, sp, τ, vp, v′)dv′
         this->_vp = this->_Domain->sampleVprime(this->_xp, this->_sp, tau, this->_vp);

         // Move the particle
         this->_xp += this->_vp * tau;

         // Set the life time of particle
         this->_sp -= tau;
      }

   }
}