#define N 4
#define M (N*N)
#define ALPHABET_SIZE 26
#define  MAX_LENGHT 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "gener_grille.h"
#include "recherche_dictio.h"
#include "recherche_grille.h"
#include "str_perso.h"

int main(){

	char grille[N][N];

	gener_gril(grille);
	affic_mat(grille);

	char character[MAX_LENGHT];
	FILE * fic;
	fic = fopen("./words.txt","r");

	if(fic != NULL){

			fscanf(fic,"%s",character);
			printf("creation d'un arbre prefixer de : %s ",character);
			while(!feof(fic)){
					insert_node(character);
					// printf("%s\n",character);
					fscanf(fic,"%s",character);

			}
			printf("--> %s\n",character);
	}
	fclose(fic);


	findWords(grille);
    printf(" \n");
	return 0;
}
