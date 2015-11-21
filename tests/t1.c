#include "cu/cu.h"
#include "../include/recherche_dictio.h"
#include <stdio.h>

TEST(test1) {
  creeTrie();

  char character[MAX_LENGHT];
  FILE * fic;
  fic = fopen("data/words.txt","r");
  if(fic == NULL){fic = fopen("../data/words.txt","r");}
  if(fic != NULL){

      fscanf(fic,"%s",character);
      while(!feof(fic)){
          // insert_node(character);
          // printf("%s\n",character);

          if(search(character) == -2 || search(character) == -1){
            assertFalse(1);
            fprintf(stderr, "%s\n",character);
          }else{
            assertTrue(1);
          }
          fscanf(fic,"%s",character);

      }
  }
  fclose(fic);
}

TEST(test2) {
  char character[100] = "testjesuisunephrase";

  if(search(character) == -2 || search(character) == -1){
    assertFalse(1);
    fprintf(stderr, "%s\n",character);
  }else{
    assertTrue(1);
  }

}

TEST(test3) {
  char character[MAX_LENGHT];
  FILE * fic2;
  fic2 = fopen("data/test.txt","r");
  if(fic2 == NULL){fic2 = fopen("../data/test.txt","r");}
  if(fic2 != NULL){
      fscanf(fic2,"%s",character);
      while(!feof(fic2)){
          // insert_node(character);
          // printf("%s\n",character);

          if(search(character) == -2 || search(character) == -1){
            assertFalse(1);
            fprintf(stderr, "%s\n",character);
          }else{
            assertTrue(1);
          }
          fscanf(fic2,"%s",character);

      }
  }
  fclose(fic2);
}
