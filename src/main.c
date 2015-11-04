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

	creeTrie();

	findWords(grille);
  printf(" \n");
	affic_mat(grille);
	return 0;
}
