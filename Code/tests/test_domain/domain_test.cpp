#include "../googletest/googletest/include/gtest/gtest.h"
#include "domain.hpp"
#include "parametres.hpp"

// Test fixture pour la classe Domain
class DomainTest : public ::testing::Test {
protected:
    // Initialisation commune à tous les tests
    void SetUp() override {
    }

    void TearDown() override {

    }


    Domain domain;
};

// Test de la fonction u0
TEST_F(DomainTest, TestU0) {
    Vecteur xp(3, 0.0);
    Vecteur vp(3, 1.0);

    double result = domain.u0(xp, vp);

    EXPECT_DOUBLE_EQ(result, 0.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
