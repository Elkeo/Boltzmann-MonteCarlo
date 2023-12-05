#include "main.hpp"
#include "population.hpp"


int main(int argc, char const* argv[])
{
   /* Déclaration - initialisation des variables */
   int
      d = 1,      // Nombre de dimensions
      nMC = 10;   // Nombre de particules dans les paquets (permet la bonne charge quand parallélisation)

   /* Création du domaine où les particules se meuvent */
   std::valarray<std::valarray<double>> Omega(d);
   for (int i = 0; i < d; i++)
   {
      std::valarray<double> dimDomain = { -1, 1 };
      Omega[i] = dimDomain;
   }
   Domain Domaine(d, Omega);

   /* Création du temps, de la position et de la vitesse initiaux de la population de particules */
   double t = 1.0;                              // Temps pour lequel on veut calculer la solution
   std::valarray<double> x({ 0.0, 0.0, 0.0 });  // Position pour laquelle on veut calculer la solution (ici au centre)
   std::valarray<double> v({ 1.0, 0.0, 0.0 });  // Vitesse initiale pour laquelle on veut calculer la solution

   /* Création de la solution u(x, t, v) */
   double u(0.0);

   /* Création de la population de particules (fictives) */
   Population packOfParticles(nMC, x, t, v, u);

   /* Les particules (fictives) évoluent */
   packOfParticles.move();

   /* On en déduit la solution u(x, t, v) */
   u = packOfParticles.get_u();

   return 0;
}