#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/str_perso.h"

//  add_char_to_str(word, "t");
void add_char_to_str(char string[M], char character){
      string[strlen(string)+1] = '\0';
      string[strlen(string)] = character;
}
void sub_char_to_str(char string[M]){
      string[strlen(string)-1] = '\0';
}
