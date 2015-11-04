#include <stdlib.h>

int compte_points(char * mot[]){
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
