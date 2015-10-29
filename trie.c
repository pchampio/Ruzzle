#include <stdio.h>
#include <stdlib.h>

int main() {
   char grep_obj[20];
   char command[100];
   printf("find : ");
   scanf("%s", grep_obj);
    sprintf(command, "grep \"^%s\" dico-ref-ascii-sans-accent.txt > tmp", grep_obj);
    printf("command = \"%s\"\n", command);
    system(command);



    return 0;
}
