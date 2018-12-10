/* my-cat -ohjelma */
/* Tekijät: Juho Kontiainen 0503209 */
/*          Jesse Peltola   0523140 */
/* Lähteet: stackoverflow           */

#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) {
  char c;
  FILE *fp = fopen(argv[1], "r"); 
  if (fp == NULL) { 
   printf("cannot open file\n");
   exit(1);
  }

  c = fgetc(fp); /*Luetaan tiedostoa */
  while (c != EOF) { /*end-of-fileen asti */
    printf("%c",c);
    c = fgetc(fp);
  }
  fclose(fp);
  return 0;
}
