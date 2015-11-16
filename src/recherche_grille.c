#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/recherche_grille.h"
#include "../include/str_perso.h"
#include "../include/recherche_dictio.h"

/**
* \file recherche_grille.c

* \fn compte_points(char mot[]);
* \param mot le mot où le comptage des points est appliqué
* \brief compte les point d'un mot génèré selon les règles du scrabble
* \return le nombre de point du mot

* \fn void findWordsUtil(char mat[N][N], int visited[N][N], int i, int j, char str[M]);
* \param mat la matrice de mots
* \param visited c'est une matrice qui contient les cellules déja parcourues
* \param i l'index des collones où la recherche commence/continue
* \param j l'index des lignes où la recherche commence/continue
* \param str le mot formé
* \brief Est une fonction recursive qui affiche les mots présent dans la matrice

* \fn void findWords(char mat[N][N]);
* \param mat la matrice de mots
* \brief Point de départ de la fonction findWordsUtil
*/

int compte_points(char mot[]){
	int i = 0, pts = 0;
    for(i = 0 ; mot[i] != '\0' ; i++){
	    if(mot[i] == 'a') pts += 1;
	    else if(mot[i] == 'b') pts += 3;
	    else if(mot[i] == 'c') pts += 3;
	    else if(mot[i] == 'd') pts += 2;
	    else if(mot[i] == 'e') pts += 1;
	    else if(mot[i] == 'f') pts += 4;
	    else if(mot[i] == 'g') pts += 2;
	    else if(mot[i] == 'h') pts += 4;
	    else if(mot[i] == 'i') pts += 1;
	    else if(mot[i] == 'j') pts += 8;
	    else if(mot[i] == 'k') pts += 5;
	    else if(mot[i] == 'l') pts += 1;
	    else if(mot[i] == 'm') pts += 3;
	    else if(mot[i] == 'n') pts += 1;
	    else if(mot[i] == 'o') pts += 1;
	    else if(mot[i] == 'p') pts += 3;
	    else if(mot[i] == 'q') pts += 10;
	    else if(mot[i] == 'r') pts += 1;
	    else if(mot[i] == 's') pts += 1;
	    else if(mot[i] == 't') pts += 1;
	    else if(mot[i] == 'u') pts += 1;
	    else if(mot[i] == 'v') pts += 4;
	    else if(mot[i] == 'w') pts += 4;
	    else if(mot[i] == 'x') pts += 8;
	    else if(mot[i] == 'y') pts += 4;
	    else if(mot[i] == 'z') pts += 10;
    }
  return pts;
}

// une fonction recursive qui prend les mots présents dans la matrice
void findWordsUtil(char mat[N][N], int visited[N][N], int i, int j, char str[M]){
	// marque la cellule (i, j) comme visitée
	// ajoute un char a str
	visited[i][j] = 1;
	add_char_to_str(str, mat[i][j]);
	int isfind = search(str);
	// Si str est present dans le dico, alors il est affiché
	if (isfind == strlen(str)){
		printf("%s : %ipts / ", str, compte_points(str));
	}


	// Traverse les 8 cellules adjacentes de mat[i][j]
	int dx,dy;
		for (dx = (i <= 0 ? 0 : -1); dx <= (i >= N-1 ? 0 : 1); dx++) {
			for (dy = (j <= 0 ? 0 : -1); dy <= (j >= N-1 ? 0 : 1); dy++) {
				// if (isfind == -1 ) {	printf("%s\n", str);}
				if (!visited[dx+i][dy+j] && (isfind == -2 || isfind > -1 )){
					findWordsUtil(mat,visited, dx+i, dy+j, str);
				}
			}
		}
	// Efface le caractère de str et raz de visited pour la prochaine série de calcul
	sub_char_to_str(str);
	visited[i][j] = 0;
}

// Affiche les mots trouvés
void findWords(char mat[N][N]){
	// Marque tous les caractères a ne pas visiter
	int visited[N][N] = {{0}};

	// Initialise str
	char str[M]= {'\0'};
	int i,j;
	// point de depart
	for (i=0; i<N; i++){
		for (j=0; j<N; j++){
			findWordsUtil(mat, visited, i, j, str);
		}

	}

}
