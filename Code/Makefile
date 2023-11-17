# Compilateur utilisé
CC=g++

# Options en mode optimisé - La variable DEBUG est définie comme fausse
DEBUG_FLAG = -W -Wall -ansi -pedantic -g 
OPTIM_FLAG = -O3 -g 

# On choisit comment on compile
CXX_FLAGS = $(DEBUG_FLAG)

# Le nom de l'exécutable
PROG = run

# Les fichiers source à compiler
SRC = main.cpp MonteCarlo.cpp

# La commande complète : compile seulement si un fichier a été modifié
$(PROG) : $(SRC)
	$(CC) $(SRC) $(CXX_FLAGS) -o $(PROG) -lm

# Évite de devoir connaitre le nom de l'exécutable
all : $(PROG)

# Supprime l'exécutable, les fichiers binaires (.o) et les fichiers
# temporaires de sauvegarde (~)
clean :
	rm -rf *.o *~ $(PROG)
