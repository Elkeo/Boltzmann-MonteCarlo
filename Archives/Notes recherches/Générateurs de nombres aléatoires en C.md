Plusieurs générateurs de nombres aléatoires semblent revenir :

# ```rand``` 
fonction déterministe (besoin d'une seed, a indiquer avec ```srand```) de génération de nombres aléatoires, issues de ```stdlib.h``` 

Génèrent des nombres entre 0 et une constante. 

Ces fonctions ne semblent pas générer des nombres aléatoires de manière parfaitement homogène. (La documentation sur internet semble indiquer que c'est pas un choix très judicieux)

# ```random``` 

De même, fonction déterministe qui produirait des nombres aléatoire de meilleure qualité que ```rand``` 
Importée avec ```#include "sys/random"```

# ```getrandom```

Fonction de Linux, apparemment bien meilleure que les deux précédentes, mais plus complexe à utiliser. => En fait pas forcément très nécessaire puisque lent pour des propriétés cryptographiques dont on a pas besoin du tout. 

Peut être plus partir sur ```/dev/random``` ou ```/dev/urandom```

En fait c'est plus compliqué que ça, il va falloir que je pousse d'avantage les recherches hihi.

