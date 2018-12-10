/* my-cat -ohjelma */
/* Tekijät: Juho Kontiainen 0503209 */
/*          Jesse Peltola   0523140  */
/* Lähteet: stackoverflow           */

#include <stdio.h>
#include <stdlib.h>
int cat(char *);

int main(int argc, char *argv[]) {
  int i;
  if (argc <= 1) { /*Ei argumentteja */
    return 1;
  }
  for (i=1; i<argc; ++i) { /*käydään muut annetut parametrit läpi */
    cat(argv[i]);
  }
  return 0;
}
int cat(char *argv) {
  char c;
  FILE *fp = fopen(argv, "r"); 
  if (fp == NULL) { 
   printf("my-cat: cannot open file\n");
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
