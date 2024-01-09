#include "main.hpp"
#include "population.hpp"

/*
   Ce code résout l'équation intégro-différentielle de
   Boltzmann par un schéma semi-analogue de Monte-Carlo.
*/

int main(int argc, char const* argv[])
{
   /* Déclaration - initialisation des variables */
   int
      d = 2,      // Nombre de dimensions
      nMC = 10;   // Nombre de particules dans les paquets (permet la bonne charge quand parallélisation)

   /* Création du domaine où les particules se meuvent */
   std::valarray<Vecteur> Omega(d);
   Vecteur nbNodesInDimension(d);
   for (int i = 0; i < d; i++)
   {
      Vecteur dimDomain = { -1, 1 };
      Omega[i] = dimDomain;
   }
   GenericDomain* Domaine = NULL;
   Domaine = new PeriodicDomain(d, Omega);

   /* Création du temps, de la position et de la vitesse initiaux de la population de particules */
   // ATTENTION : on masque u0 en initialisant comme cela
   double t = 1.0;               // Temps pour lequel on veut calculer la solution
   Vecteur x = Vecteur(d, 0.0);  // Position pour laquelle on veut calculer la solution (ici au centre)
   Vecteur v = Vecteur(d, 1.0);  // Vitesse initiale pour laquelle on veut calculer la solution

   /* Création de la solution u(x, t, v) */
   double u(0.0);

   /* Création de la population de particules (fictives) */
   Population packOfParticles(Domaine, nMC, x, t, v, u);

   /* Les particules (fictives) évoluent */
   packOfParticles.move();

   /* On en déduit la solution u(x, t, v) */
   u = packOfParticles.get_u();
   std::cout << "Solution en x, t, v : " << u << std::endl;

   return 0;
}