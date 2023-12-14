#include "main.hpp"
#include "domain.hpp"

/* CLASSE DÉFINISSANT UNE PARTICULE UNIQUE */
class Particle
{
private:
   const GenericDomain* _Domain;
   double _sp, _wp, _t;
   Vecteur _xp;
   Vecteur _vp;

public:
   bool notInDomain();

public:
   Particle(const GenericDomain*, const int&, const Vecteur&, const double&, const Vecteur&);
   ~Particle();
   virtual void move(double&);
};