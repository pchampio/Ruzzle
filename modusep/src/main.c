#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/str_perso.h"
#include "../include/gener_grille.h"
#include "../include/recherche_dictio.h"
#include "../include/recherche_grille.h"


int main(){

	char grille[N][N];

	gener_gril(grille);
	affic_mat(grille);

	char character[MAX_LENGHT];
	FILE * fic;
	fic = fopen("data/words.txt","r");

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
