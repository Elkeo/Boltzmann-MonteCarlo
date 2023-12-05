#include "main.hpp"

int main(int argc, char const* argv[])
{
   //int d = 1;
   return 0;
}


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
   Domain(const std::valarray<std::valarray<double>> Om, int nbDim);
   Domain();
   ~Domain();
};
Domain::Domain() {};

Domain::Domain(const std::valarray<std::valarray<double>> Om, int nbDim) : Omega(Om), d(nbDim)
{
};

Domain::~Domain()
{
};

// Here a general function for the application of arbitrary boundary conditions
void Domain::applyBoundaryConditions(std::valarray<double> xp, double sp, std::valarray<double> vp)
{

};


// Objet Population de particules singulières (essentiellement un tableau de particules)
class Population : public Domain
{
protected:
   const int nbParticles;
   double u;
   std::valarray<double> x, v, t;

public:
   Population();
   Population(int, int);
   ~Population();

   virtual void move(double);
};

// Objet Particule singulière
class Particle : public Population
{
private:
   double sp;
   double wp;
   std::valarray<double> xp;
   std::valarray<double> vp;

   std::valarray<double> sampleVprime(std::valarray<double>, double, double, std::valarray<double>);
   double sampleTau(std::valarray<double>, double, std::valarray<double>);

protected:

   bool notInDomain();

public:
   Particle(int, int);
   ~Particle();
   virtual void move(double);
};

Population::Population(int nbDim, int nMC) : nbParticles(nMC)
{
};

Population::~Population()
{
};

void Population::move(double t)
{
   for (int i = 0; i < nbParticles; i++)
   {
      Particle particle(d, nbParticles);
      particle.move(t);
   }
};

// Constructeur par défaut : on initialise les vecteurs avec leur nombre de dimensions.
Particle::Particle(int nbDim, int nMC) :
   sp(0.0),
   wp(1.0 / nMC),
   xp(std::valarray<double>(nbDim, 0.0)),
   vp(std::valarray<double>(nbDim, 0.0))
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
      if (not ((Omega[i][1] <= xp[i]) and (xp[i] <= Omega[i][2])))
      {
         return true;
      }
   }
   return false;
};

void Particle::move(double t)
{
   double tau;
   while ((sp > 0) and (wp > 0))
   {
      if (Particle::notInDomain())
      {
         applyBoundaryConditions(xp, sp, vp);
      }
      tau = sampleTau(xp, sp, vp);
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
         vp = sampleVprime(xp, sp, tau, vp);

         // Move the particle
         xp += vp * tau;

         // Set the life time of particle
         sp -= tau;
      }

   }
}

std::valarray<double> Particle::sampleVprime(std::valarray<double> xp, double sp, double tau, std::valarray<double> vp)
{
   std::valarray<double> vprime(xp.size(), 0.0);

   return vprime;
};

// Sample τ from the distribution having probability measure fτ(xp, sp, s, vp)ds
double Particle::sampleTau(std::valarray<double> xp, double sp, std::valarray<double> vp)
{
   double tau(0.0);

   return tau;
};

