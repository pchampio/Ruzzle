#define N 4
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{char lettre; int points; char bon[2];}t_case;


/* Affiche une matrice */
void affic_mat(t_case mat[N][N]){
	int i, j;
	for(i = 0; i < N ; i++){
        	for(j = 0; j < N; j++){
            		printf("%c ", mat[i][j].lettre);
		}
        printf("\n");
    }
    printf("\n");
}

void gener_gril(t_case mat[N][N]){
	int i, j, alea;
	srand(time(NULL));
	for(i = 0; i < N ; i++){
        	for(j = 0; j < N; j++){
			alea = rand();
			mat[i][j].lettre = (alea % 26 + 65);
		}
	}
}

int main(){
	t_case grille[N][N];
	gener_gril(grille);
	affic_mat(grille);
	return 0;
}
	
