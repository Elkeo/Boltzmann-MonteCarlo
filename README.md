# Cailloux

## Sujet

Résolution de l'équation de Boltzmann linéaire par méthode Monte-Carlo.

## Dépôt du projet de Calcul Haute Performance

Groupe de :
- Gabriel RODIERE,
- Khaoula EL MADDAH,
- Antoine BOUCHER,
- Clément AUMONIER,
- Guillaume DOYEN.


# Choix des paramètres

Le fichier param.toml rassemble les différents paramètres d'entrée (nombre de dimension(s), nombre de particules, dimensions du domaine, nombre de points, vitesses et temps auxquels on cherche la solution u).

# Exécution du code

Le code se compile en se plaçant dans le répertoire Boltzmann-Montecarlo/Code/MC et en utilisant la commande "make". 

L'exécution se fait ensuite par l'appel "./main" et donne la solution de $u(x_i, y_j, z_k, t^n, v)$ en fonction des paramètres choisis dans un fichier "Resultats/solution_t_"n".txt".
Les 4 premières colonnes correspondent à $t^n$, $x_i$, $y_j$ et $z_k$ et la cinquième et dernière à $u(x_i, y_j, z_k, t^n, v)$.

NB : les fonctions SigmaS et SigmaT sont constantes et retournent pour valeur celle écrite dans le fichier param.toml


# Détails sur le code

Le code résout l'équation intégro-différentielle de Boltzmann par un schéma de Monte-Carlo semi-analogue (aussi appelé implicite).
Certains choix de simplification ont été faits sur la solution. En particulier :
 - La solution est calculée pour des particules monocinétiques ($|v| = cte$) tirées uniformément sur la sphère unité ;
 - Les opacités sont constantes ;
 - Le temps d'intéraction est tiré selon une loi exponentielle de paramètre $|v| \sigma$.
Le domaine de résolution peut-être avec plusieurs types de parois : élastiques ou périodiques.

# Cas tests

Différents cas test ont été réalisés et sont placés dans des sous-répertoires de MC. Dans chaque dossier se trouve un fichier README pour expliquer comment utiliser le cas test en question.
