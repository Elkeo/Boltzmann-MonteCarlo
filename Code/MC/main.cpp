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
      delete Domaine;
      std::cout << "Domain type not recognized : choose \"elastic\" or \"periodic\"." << std::endl;
      exit(1);
   }

   /* Création de la solution u(x, t, v) */
   std::valarray<std::valarray<std::valarray<double>>> u(std::valarray<std::valarray<double>>(std::valarray<double>(0.0, parameters.nbPtsZ), parameters.nbPtsY), parameters.nbPtsX);

   for (int i = 0; i < parameters.nbPtsX; i++)
   {
      for (int j = 0; j < parameters.nbPtsY; j++)
      {
         for (int k = 0; k < parameters.nbPtsZ; k++)
         {
            double x = parameters.array_x[0] + (i + 0.5) * (parameters.array_x[1] - parameters.array_x[0]) / (parameters.nbPtsX);
            double y = parameters.array_y[0] + (j + 0.5) * (parameters.array_y[1] - parameters.array_y[0]) / (parameters.nbPtsY);
            double z = parameters.array_z[0] + (k + 0.5) * (parameters.array_z[1] - parameters.array_z[0]) / (parameters.nbPtsZ);

            /* Création de la population de particules (fictives) */
            Population packOfParticles(Domaine, parameters, u[i][j][k], { x, y, z });

            /* Les particules (fictives) évoluent */
            packOfParticles.move();

            /* On en déduit la solution u(x, t, v) */
            u[i][j][k] = packOfParticles.get_u();
            std::cout << "Solution en " << x << " " << y << " " << z << " : " << u[i][j][k] << std::endl;
         }
      }
   }



   delete Domaine;

   return 0;
}