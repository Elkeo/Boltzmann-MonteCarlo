# Base de non régression


## Execution

Pour éxecuter la base de test il surffier de taper la commande :
```bash
python3 BNR.py
```

## Structure du code


Le script __BNR.py__ fais une boucle sur tout les tests disponibles. Lors de la boucle le système compile en utilisant le __Makefile__ disponible dans chaque répertoire. Ensuite le programme est executé puis les messages relatif sont affiché dans la console. L'utilisateur est invité à les lire et décider de si le test est validé ou non. Enfin un "make clean" est effectué dans le répetoire puis le système passe au test suivant.