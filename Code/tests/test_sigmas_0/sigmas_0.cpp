#include <gtest/gtest.h>
#include "domain.hpp"
#include "parametres.hpp"
#include "population.hpp"
#include <cmath>

class BoltzmannSolver {
public:
    BoltzmannSolver(GenericDomain* domain);

    double solve(const Vecteur& x, const Vecteur& v, double t, int nMC);

private:
    GenericDomain* _domain;
};


BoltzmannSolver::BoltzmannSolver(GenericDomain* domain) : _domain(domain) {}

double BoltzmannSolver::solve(const Vecteur& x, const Vecteur& v, double t, int nMC) {
    double u = 0.0;
    
    // Use dynamic_cast to check the type of the derived class
    PeriodicDomain* periodicDomain = dynamic_cast<PeriodicDomain*>(_domain);
    ElasticDomain* elasticDomain = dynamic_cast<ElasticDomain*>(_domain);

    if (periodicDomain != nullptr) {
        Vecteur xCopy = x;
        double tCopy = t;
        Vecteur vCopy = v;
        periodicDomain->applyBoundaryConditions(xCopy, tCopy, vCopy);
    } else if (elasticDomain != nullptr) {
        Vecteur xCopy = x;
        double tCopy = t;
        Vecteur vCopy = v;
        periodicDomain->applyBoundaryConditions(xCopy, tCopy, vCopy);
    }

    // Common logic for both types
    Population packOfParticles(_domain, nMC, x, t, v, u);
    packOfParticles.move();
    return packOfParticles.get_u();
}



TEST(BoltzmannSolverTest, UValueTest) {
    int
      d = 2,      // Nombre de dimensions
      nMC = 10;   // Nombre de particules dans les paquets (permet la bonne charge quand parallélisation)
    double t = 1.0;               // Temps pour lequel on veut calculer la solution
    Vecteur x = Vecteur(d, 0.0);  // Position pour laquelle on veut calculer la solution (ici au centre)
    Vecteur v = Vecteur(d, 1.0);  // Vitesse initiale pour laquelle on veut calculer la solution

    std::valarray<Vecteur> Omega(d);
    for (int i = 0; i < d; i++)
    {
      Vecteur dimDomain = { -1, 1 };
      Omega[i] = dimDomain;
    }

    // Create instances of PeriodicDomain and ElasticDomain
    GenericDomain* periodicDomain = new PeriodicDomain(d, Omega);
    GenericDomain* elasticDomain = new ElasticDomain(d, Omega);

    // Create BoltzmannSolver instances
    BoltzmannSolver periodicSolver(periodicDomain);
    BoltzmannSolver elasticSolver(elasticDomain);

    // Test for PeriodicDomain
    double resultPeriodic = periodicSolver.solve(x, v, t, nMC);
    ASSERT_DOUBLE_EQ(resultPeriodic, 0.0);

    // Test for ElasticDomain
    double resultElastic = elasticSolver.solve(x, v, t, nMC);
    ASSERT_DOUBLE_EQ(resultElastic, 0.0);

    // Clean up memory
    delete periodicDomain;
    delete elasticDomain;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}