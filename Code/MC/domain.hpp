#include "main.hpp"


/* CLASSE DÉFINISSANT LE DOMAINE DANS LEQUEL LE PAQUET DE PARTICULE ÉVOLUE */
class GenericDomain
{
protected:
   int _d;
   std::valarray<Vecteur> _Omega;
   std::valarray<Vecteur> _xCoords, _yCoords;

public:
   /* Constructeurs et destructeurs par défaut */
   GenericDomain(const int& nbDim, const std::valarray<Vecteur>& Om);
   virtual ~GenericDomain();

   /* Fonctions membres */
   double initialCondition(const Vecteur&, const Vecteur&) const;
   virtual void applyBoundaryConditions(Vecteur&, double&, Vecteur&) const = 0;
   void applyInitialCondition() const;
   double sigmaS(const Vecteur&, const double&, const Vecteur&) const;
   double sigmaT(const Vecteur&, const double&, const Vecteur&) const;
   double sampleTau(const Vecteur&, const double&, const Vecteur&) const;
   Vecteur sampleVprime(const Vecteur&, const double&, const double&, const Vecteur&) const;

   /* Accesseurs */
   const int& get_d() const { return _d; }
   const std::valarray<Vecteur>& get_Omega() const { return _Omega; }
};

/* Domaine avec conditions de bords périodiques */
class PeriodicDomain : public GenericDomain
{
public:
   /* Constructeurs et destructeurs par défaut */
   PeriodicDomain(const int& nbDim, const std::valarray<Vecteur>& Om) : GenericDomain(nbDim, Om) {};
   virtual ~PeriodicDomain();

   virtual void applyBoundaryConditions(Vecteur&, double&, Vecteur&) const;
};

/* Domaine avec choc élastique aux parois */
class ElasticDomain : public GenericDomain
{
public:
   /* Constructeurs et destructeurs par défaut */
   ElasticDomain(const int& nbDim, const std::valarray<Vecteur>& Om) : GenericDomain(nbDim, Om) {};
   virtual ~ElasticDomain();

   virtual void applyBoundaryConditions(Vecteur&, double&, Vecteur&) const;
};