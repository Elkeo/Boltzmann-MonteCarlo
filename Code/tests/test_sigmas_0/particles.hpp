#ifndef PARTICLES_HPP
#define PARTICLES_HPP

#include "domain.hpp"  // Include GenericDomain
#include "parameters.hpp"  // Include struct_parameters
#include "main.hpp"

/* CLASSE DÉFINISSANT UNE PARTICULE UNIQUE */
class Particle
{
private:
   const GenericDomain* _Domain;
   const struct_parameters _parameters;
   double _sp, _wp, _t;
   Vecteur _xp;
   Vecteur _vp;

public:
   bool notInDomain();

public:
   Particle(const GenericDomain*, const struct_parameters &parameters);
   ~Particle();
   virtual void move(double&);
};

#endif // DOMAIN_HPP