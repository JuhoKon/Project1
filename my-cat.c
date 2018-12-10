/* my-cat -ohjelma */
/* Tekijät: Juho Kontiainen 0503209 */
/*          Jesse Peltola           */
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

  c = fgetc(fp);
  while (c != EOF) {
    printf("%c",c);
    c = fgetc(fp);
  }
  fclose(fp);
  return 0;
}
