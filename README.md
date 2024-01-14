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

Le fichier param.toml rassemble les différents paramètres d'entrée (nombre de dimension(s), nombre de particules, position, vitesse et temps auxquels on cherche la solution u).

# Exécution du code

Le code se compile en se plaçant dans le répertoire Boltzmann-Montecarlo/Code/MC et en utilisant la commande "make". 

L'écution se fait ensuite par l'appel "./main" et donne la solution de u(x,t,v) en fonction des paramètres choisis.

NB : les fonctions SigmaS et SigmaT n'étant pas encore implémentées, la solution est constante.


# Cas tests

Différents cas test ont été réalisés et sont placés dans des sous-répertoires de MC. Dans chaque dossier se trouve un fichier readme pour expliquer comment utiliser le cas test en question.