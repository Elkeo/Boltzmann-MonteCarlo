Plusieurs générateurs de nombres aléatoires semblent revenir :

# ```rand``` 
fonction déterministe (besoin d'une seed, a indiquer avec ```srand```) de génération de nombres aléatoires, issues de ```stdlib.h``` 

Génèrent des nombres entre 0 et une constante. 

Ces fonctions ne semblent pas générer des nombres aléatoires de manière parfaitement homogène. (La documentation sur internet semble indiquer que c'est pas un choix très judicieux)

# ```random``` 

De même, fonction déterministe qui produirait des nombres aléatoire de meilleure qualité que ```rand``` 
Importée avec ```#include "sys/random"```

# ```getrandom```

Fonction de Linux, apparemment bien meilleure que les deux précédentes, mais plus complexe à utiliser.



