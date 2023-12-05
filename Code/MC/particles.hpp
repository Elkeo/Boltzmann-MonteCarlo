#include "main.hpp"
#include "domain.hpp"

/* CLASSE DÉFINISSANT UNE PARTICULE UNIQUE */
class Particle : public Domain
{
private:
   double _sp, _wp, _t;
   std::valarray<double> _xp;
   std::valarray<double> _vp;

   std::valarray<double> sampleVprime(std::valarray<double>, double, double, std::valarray<double>);
   double sampleTau(std::valarray<double>, double, std::valarray<double>);

protected:
   bool notInDomain();

public:
   Particle(const int&, const std::valarray<double>&, const double&, const std::valarray<double>&);
   ~Particle();
   virtual void move(double&);
};