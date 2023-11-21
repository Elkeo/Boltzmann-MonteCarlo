import random
import math

def monte_carlo_importance_sampling(f, p, q, a, b, N):
    sum_values = 0
    for _ in range(N):
        x = random.normalvariate(0, 1)  # Utilisation d'une distribution normale standard
        if a <= x <= b:
            weight = f(x) / p(x)
            sum_values += f(x) * weight

    integral_approximation = sum_values / N
    return integral_approximation


#Nb de tirages
N=1000000
#intervalle
a=0
b=1

# Exemple d'utilisation avec la fonction f(x) = x^2 sur l'intervalle [0, 1]
# Utilisons une distribution normale centrée en 0 et d'écart type 1 comme q(x)
result = monte_carlo_importance_sampling(lambda x: x**2, lambda x: math.exp(-0.5 * x**2) / math.sqrt(2 * math.pi), lambda x: math.exp(-0.5 * x**2) / math.sqrt(2 * math.pi), 0, 1, N)
print("Approximation de l'intégrale avec importance sampling :", result)


# calculer l'intégrale exacte
exact_result = b**3/3-a**3/3
print("Valeur exacte de l'intégrale (calculée avec la fonction quad) :", exact_result)
