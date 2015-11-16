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
* This is the introduction.
*
* \section install_sec Installation
*
* \subsection step1 Step 1: Opening the box
*
* etc...
*/

/**
 * \file main.c
 * \author Champion Pierre / Mok Modira  / Laville Martin
 * \version   1.0
 * \date       05 Novembre 2015
 * \fn int main (void)
 * \brief fait appelle aux diférentes function
 * \return Renvoie un entier, nul si aucune erreur n'est arrivee, autre chose sinon




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
