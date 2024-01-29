import os
import subprocess


RED = "\033[31m"
GREEN = "\033[32m"
BLUE = "\033[34m"
YELLOW = "\033[33m"
BOLD = "\033[1m"
RESET = "\033[0m"

# Liste des répertoires contenant les codes C++ et Makefiles
repertoires = [
    "./Test_echantillonnage",
    # "./tests",
    "./test_integr",
    "./repro"

]

# Boucle sur chaque répertoire
for chemin in repertoires:
    print(f"{YELLOW}Compilation et éxecution de : {chemin}")

    # Changement du répertoire courant au répertoire du test
    os.chdir(chemin)

    # Compilation du projet avec Makefile
    compile_process = subprocess.run(["make"], capture_output=True, text=True)

    if compile_process.returncode == 0:
        print(f"{GREEN}Compilation réussie.")
        print(f"{BLUE}{BOLD}####################################{RESET}\n")

        os.system("./run")  
    else:
        print(f"{RED}Erreur lors de la compilation du projet dans {chemin}:\n{compile_process.stderr}{RESET}")
    
    if chemin=="./Test_echantillonnage":
        os.system("python3 treatment.py")  


    print(f"{BLUE}{BOLD}\n####################################{RESET}")
    # Nettoyage du projet avec make clean
    clean_process = subprocess.run(["make", "clean"], capture_output=True, text=True)
    if clean_process.returncode == 0:
        print(f"{GREEN}Nettoyage réussi.{RESET}")
    else:
        print(f"{RED}Erreur lors du nettoyage du projet dans {chemin}:\n{clean_process.stderr}{RESET}")

    # Retour au répertoire précédent pour la prochaine itération
    os.chdir("..")


print(f"{BOLD}\nTous les tests on été effectués.")
print(f"{BOLD}Pour plus de détails veuiillez vous référer aux messages de sortie.")
