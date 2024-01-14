#ifndef PARAMETRES_HPP
#define PARAMETRES_HPP

#include <valarray>

struct struct_parameters {
    //Simuation parameters
    int nbDims = 0; //Number of dimensions
    int nbMC = 0; //Number of MC particles 
    double time = 0; //Time of the wanted result 

    std::valarray<double> array_x;
    std::valarray<double> array_y;
    std::valarray<double> array_z;
    std::valarray<double> array_v;

    std::string domainType = "";

    //Phisical parameters
    double sigmaS = 0;
    double sigmaT = 0;
    double modV = 0;
};

void init_parameters(struct_parameters& parameters_1);

#endif
