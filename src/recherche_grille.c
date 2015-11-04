#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/recherche_grille.h"
#include "../include/str_perso.h"
#include "../include/recherche_dictio.h"


// une fonction recursive qui print les mots présent dans la matrise
void findWordsUtil(char mat[N][N], int visited[N][N], int i, int j, char str[M]){
	// marke la cellule (i, j) comme visiter
	// ajoute un char a str
	visited[i][j] = 1;
	add_char_to_str(str, mat[i][j]);
	int isfind = search(str);
	// Si str is present dans le dico, alors il est print
	if (isfind == strlen(str)){
		printf("%s / ", str);
	}


	// Traverse les 8 adjacent cellules de mat[i][j]
	int dx,dy;
		for (dx = (i <= 0 ? 0 : -1); dx <= (i >= N-1 ? 0 : 1); dx++) {
			for (dy = (j <= 0 ? 0 : -1); dy <= (j >= N-1 ? 0 : 1); dy++) {
				if (!visited[dx+i][dy+j] ){
					findWordsUtil(mat,visited, dx+i, dy+j, str);
				}
			}
		}
	// Effacer le caractère de str et raz de visited pour le prochain batch de calcul
	sub_char_to_str(str);
	visited[i][j] = 0;
}

// Prints les mots trouve
void findWords(char mat[N][N]){
	// Mark tout les characters a pas visite
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
