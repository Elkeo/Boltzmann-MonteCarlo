#include "toml/toml.hpp"
#include "parameters.hpp"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <valarray>


void init_parameters(struct_parameters& parameters) {

    //Opening file
    auto param_file = toml::parse("param.toml");

    //Simuation parameters
    const auto& simulation = toml::find(param_file, "simulation");

    parameters.nbDims = toml::find<int>(simulation, "nbDims");//Number of dimensions
    parameters.nbMC = toml::find<int>(simulation, "nbMC"); //Number of MC particles 
    parameters.time = toml::find<double>(simulation, "time"); //Final time of the simulation
    parameters.domainType = toml::find<std::string>(simulation, "domainType"); //Type of domain

    // Position pour laquelle on veut calculer la solution (ici au centre)
    parameters.array_x = { toml::find<double>(simulation, "xmin"), toml::find<double>(simulation, "xmax") };
    // Vitesse initiale pour laquelle on veut calculer la solution
    parameters.array_v = std::valarray<double>(parameters.nbDims, toml::find<double>(simulation, "v1"));

    if (parameters.nbDims >= 2) {
        parameters.array_y = { toml::find<double>(simulation, "ymin"), toml::find<double>(simulation, "ymax") };
        parameters.array_v[1] = toml::find<double>(simulation, "v2");
        if (parameters.nbDims == 3) {
            parameters.array_z = { toml::find<double>(simulation, "zmin"), toml::find<double>(simulation, "zmax") };
            parameters.array_v[2] = toml::find<double>(simulation, "v3");
        }
    }

    //Phisical parameters
    const auto& physics = toml::find(param_file, "physics");
    parameters.sigmaS = toml::find<double>(physics, "sigmaS");
    parameters.sigmaT = toml::find<double>(physics, "sigmaT");
    parameters.modV = toml::find<double>(physics, "modV");
}
