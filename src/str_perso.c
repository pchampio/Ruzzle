#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/str_perso.h"

//  add_char_to_str(word, "t");

/**
* \file str_perso.c
* \fn add_char_to_str(char string[M], char character);
* \brief ajoute un character à une chaine de character
* \param string chaine de character où le character sera ajouter
* \param character character qui sera ajouter à la chaine de character

* \fn sub_char_to_str(char string[M]);
* \brief retire le dernier character à une chaine de character
* \param string chaine de character qui sera reduit
*/
void add_char_to_str(char string[M], char character){
      string[strlen(string)+1] = '\0';
      string[strlen(string)] = character;
}
void sub_char_to_str(char string[M]){
      string[strlen(string)-1] = '\0';
}
