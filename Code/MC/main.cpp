#include "main.hpp"

int main(int argc, char const* argv[])
{
   int d = 1;
   return 0;
}

class Domain
{
public:
   int d;
   std::valarray<std::valarray<double>> Omega;
   void applyBoundaryConditions(std::valarray<double>, double, std::valarray<double>);
   void applyInitialCondition();
public:
   Domain(const std::valarray<std::valarray<double>> Om, int nbDim);
   ~Domain();
};

Domain::Domain(const std::valarray<std::valarray<double>> Om, int nbDim) : Omega(Om), d(nbDim)
{
}

Domain::~Domain()
{
}

// Here a general function for the application of arbitrary boundary conditions
void Domain::applyBoundaryConditions(std::valarray<double> xp, double sp, std::valarray<double> vp)
{

};

// Objet Particule singulière
class Particle : public Domain
{
protected:
   double sp;
   double wp;
   std::valarray<double> xp;
   std::valarray<double> vp;
   std::valarray<double> u;

   double sampleTau();
public:
   Particle(int, int);
   ~Particle();
   void notIn(Domain Dom);
};

// Constructeur par défaut : on initialise les vecteurs avec leur nombre de dimensions.
Particle::Particle(int nbDim, int nMC) :
   sp(0.0),
   wp(1.0 / nMC),
   xp(std::valarray<double>(nbDim, 0.0)),
   vp(std::valarray<double>(nbDim, 0.0)),
   u(std::valarray<double>(nbDim, 0.0))
{
};

// Destructeur par défaut
Particle::~Particle()
{
};

Particle::notIn(Domain Dom)
{
   for (size_t i = 0; i < d; i++)
   {
      if (not (Omega[i][1] <= xp[i] <= Omega[i][2]))
      {
         return true;
      }
   }
};

// Sample τ from the distribution having probability measure fτ(xp, sp, s, vp)ds
double sampleTau()
{

};

// Objet Population de particules singulières (essentiellement un tableau de particules)
class Population : public Particle
{
protected:
   const int nbParticles;
   std::valarray<Particle> particlePopulation;
public:
   Population(int, int);
   ~Population();
   void move(double);
};

Population::Population(int nbDim, int nMC) : nbParticles(nMC), particlePopulation(std::valarray<Particle>(nMC))
{
};

Population::~Population()
{
};

void Population::move(double t)
{
   for (size_t i = 0; i < nbParticles; i++)
   {
      particlePopulation[i].move(t);
      double tau;
      while ((sp > 0) and (wp > 0))
      {
         if (Particle.notIn(Domain::Omega))
         {
            Domain::applyBoundaryConditions(xp, sp, vp);
         }
         tau = sampleTau();
         if (tau > sp)
         {
            // See the treatment in factor of 1[t, ∞[(τ)in (9.24)
            // Move the particle
            xp += sp * vp;

            // Set the life time of particle p to zero
            sp = 0;

            // Do not change the velocity of particle
            // Do not change the weight of particle
            // Tally the contribution of particle
            u += wp * u0(xp, vp);

         }
         else
         {
            // See the recursive treatment in factor of 1[0, t](τ) in (9.24)
            // Change the particle weight
            wp *= sigmaS(xp, sp - tau, vp) / sigmaT(xp, sp - t, vp);

            // Sample the velocity V′ of particle p from PVs ′)'"a(xp, sp, τ, vp, v′)dv′
            vp = sampleVprime();

            // Move the particle
            xp += vp * tau;

            // Set the life time of particle
            sp -= tau;
         }

      }
   }
};

