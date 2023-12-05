#include "main.hpp"
#include "domain.hpp"

/* CLASSE DÉFINISSANT UNE PARTICULE UNIQUE */
class Particle : public Domain
{
private:
   double _sp, _wp, _t;
   Vecteur _xp;
   Vecteur _vp;

protected:
   bool notInDomain();

public:
   Particle(const int&, const Vecteur&, const double&, const Vecteur&);
   ~Particle();
   virtual void move(double&);
};