Ruzzle  [![Build Status](https://travis-ci.org/Drakirus/Ruzzle.svg)](https://travis-ci.org/Drakirus/Ruzzle)
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
 L'exécutable généré peut être retrouvé dans **./bin**



	Le paramètre size= permet de choisir la taille de la grille
	Par exemple pour une grille de 20*20 : (par defaut size=4)
	(Si la valeur 1 est indiquée la grille sera de taille 4*4)
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
La documentation **accompagnée de notre rapport**  générée peut être retrouvée dans **./doc/html/index.html**
### Nettoyage
```
$ make clean
```
 Supprime les fichiers dus a la création de l'exécutable, et l'exécutable.
La documentation est elle aussi supprimée.

## Test Unitaire
### Exécution
```
$ make test
```
Les tests unitaires sont générés, l'exécutable des test est **./tests/test**
>Les mots **non trouvés** sont placés dans **./tests/regressions/tmp.T1.err**
>Les mots qui seront recherchés sont ceux du dictionnaire et ceux du ficher **./data/test.txt**

Pour exécuter les tests:

```
$ cd tests && ./test

(si -bash: ./test: Permission denied)
$ sudo ./test
```

Pour afficher les mots non trouvés dans l'arbre
```
$ cat regressions/tmp.T1.err
```
### Nettoyage des tests
```
$ make test_clean (dans le répertoire ./Ruzzle)
```
 Supprime les fichier dus à la création de l'exécutable de test, et l'exécutable test.


### Lien Github


 https://github.com/Drakirus/Ruzzle
 
