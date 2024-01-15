#include "./toml/toml.hpp"
#include "parameters.hpp"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <valarray>


void init_parameters(struct_parameters &parameters){

    //Opening file
    auto param_file = toml::parse("param.toml"); 

    //Simuation parameters
    const auto& simulation = toml::find(param_file, "simulation");

    parameters.nbDims = toml::find<int>(simulation, "nbDims");//Number of dimensions
    parameters.nbMC = toml::find<int>(simulation, "nbMC"); //Number of MC particles 
    parameters.time = toml::find<double>(simulation, "time"); //Time of the wanted result 

    double x1 = toml::find<double>(simulation, "x1"), x2 = toml::find<double>(simulation, "x2"), x3 = toml::find<double>(simulation, "x3"); //Position of the wanted result 
    double v1 = toml::find<double>(simulation, "v1"), v2 = toml::find<double>(simulation, "v2"), v3 = toml::find<double>(simulation, "v3"); //Speed of the wanted result

    parameters.array_x = std::valarray<double>(parameters.nbDims, toml::find<double>(simulation, "x1"));  // Position pour laquelle on veut calculer la solution (ici au centre)
    parameters.array_v = std::valarray<double>(parameters.nbDims, toml::find<double>(simulation, "v1"));  // Vitesse initiale pour laquelle on veut calculer la solution
    if(parameters.nbDims >= 2){
        parameters.array_x[1] = toml::find<double>(simulation, "x2");
        parameters.array_v[1] = toml::find<double>(simulation, "v2");
        if(parameters.nbDims == 3){
            parameters.array_x[2] = toml::find<double>(simulation, "x3");
            parameters.array_v[2] = toml::find<double>(simulation, "v3");
        }
    }

    //Phisical parameters
    const auto& physics = toml::find(param_file, "physics");
    parameters.sigmaS = toml::find<double>(physics, "sigmaS"); 
    parameters.sigmaT = toml::find<double>(physics, "sigmaT");
    parameters.modV = toml::find<double>(physics, "modV");
}
