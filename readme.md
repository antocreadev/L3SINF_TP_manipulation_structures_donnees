Pour lancer l'exo 1: 
1.
```bash
make exo1
```
2.
```bash 
cd bin
```
3.
```bash
./menghiexo1
```
<!-- 
Pour lancer un code c seul sans modulairité: 
```bash 
make t=nom_du_fichier
``` -->

# Exercice 2 - Question 1 : 

Pour l'implémenation d'une pile, j'ai choisi d'utiliser une liste chainée.
En effet, une liste chainée est une structure de données dynamique qui permet d'ajouter et de supprimer des éléments en temps constant. De plus il est facile d'ajouter ou de supprimer un élément en tête de liste. Et avec une liste chaînée, la gestion de la mémoire est simplifiée car les nœuds de la liste sont alloués individuellement au besoin. Cela évite les problèmes liés à l'allocation statique de mémoire ou à la nécessité de redimensionner un tableau dynamique. Juste milieu sur la complexité d'implémentation légèrement plus complexe à mettre en œuvre qu'un tableau statique, une liste chaînée reste relativement simple à coder, les opérations d'ajout et de suppression sont simples à mettre en œuvre avec les pointeurs.


# Exercice 3 - Question 1 :
Pour la gestion des horaires de trains, une liste chaînée serait préférable. Elle permet un ajout efficace de nouveaux horaires, une recherche satisfaisante des horaires au départ d'une ville donnée, des opérations d'insertion et de suppression rapides, une gestion de la mémoire plus simple, et une mise en œuvre relativement facile.