#define N 4
#define M (N*N)
#define ALPHABET_SIZE 26
#define  MAX_LENGHT 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <time.h>
#include "str_perso.h"


/* Affiche une matrice */
void affic_mat(char mat[N][N]){
	int i, j;
	for(i = 0; i < N ; i++){
		for(j = 0; j < N; j++)
			printf("%c ", mat[i][j]);
  	printf("\n");
  }
  printf("\n");
}

// https://fr.wikipedia.org/wiki/Fr%C3%A9quence_d%27apparition_des_lettres_en_fran%C3%A7ais
char distLetter(){
    rand();
    int x = rand() % 15833;
    if(x < 1209) return 'a';
    if(x < 1510) return 'b';
    if(x < 2151) return 'c';
    if(x < 2699) return 'd';
    if(x < 4526) return 'e';
    if(x < 4726) return 'f';
    if(x < 5161) return 'g';
    if(x < 5528) return 'h';
    if(x < 6931) return 'i';
    if(x < 6957) return 'j';
    if(x < 7101) return 'k';
    if(x < 7947) return 'l';
    if(x < 8395) return 'm';
    if(x < 9462) return 'n';
    if(x < 10496) return 'o';
    if(x < 10962) return 'p';
    if(x < 10987) return 'q';
    if(x < 12111) return 'r';
    if(x < 13613) return 's';
    if(x < 14653) return 't';
    if(x < 15174) return 'u';
    if(x < 15328) return 'v';
    if(x < 15452) return 'w';
    if(x < 15499) return 'x';
    if(x < 15757) return 'y';
    return 'z';
}

void gener_gril(char mat[N][N]){
	int i, j;
	srand(time(NULL));
	for(i = 0; i < N ; i++){
		for(j = 0; j < N; j++)
			mat[i][j] = distLetter();
	}
}