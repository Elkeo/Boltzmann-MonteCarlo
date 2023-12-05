#include "main.hpp"
#include "particles.hpp"


/* CLASSE DÉFINISSANT LES PAQUETS DE PARTICULES */
class Population : public Domain
{
protected:
   const int nbParticles;
   double _u, _t;
   const Vecteur _x, _v;

public:
   Population(int, const Vecteur&, const double&, const Vecteur&, double& u);
   ~Population();

   virtual void move();
   const double& get_u() const { return _u; };
};