import random
import math
#from numpy import np
from scipy.integrate import quad

#MC avec des xi suivant une loi uniforme

def monte_carlo_integration_uniform(f, a, b, N):
    sum_values = 0
    for _ in range(N):
        x = random.uniform(a, b)
        sum_values += f(x)

    integral_approximation = (b - a) * sum_values / N
    return integral_approximation

#MC avec des xi suivant une loi gaussienne
def monte_carlo_integration_gauss(f, a, b, N):
    sum_values = 0
    for _ in range(N):
        x1 = random.uniform(a, b)
        x2 = random.uniform(a, b)
        u = math.sqrt(-2*math.log(x1))*math.cos(2*math.pi*x2)
        sum_values += f(u)

    integral_approximation = (b - a) * sum_values / N
    return integral_approximation

# Fonction à intégrer
def f(x):
    return x**2

#####################################################################

# Intervalle d'intégration
a, b = 0, 1

#Nb de tirages
N=1000000

# Utilisation de quad pour calculer l'intégrale exacte
exact_result, _ = quad(f, a, b)
print("Valeur exacte de l'intégrale (calculée avec la fonction quad) :", exact_result)

#approx avec tirage uniforme
result1 = monte_carlo_integration_uniform(f, a, b, N)
print("Approximation de l'intégrale (calculée par méthode de MC) :", result1)
print("L'erreur absolue vaut : ",abs(exact_result-result1))

#approx avec tirage gaussien
result2 = monte_carlo_integration_gauss(f, a, b, N)
print("Approximation de l'intégrale (calculée par méthode de MC) :", result2)
print("L'erreur absolue vaut : ",abs(exact_result-result2))