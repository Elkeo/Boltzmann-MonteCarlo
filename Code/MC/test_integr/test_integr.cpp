#include "../main.hpp"
#include "../population.hpp"

/*
  code.
*/

int main(int argc, char const* argv[])
{

   /* Déclaration - initialisation des variables */

   struct struct_parameters parameters;
   init_parameters(parameters);
   /* Création du domaine où les particules se meuvent */


   std::valarray<Vecteur> Omega(parameters.nbDims);
   for (int i = 0; i < parameters.nbDims; i++)
   {
      Vecteur dimDomain = { -1, 1 };
      Omega[i] = dimDomain;
   }
   GenericDomain* Domaine = NULL;
   Domaine = new PeriodicDomain(parameters, Omega);

   /* Création de la solution u(x, t, v) */
   double u(0.0);

   /* Création de la population de particules (fictives) */
   Population packOfParticles(Domaine, parameters, u);

   /* Les particules (fictives) évoluent */
   packOfParticles.move();

   /* On en déduit la solution u(x, t, v) */


   return 0;
}