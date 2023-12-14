#include "population.hpp"


/* Constructeur par défaut de la classe Population */
Population::Population(const GenericDomain* Domain, const int nMC, const Vecteur& x, const double& t, const Vecteur& v, double& u) :
   _Domain(Domain),
   _nbParticles(nMC),
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

/* Fonction qui fait évoluer plein de particules */
void Population::move()
{
   for (int i = 0; i < _nbParticles; i++)
   {
      /* On créé une particule */
      Particle particle(_Domain, _nbParticles, _x, _t, _v);
      /* La particule est "envoyée" évoluer */
      particle.move(_u);
   }
};
