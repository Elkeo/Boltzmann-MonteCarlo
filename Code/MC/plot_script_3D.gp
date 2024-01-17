# Utilisez le terminal PNG et définissez la sortie
set terminal png
set output "solution_3d.png"

# Définissez le titre du graphique
set title "Visualisation 3D de la Solution à t=1.000000"

# Définissez les étiquettes des axes
set xlabel "Axe X"
set ylabel "Axe Y"
set zlabel "Axe Z"

# Tracez la solution en 3D à partir du fichier de données
splot "solution_t_1.000000.txt" using 1:2:4 with lines title "Solution t=1.000000"

# Quittez Gnuplot
quit
