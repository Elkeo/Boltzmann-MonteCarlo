#include "main.hpp"
#include "population.hpp"

/*
   Ce code résout l'équation intégro-différentielle de
   Boltzmann par un schéma semi-analogue de Monte-Carlo.
*/

int main(int argc, char const* argv[])
{

   /* Déclaration - initialisation des variables */

   struct struct_parameters parameters;
   init_parameters(parameters);


   /* Création du domaine où les particules se meuvent */
   std::valarray<Vecteur> Omega(parameters.nbDims);
   Omega[0] = parameters.array_x;
   if (parameters.nbDims >= 2) {
      Omega[1] = parameters.array_y;
      if (parameters.nbDims == 3) {
         Omega[2] = parameters.array_z;
      }
   }

   GenericDomain* Domaine = NULL;
   if (parameters.domainType == "elastic")
   {
      Domaine = new ElasticDomain(parameters, Omega);
   }
   else if (parameters.domainType == "periodic")
   {
      Domaine = new PeriodicDomain(parameters, Omega);
   }
   else
   {
      std::cout << "Domain type not recognized : choose \"elastic\" or \"periodic\"." << std::endl;
      exit(1);
   }

   /* Création de la solution u(x, t, v) */
   double u(0.0);

   /* Création de la population de particules (fictives) */
   Population packOfParticles(Domaine, parameters, u);

   /* Les particules (fictives) évoluent */
   packOfParticles.move();

   /* On en déduit la solution u(x, t, v) */
   u = packOfParticles.get_u();
   std::cout << "Solution en x, t, v : " << u << std::endl;

   return 0;
}