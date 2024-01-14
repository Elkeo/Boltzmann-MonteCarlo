#include "main.hpp"
#include "particles.hpp"
#include "parameters.hpp"



/* CLASSE DÉFINISSANT LES PAQUETS DE PARTICULES */
class Population
{
private:
   const GenericDomain* _Domain;
   const struct_parameters _parameters;
   const int _nbParticles;
   double _u;
   Vecteur _x;

public:
   Population(const GenericDomain*, const struct_parameters& parameters, double& u, const Vecteur& x);
   ~Population();

   void move();
   const double& get_u() const { return this->_u; };
};