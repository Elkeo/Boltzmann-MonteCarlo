import os
import subprocess

# Liste des répertoires contenant les codes C++ et Makefiles
repertoires = [
    # "./Test_echantillonage",
    # "./tests",
    "./test_integr",
    "./repro"

]

# Boucle sur chaque répertoire
for chemin in repertoires:
    print(f"Compilation et éxecution de : {chemin}")

    # Changement du répertoire courant au répertoire du projet
    os.chdir(chemin)

    # Compilation du projet avec Makefile
    compile_process = subprocess.run(["make"], capture_output=True, text=True)

    if compile_process.returncode == 0:
        print("Compilation réussie.")

        os.system("./run")  
    else:
        print(f"Erreur lors de la compilation du projet dans {chemin}:\n{compile_process.stderr}")


     # Nettoyage du projet avec 'make clean'
    clean_process = subprocess.run(["make", "clean"], capture_output=True, text=True)
    if clean_process.returncode == 0:
        print("Nettoyage réussi.")
    else:
        print(f"Erreur lors du nettoyage du projet dans {chemin}:\n{clean_process.stderr}")

    # Retour au répertoire précédent pour la prochaine itération
    os.chdir("..")

print("\nTous les tests on été effectués.\nPour plus de détails veuiillez vous référer aux messages de sortie.")
