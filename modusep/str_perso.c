#define N 4
#define M (N*N)
#define ALPHABET_SIZE 26
#define  MAX_LENGHT 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//  add_char_to_str(word, "t");
void add_char_to_str(char string[M], char character){
      string[strlen(string)+1] = '\0';
      string[strlen(string)] = character;
}
void sub_char_to_str(char string[M]){
      string[strlen(string)-1] = '\0';
}