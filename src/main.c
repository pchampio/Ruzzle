#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/str_perso.h"
#include "../include/gener_grille.h"
#include "../include/recherche_dictio.h"
#include "../include/recherche_grille.h"
/*! \mainpage My Personal Index Page
*
* \section intro_sec Introduction
*
* Le but de ce projet est de programmer un solver d'une grille Ruzzle.
* C'est-à-dire un programme capable de résoudre une grille d'une certaine taille en en trouvant tous les mots existants.
* Nous avons utilisé le langage C ainsi que git comme outil de versioning et de partage.
*
* \section install_sec Fonction
*
*  Notre programme est constitué de quatre modules :  gener_grille.c recherche_dictio.c recherche_grille.c str_perso.c.
*
* \subsection step1 str_perso
*
* Ce module permet l'ajout et la suppression de caractère à la fin d'une chaine pour faciliter l'utilisation des chaines de caractère dans les modules suivants.
*
* \subsection step2 gener_gril
*
*  Le programme de génération de la grille prend en compte une fonction disletter qui, à l'aide de statistiques trouvées sur internet,
*  génère les lettres en fonction de la fréquence d'apparition des lettres en règle générale.
*
* \subsection step3 recherche_dictio
*
* Ce module va créer un arbre préfixé qui permet de stocker (non efficacement) les différents mots du dictionnaire.
* Cependant, le nombre de calcul pour rechercher un mot est au maximum égal à la taille du mot
* alors que sans cette fonction le dictionnaire serait parcouru à chaque fois (~300'000 calculs).
*
* \subsection step4 recherche_grille
*
* Ce module fonctionne avec un systeme de backtracking (retour sur trace).
* Il consiste à trouver un ensemble de caractère de la grille (utilise le module str_perso pour agrandir et diminuer les chaines),
* si cette chaine n'existe pas il revient en arrière (supprime le dernier caractère), pour pouvoir changer de chemin et ainsi se débloquer.
*
* \section install_sec2 Développement
*
* En ce qui concerne le développement, nous avons développé dans le langage C. \n
* Certaines fonctions ont été plus compliquées que d'autre.
* Notamment le backtracking et la recherche dans le dictionnaire.\n
* En premier lieu, le backtracking n'avait pas été bien utlisé, ainsi,
* même si une chaine de caractère ne correspondait pas,
* on continuait à regarder avec un caractère supplémentaire :
* Beaucoup trop de calculs inutiles étaient effectués.\n
* La version qui a suivi et que nous vous présentons aujourd'hui, résout ce problème.
* Le calcul de matrice 100x100 est désormais possible dans un temps raisonnable,
* alors qu'auparavant, le calcul d'une matrice 5x5 était impossible.
* Le nombre de calcul est ainsi passé de factoriel à linéaire.\n
* Le nombre de recherche d'un élément dans le dictionnaire est redondant dans notre programme.\n
* C'est pour cela que l'arbre préfixé est très optimisé bien que
* son temps de génération prenne une grosse partie du temps d'execution pour une petite grille,
* il simplifie énormément les calculs pour une grande grille.\n
* Par exemple pour une matrice 4x4, le nombre de recherche dans le dictionnaire est environ de 2000.
*
*/

/**
 * \file main.c
 * \author Champion Pierre / Mok Modira / Laville Martin
 * \version   1.0
 * \date       05 Novembre 2015
 * \fn int main (void)
 * \brief fait appel aux différentes fonctions
 * \return Renvoie un entier, nul si aucune erreur n'est arrivée, autre chose sinon




*/


int main(){

	char grille[N][N];

	gener_gril(grille);
	affic_mat(grille);

	creeTrie();

	findWords(grille);
	printf(" \n");
	affic_mat(grille);
	return 0;
}
