#include "population.hpp"


/* Constructeur par défaut de la classe Population */
Population::Population(const GenericDomain* Domain, const struct_parameters &parameters, double& u) :
   _Domain(Domain),
   _parameters(parameters),
   _nbParticles(parameters.nbMC),
   _u(u)
{
};

/* Destructeur par défaut */
Population::~Population()
{
};

/* Fonction qui fait évoluer plein de particules */
void Population::move()
{
   for (int i = 0; i < this->_parameters.nbMC; i++)
   {
      /* On créé une particule */
      Particle particle(this->_Domain, this->_parameters);
      /* La particule est "envoyée" évoluer */
      particle.move(_u);
   }
};
