#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/str_perso.h"

//  add_char_to_str(word, "t");

/**
* \file str_perso.c
* \fn add_char_to_str(char string[M], char character);
* \brief ajoute un caractère à une chaine de caractère
* \param string chaine de caractère où le caractère sera ajouté
* \param character caractère qui sera ajouté à la chaine de caractère

* \fn sub_char_to_str(char string[M]);
* \brief retire le dernier caractère à une chaine de caractère
* \param string chaine de caractère qui sera reduit
*/
void add_char_to_str(char string[M], char character){
      string[strlen(string)+1] = '\0';
      string[strlen(string)] = character;
}
void sub_char_to_str(char string[M]){
      string[strlen(string)-1] = '\0';
}
