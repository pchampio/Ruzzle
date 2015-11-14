Ruzzle
==
Le Ruzzle est un jeu originaire du monde mobile, ce jeu consiste à former le plus de mots en un temps imparti à partir
d'une grille de lettres générée aléatoirement.
Le but étant de marquer le plus de points possible pour celà des bonus lettre et mot double/triple sont répartis sur la grille
mais il n'est pas permis de réutiliser deux fois la même case.

# Release - 1
### To do :
	documentations
	test unitaires
	test GDB

### Fait :
	Les fichiers sources sont dans ```./src```
	Les fichiers entêtes (.h) sont dans ```./include```
	Creation d'un fichier ```./bin``` où l'exécutable est compiler
	Documentations Doxygen

### Instructions de compilation

```
$ make
```

Permet de compiler l'ensemble des sources, l'exécutable généré peut être retrouvé dans ./bin .

	Le parametre size= permet de choisir la taille de la grille
	Par exemple pour une grille de 3*3 : (par defaut size=4)
	```$ make size=3```


Pour exe le programme

```
bin\main.exe
```

Pour se rm les fichier execulable --> version propre


```
make clean
```
