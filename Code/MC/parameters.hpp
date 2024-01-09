#ifndef PARAMETRES_HPP
#define PARAMETRES_HPP

#include <valarray>

struct struct_parameters{
    //Simuation parameters
    int nbDims; //Number of dimensions
    int nbMC; //Number of MC particles 
    double time; //Time of the wanted result 

    std::valarray<double> array_x;
    std::valarray<double> array_v;


    //Phisical parameters
    double sigmaS; 
    double sigmaT;
    double modV;
};

void init_parameters(struct struct_parameters* parameters_1);

#endif
