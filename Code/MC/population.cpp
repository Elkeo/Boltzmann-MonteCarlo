#include "population.hpp"


/* Constructeur par défaut de la classe Population */
Population::Population(int nMC, const std::valarray<double>& x, const double& t, const std::valarray<double>& v, double& u) :
   nbParticles(nMC),
   _u(u),
   _t(t),
   _x(x),
   _v(v)
{
};

/* Destructeur par défaut */
Population::~Population()
{
};

/* Fonction qui fait évoluer une particule plein de fois */
void Population::move()
{
   /* On créé une particule (pas besoin d'en faire plein, elles ont toutes les mêmes conditions initiales) */
   Particle particle(nbParticles, _x, _t, _v);

   /* La particule est "envoyée" évoluer plein de fois */
   for (int i = 0; i < nbParticles; i++)
   {
      particle.move(_u);
   }
};
