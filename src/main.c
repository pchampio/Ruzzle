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
* Nous avons utilisé le langage C comme langage de programmation ainsi que git comme outil de versioning et de partage.
*
* \section install_sec1 Répartion des Taches
*
* Le code du programme a été majoritairement réalisé par Pierre (recherche_dictio.c et str_perso.c) qui a aussi écrit le makefile,
* Martin a codé gener_gril.c ainsi que le comptage des points (dans recherche_grille.c) et Modira a programmé la plus grosse partie de recherche_grille.c.
* Chacun s'est occupé de la documentation de son propre module.
*
*
* \section install_sec2 Fonction
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
* si cette chaine n'existe pas il revient en arrière (supprime le dernier caractère), pour pouvoir changer de chemin et ainsi se débloquer.\n
* On trouve aussi dans ce module la fonction qui nous permet de décompter les points. Une fois qu'un mot a été défini comme étant dans la grille,
* au moment de l'afficher dans le terminal, cette fonction parcourt le mot en question en comptant un certain nombre de points par lettre
* (pour simplifier les choses, nous avons choisi de prendre les points du scrabble) et affiche le score renvoyé à coté du mot.
*
*
* \section install_sec3 Problèmes de développement
*
* En ce qui concerne le développement, nous avons développé dans le langage C.
* Certaines fonctions ont été plus compliquées que d'autre.
* Notamment le backtracking et la recherche dans le dictionnaire.
*
* \subsection step5 Backtracking
*
* En premier lieu, le backtracking n'avait pas été bien utlisé, ainsi,
* même si une chaine de caractère ne correspondait pas,
* on continuait à regarder le mot qui suivait (avec un caractère supplémentaire) :
* Beaucoup trop de calculs inutiles étaient effectués.\n
* La version qui a suivi et que nous vous présentons aujourd'hui, résout ce problème.
* Le calcul de matrice 100x100 est désormais possible dans un temps raisonnable,
* alors qu'auparavant, le calcul d'une matrice 5x5 était impossible.
* Le nombre de calcul est ainsi passé de factoriel à linéaire.\n
*
* \subsection step6 Recherche
*
* Le nombre de recherche d'un élément dans le dictionnaire est redondant dans notre programme.\n
* C'est pour cela que l'arbre préfixé est très optimisé bien que
* son temps de génération prenne une grosse partie du temps d'execution pour une petite grille,
* il simplifie énormément les calculs pour une grande grille.\n
* Par exemple pour une matrice 4x4, le nombre de recherche dans le dictionnaire est environ de 2000.
*
*
* \subsection step7 Débogage
* Pour le débogage, supposons qu'une erreur est présente dans la fonction findWordsUtil présent dans le module recherche_grille.
* Suite à cette erreur le backtracking ne s'effectue pas, et nous avons donc
* la création d'un mot "infini" (Le retour en arrière sur le chemin ne s'effectue pas). Voici les images de notre gdb nous affichant cette erreur.
* \image html "../../imgs/gdb1.png"
* Nous avons inséré un breakpoint au niveau de la fonction findWordsUtil pour pouvoir rentrer dans la fonction.
* Nous lançons le programme avec un run. Puis un display str qui nous affiche la valeur de str. Au début, il n'y a pas de problème. Puis,
* on s'aperçoit qu'il faut enlever un caractère à la sortie de la fonction.
*
* \image html "../../imgs/gdb2.png"
* Pour régler ce problème, nous avons insérer "sub_char_to_str(str);" en fin de fonction.
*
*
* \subsection step8 Tests unitaires
* Les tests unitaires ont pour but de vérifier si les axiomes des différents modules sont fonctionnelles.\n
* Pour les concevoir, nous avons utilisé le framework CU http://cu.danfis.cz/tutorial. Il s'agit d'une bibliothèque destinée à faciliter l'écriture et l'éxécution des tests unitaires en C.\n
* Ainsi, nous avons développé un test pour la fonction recherche_dictio.c.\n
* Ce test à, de ce fait, pu montrer que la fonction marche correctement car lors de l'exécution des test unitaires tous les mots du fichier data/words.txt sont retrouvés dans l'arbre.\n
* \image html "../../imgs/test.png"
* Le programme de test viendra aussi lire le fichier <a href="../../data/test.txt">./data/test.txt</a> où, l'on peut rentrer des mots à tester dans l'arbre,
 par exemple le mot "dfjkl" n'est pas trouvé dans le dico, on peut donc voir que l'une des assertations à échouée.\n
* \image html "../../imgs/test_f.png"
* le programme imprime les mots non présents dans l'arbre dans le fichier <a href="../../tests/regressions/tmp.T1.err">./tests/regressions/tmp.T1.err</a>, pour un débogage plus rapide.
*
* \subsection step9 Explication du programme
* 1) Nous générons une grille de taille NxN vide. \n
* 2) A l'aide du module gener_grille, nous remplissons la grille avec des lettres de l'alphabet, proportionnellement à leur fréquence d'apparitions dans la vie courante. Nous ne pouvons donc avoir une grille
* remplie de consonnes, ce qui aura pour conséquence une grille avec très peu de mots, donc généralement non intéressante. \n
* 3) Nous affichons tout simplement la grille. \n
* 4) Ensuite, à l'aide du module recherche_dictio, nous allons créer un dictionnaire où la recherche des mots est optimisée. \n
* 5) Par la suite, nous trouvons toutes les combinaisons possibles de lettres possible qui forment un mot. Chaque mot trouvé est affiché, avec les points correspondant à ce mot. \n
* 6) Pour finir, nous affichons une nouvelle fois la grille, pour que l'utilisateur se repère plus facilement. \n
*
* \section install_sec4 Conclusion
*
*Au terme de ces semaines de travail sur ce projet, nous sommes satisfaits que notre projet ait abouti.\n
*Le programme est fonctionnel cependant toutes les contraintes du jeu n'ont pas été réalisées, comme le tri des points des mots ou les lettres comptants double/triple.
*Ces fonctions n'ont pas été réalisées par manque de temps.
*De plus le but de ce module et donc de ce projet est la manipulation et l'utilisation des outils autour de la programmation.
* A contrario, lors du développement de notre solution à ce problème nous nous sommes rendus compte que notre programme pouvait fonctionner avec des matrices bien plus grande que 4x4,
* ce qui veut dire que notre programme est adaptatif. \n
* Il faut ajouter à la réussite de notre projet que son élaboration nous a permis d'apprendre et de mettre en place différentes composantes de la réalisation d'un projet d'algorithmique ce
* qui est essentiel à un bon programmeur.\n\n
*
* Ce projet est le premier que nous effectuons dans le langage C. C'est aussi grâce à lui que nous nous sommes familiarisés avec les "Makefile"
* et sur la façon de structurer les fichiers afin de rendre un contenu propre.\n
* Il faut également souligner que les connaissances en matière de programmation des différents membres étaient inégales et que ce projet à permis a chacun des membres de bénéficier des connaissances des autres.\n\n
* En ce qui concerne le caractère collaboratif, nous avons fortement utilisé GITHUB, avec un total de plus de 120 commit.
* Cet outil de versioning à été essentiel pour que nous soyons le plus efficace possible dans notre travail de groupe.
* Notre programme est donc ouvert à tous et il se trouve que notre page github sur le ruzzle compte plus de 700 vues.\n\n
*
* Pour finir, nous avons utilisé Doxygen pour la mise en place de la documentation, l'apprentissage de sa syntaxe est nécessaire pour présenter des projets.\n
* Champion Pierre / Mok Modira / Laville Martin
*/
/**1
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
