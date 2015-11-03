#define N 4
#define M (N*N)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{char lettre; int points; char bon[2];}t_case;


#define ALPHABET_SIZE 26
#define  MAX_LENGHT 20

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

//                			      racine
//                            /   \     \
//    NULL    NULL            m   p      g        --> niveau 0
//      NULL     NULL         |   |      |
//     NULL      NULL         a   i      a        --> niveau 1
//         NULL    NULL       |   |  \   |
//      NULL      NULL        r   e   x  g        --> niveau 2
//            NULL           /    |   |
//                          t    r   e            --> niveau 3
//         NULL             |    |   |
//             NULL NULL    i    r   l            --> niveau 4
//      NULL       NULL     |    |
//         NULL NULL        n    e                --> niveau 5

// caractères sont implicitement définis par index


// c'est comme une file où on ajoute un nœud à la fin de la liste
// on traverse, (node = node->lien_avec[index] au lieu de node = node->lien_avec) jusnodeu'a  node->lien_avec[index] == NULL (au lieu de node->lien_avec == NULL)
// nodeuand on atteint NULL, au lieu d'ajoute 1 t_element et faire pointer celuis avent au nouveau, on cree plusieurs t_element (nouvelle lettres de alphaBet)
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
        int index = character[level] - 'a';

        if(node->lien_avec[index] == NULL) {
            // mettre la valeur de ce charactersdans node->lien_avec[index]
            // et on cree un autre t_element qui va pointer vers (node->lien_avec[index] du dessus)
            node->lien_avec[index] = create_node();  // qui est : struct t_element* suivant = create_node(); node->lien_avec[index] = suivant;
        }

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
//  add_char_to_str(word, "t");
void add_char_to_str(char string[M], char character){
      string[strlen(string)+1] = '\0';
      string[strlen(string)] = character;
}
void sub_char_to_str(char string[M]){
      string[strlen(string)-1] = '\0';
}

// https://fr.wikipedia.org/wiki/Fr%C3%A9quence_d%27apparition_des_lettres_en_fran%C3%A7ais
char distLetter() {
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
    if(x < 15833) return 'z';

}

void gener_gril(char mat[N][N]){
	int i, j;
	srand(time(NULL));
	for(i = 0; i < N ; i++){
		for(j = 0; j < N; j++)
			mat[i][j] = distLetter();
	}
}

// une fonction recursive qui print les mots présent dans la matrise
void findWordsUtil(char mat[N][N], int visited[N][N], int i, int j, char str[M]){
	// marke la cellule (i, j) comme visiter
	// ajoute un char a str
	visited[i][j] = 1;
	add_char_to_str(str, mat[i][j]);
	int isfind = search(str);
	// Si str is present dans le dico, alors il est print

	if (isfind == strlen(str))
		printf("%s / ", str);

	// Traverse les 8 adjacent cellules de mat[i][j]
	int dx,dy;
		for (dx = (i <= 0 ? 0 : -1); dx <= (i >= N-1 ? 0 : 1); dx++) {
			for (dy = (j <= 0 ? 0 : -1); dy <= (j >= N-1 ? 0 : 1); dy++) {
				if (!visited[dx+i][dy+j] ){ // si la case n'a pas déjà été visiter et qu'il y a un mots avec ce commecement qui existe  && contains(str, '.', "words.txt" )
				// && (isfind == -2 || isfind == strlen(str))
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
		for (j=0; j<N; j++)
				findWordsUtil(mat, visited, i, j, str);
	}

}

int contains(char grep_obj[M], char EndFlag[1], char File[100]){
		char command[100];
		sprintf(command, "grep \"^%s%c\" %s > tmp", grep_obj, EndFlag, File);

		// if (EndFlag == '$' ) {  //debug
		// 	printf("find --> \"%s\"\n", grep_obj);
		// }
		system(command);

		char character[20];
		FILE * fic;
		fic = fopen("tmp","r");

		if(fic != NULL){
			fscanf(fic,"%s",character);
			if(!feof(fic)){
				fclose(fic);
				return 1;
			}
		}
		fclose(fic);
		return 0;
}

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

	return 0;
}
