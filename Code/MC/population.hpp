#include "main.hpp"
#include "particles.hpp"


/* CLASSE DÉFINISSANT LES PAQUETS DE PARTICULES */
class Population : public Domain
{
protected:
   const int nbParticles;
   double _u, _t;
   const std::valarray<double> _x, _v;

public:
   Population(int, const std::valarray<double>&, const double&, const std::valarray<double>&, double& u);
   ~Population();

   virtual void move();
   const double& get_u() const { return _u; };
};