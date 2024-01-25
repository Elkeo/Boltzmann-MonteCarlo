#include "../../population.hpp"

/*
   Ce code résout l'équation intégro-différentielle de
   Boltzmann par un schéma semi-analogue de Monte-Carlo.
*/

int main(int argc, char const* argv[])
{
   /* Déclaration - initialisation des variables */
   struct struct_parameters parameters;
   parameters.fileName =  "param.toml";
   init_parameters(parameters);
   double nbIterations = ceil(parameters.finalTime / parameters.dt);

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
   std::valarray<std::valarray<std::valarray<double>>> u1(std::valarray<std::valarray<double>>(std::valarray<double>(0.0, parameters.nbPtsZ), parameters.nbPtsY), parameters.nbPtsX);

   std::valarray<std::valarray<std::valarray<double>>> u2(std::valarray<std::valarray<double>>(std::valarray<double>(0.0, parameters.nbPtsZ), parameters.nbPtsY), parameters.nbPtsX);
   for (int n = 0; n < nbIterations; n++)
   {

      for (int iter_i = 0; iter_i < parameters.nbPtsX; iter_i++)
      {
         for (int iter_j = 0; iter_j < parameters.nbPtsY; iter_j++)
         {
            for (int iter_k = 0; iter_k < parameters.nbPtsZ; iter_k++)
            {
               u1[iter_i][iter_j][iter_k] = 0.0;
               double x = parameters.array_x[0] + (iter_i + 0.5) * (parameters.array_x[1] - parameters.array_x[0]) / (parameters.nbPtsX);
               double y = parameters.array_y[0] + (iter_j + 0.5) * (parameters.array_y[1] - parameters.array_y[0]) / (parameters.nbPtsY);
               double z = parameters.array_z[0] + (iter_k + 0.5) * (parameters.array_z[1] - parameters.array_z[0]) / (parameters.nbPtsZ);

               /* Création de la population de particules (fictives) */
               Population packOfParticles(Domaine, parameters, u1[iter_i][iter_j][iter_k], { x, y, z });

               /* Les particules (fictives) évoluent */
               packOfParticles.move();

               /* On en déduit la solution u(x, t, v) */
               u1[iter_i][iter_j][iter_k] = packOfParticles.get_u();
            }
         }
      }
      parameters.time += parameters.dt;
   }

      for (int iter_n = 0; iter_n < nbIterations; iter_n++)
   {

      for (int iter_i = 0; iter_i < parameters.nbPtsX; iter_i++)
      {
         for (int iter_j = 0; iter_j < parameters.nbPtsY; iter_j++)
         {
            for (int iter_k = 0; iter_k < parameters.nbPtsZ; iter_k++)
            {
               u2[iter_i][iter_j][iter_k] = 0.0;
               double x = parameters.array_x[0] + (iter_i + 0.5) * (parameters.array_x[1] - parameters.array_x[0]) / (parameters.nbPtsX);
               double y = parameters.array_y[0] + (iter_j + 0.5) * (parameters.array_y[1] - parameters.array_y[0]) / (parameters.nbPtsY);
               double z = parameters.array_z[0] + (iter_k + 0.5) * (parameters.array_z[1] - parameters.array_z[0]) / (parameters.nbPtsZ);

               /* Création de la population de particules (fictives) */
               Population packOfParticles(Domaine, parameters, u2[iter_i][iter_j][iter_k], { x, y, z });

               /* Les particules (fictives) évoluent */
               packOfParticles.move();

               /* On en déduit la solution u(x, t, v) */
               u2[iter_i][iter_j][iter_k] = packOfParticles.get_u();
            }
         }
      }
      parameters.time += parameters.dt;
   }

   double somme;
   for (int iter_i = 0; iter_i < parameters.nbPtsX; iter_i++)
   {
      for (int iter_j = 0; iter_j < parameters.nbPtsY; iter_j++)
      {
         for (int iter_k = 0; iter_k < parameters.nbPtsZ; iter_k++)
         {
            somme+= u1[iter_i][iter_j][iter_k]*u1[iter_i][iter_j][iter_k]+u2[iter_i][iter_j][iter_k]*u2[iter_i][iter_j][iter_k];
         }
      }
   }
   double erreur;
   erreur=sqrt(somme)/parameters.nbPtsX*std::max(parameters.nbPtsY, 1)*std::max(parameters.nbPtsZ, 1);

   delete Domaine;

   std::cout << "\n"<<std::endl;

   std::cout << "########################"<<std::endl;
   std::cout << "Test de reproductibilité" << std::endl;
   std::cout << "Erreur entre les 2 solutions = " << erreur << std::endl;
   std::cout << "########################"<<std::endl;
   std::cout << "\n"<<std::endl;


   return 0;
}