
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/recherche_dictio.h"

struct t_element {
    int data;
    struct t_element* lien_avec[ALPHABET_SIZE];
};

struct t_element* racine = NULL;

struct t_element*  create_node() {
    struct t_element *node = (struct t_element*)malloc(sizeof(struct t_element));
    int x ;
    for( x = 0;x<ALPHABET_SIZE;x++)
        node->lien_avec[x] = NULL;
    node->data = -1;
    return node;
}
/*                                racine
 *                               /   \     \
 *                               m   p      g        --> niveau 0
 *                               |   |      |
 *                               a   i      a        --> niveau 1
 *                               |   |  \   |
 *                               r   e   x  g        --> niveau 2
 *                              /    |   |
 *                             t    r    e           --> niveau 3
 *                             |    |    |
 *                             i    r    l           --> niveau 4
 *                             |    |
 *                             n    e                --> niveau 5
 */

// caractères sont implicitement définis par index


// c'est comme une file où on ajoute un nœud à la fin de la liste
// on traverse, (node = node->lien_avec[index] au lieu de node = node->lien_avec) jusqu'a  node->lien_avec[index] == NULL (au lieu de node->lien_avec == NULL)
// quand on atteint NULL, au lieu d'ajoute 1 t_element et faire pointer celuis avent au nouveau, on cree plusieurs t_element (nouvelle lettres de alphaBet)
// où là valeur est égal au niveau (en bas) donc la longeur d'un mot.
void insert_node(char character[MAX_LENGHT]) {
    int length = strlen(character);
    int index;
    int level;
    if(racine == NULL)
        racine = create_node();
    struct t_element* node = racine;  // Pour l'insertion de chaque chaîne, nous allons commencer à partir de la racine

    for(level = 0 ; level < length; level++) {
        // pour chaques level trouver l'index correspondant
        // characters (a-z = 0-26)
        index = character[level] - 'a';

        if(node->lien_avec[index] == NULL) {
            // mettre la valeur de ce charactersdans node->lien_avec[index]
            // et on cree un autre t_element qui va pointer vers (node->lien_avec[index] du dessus)
            node->lien_avec[index] = create_node();  // qui est : struct t_element* suivant = create_node(); node->lien_avec[index] = suivant;
        }
        // on rentre dans la lettre crée pour en crée une nouvelle
        node = node->lien_avec[index];
    }
    // a la fin de l'arbre node->data est égal à la longeur du mot
    node->data = level;
}

int search(char character[MAX_LENGHT]) {
    struct t_element* node = racine;
    int length = strlen(character);
    int level;
		int index;
    for(level = 0 ; level < length; level++) {
        index = character[level] - 'a';
        if(node->lien_avec[index] != NULL){
					node = node->lien_avec[index];
				}else{
					break;
				}

    }

		if(character[level] == '\0' && node->data != -1){
			return node->data;
		}
    return -1;
}
void creeTrie(){
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
}
