#ifndef POPULATION_HPP
#define POPULATION_HPP

#include "domain.hpp"  // Include GenericDomain
#include "parameters.hpp"  // Include struct_parameters
#include "main.hpp"
#include "particles.hpp"




/* CLASSE DÉFINISSANT LES PAQUETS DE PARTICULES */
class Population
{
private:
   const GenericDomain* _Domain;
   const struct_parameters _parameters;
   const int _nbParticles;
   double _u;

public:
   Population(const GenericDomain*, const struct_parameters &parameters, double& u);
   ~Population();

   void move();
   const double& get_u() const { return this->_u; };
};

#endif // POPULATION_HPP