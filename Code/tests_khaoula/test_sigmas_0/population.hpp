#include "main.hpp"
#include "particles.hpp"


/* CLASSE DÉFINISSANT LES PAQUETS DE PARTICULES */
class Population
{
private:
   const GenericDomain* _Domain;
   const int _nbParticles;
   double _u, _t;
   const Vecteur _x, _v;

public:
   Population(const GenericDomain*, const int, const Vecteur&, const double&, const Vecteur&, double& u);
   ~Population();

   void move();
   const double& get_u() const { return _u; };
};