#include <gtest/gtest.h>
#include "../../domain.hpp"
#include "../../parameters.hpp"

class DomainTest : public ::testing::Test {
protected:
    ElasticDomain* domain; // Remplacez par PeriodicDomain si nécessaire

    // Initialisation commune à tous les tests
    void SetUp() override {
        struct_parameters parameters; // Créez et initialisez les paramètres si nécessaire
        std::valarray<Vecteur> Om;     // Créez et initialisez Om si nécessaire

        // Instanciez le domaine avec les paramètres et Om
        domain = new ElasticDomain(parameters, Om);
    }

    void TearDown() override {
        delete domain;  // Nettoyez l'instance après chaque test
    }
};

// Test de la fonction u0
TEST_F(DomainTest, TestU0) {
    Vecteur xp(3, 0.0);
    Vecteur vp(3, 1.0);

    double result = domain->initialCondition(xp, vp);

    EXPECT_DOUBLE_EQ(result, 0.0);
}

// int main(int argc, char** argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
