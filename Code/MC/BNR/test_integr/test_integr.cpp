#include "../../population.hpp"
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <valarray>
#include <random>
#include <iostream>
#include <fstream>

using namespace std;



int main(int argc, char const* argv[])
{

   /* Déclaration - initialisation des variables */

   struct struct_parameters parameters;
   parameters.fileName =  "param.toml";

   init_parameters(parameters);

   /* Ouverture d'un fichier pour stocker la solution */

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


   double somme=0.0;
   double U0=0.0;

   double dx,dy,dz;
   dx=(parameters.array_x[1]-parameters.array_x[0])/parameters.nbPtsX;
   dy=(parameters.array_y[1]-parameters.array_y[0])/parameters.nbPtsY;
   dz=(parameters.array_z[1]-parameters.array_z[0])/parameters.nbPtsZ;

   if(parameters.nbDims==3){

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
               U0+=Domaine->initialCondition({ x, y, z }, { 0.0, 0.0, 0.0 });

               somme+=u[i][j][k];
            }
         }
      }


      
      U0=U0*dx*dy*dz/((parameters.array_x[1]-parameters.array_x[0])*(parameters.array_y[1]-parameters.array_y[0])*(parameters.array_z[1]-parameters.array_z[0]));

      double U;
      U=somme/((parameters.array_x[1]-parameters.array_x[0])*(parameters.array_y[1]-parameters.array_y[0])*(parameters.array_z[1]-parameters.array_z[0]));

      double erreur;
      erreur=U-(U0*exp(-parameters.modV*(parameters.sigmaT-parameters.sigmaS)*parameters.finalTime));
      erreur=abs(erreur);

      delete Domaine;
      std::cout << "\n"<<std::endl;
      std::cout << "########################"<<std::endl;
      std::cout << "Test intégrale" << std::endl;
      std::cout << "erreur = "<< erreur << " U= "<< U <<" U0 =" << U0<< endl;
      std::cout << "########################"<<std::endl;
      std::cout << "\n"<<std::endl;


   }


   if(parameters.nbDims==2){

      /* Création de la solution u(x, t, v) */
      std::valarray<double> ligne(0.0, parameters.nbPtsY);

      std::valarray<std::valarray<double>> u(ligne, parameters.nbPtsX);
      double somme=0;
      for (int i = 0; i < parameters.nbPtsX; i++)
      {
         for (int j = 0; j < parameters.nbPtsY; j++)
         {

               double x = parameters.array_x[0] + (i + 0.5) * (parameters.array_x[1] - parameters.array_x[0]) / (parameters.nbPtsX);
               double y = parameters.array_y[0] + (j + 0.5) * (parameters.array_y[1] - parameters.array_y[0]) / (parameters.nbPtsY);

               /* Création de la population de particules (fictives) */
               
               Population packOfParticles(Domaine, parameters, u[i][j], { x, y });

               /* Les particules (fictives) évoluent */
               packOfParticles.move();

               /* On en déduit la solution u(x, t, v) */
               u[i][j] = packOfParticles.get_u();
               somme+=u[i][j];
         }
      }

      Vecteur x(2,0); 
      Vecteur v(2); 
      double U0;
      U0=Domaine->initialCondition(x, v)*parameters.nbPtsX*parameters.nbPtsY;
      U0=U0*dx*dy/((parameters.array_x[1]-parameters.array_x[0])*(parameters.array_y[1]-parameters.array_y[0]));

      double U;
      U=somme/((parameters.array_x[1]-parameters.array_x[0])*(parameters.array_y[1]-parameters.array_y[0]));

      double erreur;
      erreur=U-(U0*exp(-parameters.modV*(parameters.sigmaT-parameters.sigmaS)*parameters.time));
      erreur=abs(erreur);

      delete Domaine;
      std::cout << "\n"<<std::endl;
      std::cout << "########################"<<std::endl;
      std::cout << "Test intégrale" << std::endl;
      std::cout << "erreur = "<< erreur << " U= "<< U <<" U0 =" << U0<< endl;
      std::cout << "########################"<<std::endl;
      std::cout << "\n"<<std::endl;

   }

      if(parameters.nbDims==1){

      /* Création de la solution u(x, t, v) */

      std::valarray<double> u(parameters.nbPtsX);
      double somme=0;
      for (int i = 0; i < parameters.nbPtsX; i++)
      {


         double x = parameters.array_x[0] + (i + 0.5) * (parameters.array_x[1] - parameters.array_x[0]) / (parameters.nbPtsX);

         /* Création de la population de particules (fictives) */
               
         Population packOfParticles(Domaine, parameters, u[i], { x });

         /* Les particules (fictives) évoluent */
         packOfParticles.move();

         /* On en déduit la solution u(x, t, v) */
         u[i]= packOfParticles.get_u();
         somme+=u[i];
         
      }

      Vecteur x(1,0); 
      Vecteur v(1); 
      double U0;
      U0=Domaine->initialCondition(x, v)*parameters.nbPtsX*parameters.nbPtsY*parameters.nbPtsZ;
      U0=U0*dx/(parameters.array_x[1]-parameters.array_x[0]);

      double U;
      U=somme/(parameters.array_x[1]-parameters.array_x[0]);

      double erreur;
      erreur=U-(U0*exp(-parameters.modV*(parameters.sigmaT-parameters.sigmaS)*parameters.time));
      erreur=abs(erreur);

      delete Domaine;
      std::cout << "\n"<<std::endl;
      std::cout << "########################"<<std::endl;
      std::cout << "Test intégrale" << std::endl;
      std::cout << "erreur = "<< erreur << " U= "<< U <<" U0 =" << U0<< endl;
      std::cout << "########################"<<std::endl;
      std::cout << "\n"<<std::endl;

   }





   return 0;
}