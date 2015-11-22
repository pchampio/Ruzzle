Ruzzle
==
Le Ruzzle est un jeu originaire du monde mobile, ce jeu consiste à former le plus de mots en un temps imparti à partir
d'une grille de lettres générée aléatoirement.
Le but étant de marquer le plus de points possible pour celà des bonus lettre et mot double/triple sont répartis sur la grille
mais il n'est pas permis de réutiliser deux fois la même case.

# Release - 1

## Instructions de compilation
### Solver
Pour compiler l'ensemble des sources :
```
$ make
```
 l'exécutable généré peut être retrouvé dans **./bin**



	Le parametre size= permet de choisir la taille de la grille
	Par exemple pour une grille de 20*20 : (par defaut size=4)
	(Si la valeur 1 est indquée la grille sera de taille 4*4)
```
$ make size=20
```


Pour exécuter le programme :

```
$ time bin\main.exe
```
### Documentation
```
$ make doc
```
La documentation **accompagner de notre rapport**  généré peut être retrouvé dans **./doc/html/index.html**
### Nettoyage
```
$ make clean
```
 Supprime les ficher due a la création de l'exécutable, et l'exécutable.
La documentation est elle aussi supprimer.

## Test Unitaire
### Exécution
```
$ make test
```
Les tests unitaires sont généré, l'exécutable des test est **./tests/test**
>Les mots **non trouver** sont placée dans **./tests/regressions/tmp.T1.err**
>Les mots qui serons rechercher sont ceux du dictionnaire et ceux du ficher **./data/test.txt**

Pour exécuter les tests:

```
$ cd tests && ./test

(si -bash: ./test: Permission denied)
$ cd tests && sudo ./test
```

Pour afficher les mots non trouver dans l'arbre
```
$ cat regressions/tmp.T1.err
```
### Nettoyage des tests
```
$ make test_clean (dans le répertoire ./Ruzzle)
```
 Supprime les ficher due a la création de l'exécutable de test, et l'exécutable test.
