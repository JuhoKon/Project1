/* my-grep -ohjelma */
/* Tekijät: Juho Kontiainen 0503209 */
/*          Jesse Peltola   0523140 */
/* Lähteet: stackoverflow           */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char c[150];

  if (argc <= 1) { /*grep vaatii jotain argumentteja */
    printf("my-grep: searchterm [file...]\n");
    exit(1);
  }
  if (argc == 2) { /*jos 2 argumenttia,halutaan lukea terminaalia */
    while(fgets(c,149,stdin)!=NULL) {
      if (strstr(c,argv[1])) {	/*strstr-funktiolla verrataan merkkijonoja keskenään ja printataan kyseinen merkkijono uudestaan jos vastaava löytyy */
	printf("%s",c);								
      }
    }
    return 0;
  }
  
  FILE *fp = fopen(argv[2], "r"); /*muutoin luetaan tiedostosta */
  if (fp == NULL) { 
   printf("my-grep: cannot open file\n");
   exit(1);
  }
  while(fgets(c,149,fp)!=NULL) {
    if (strstr(c,argv[1])) {
    printf("%s",c);
    }
  }
  fclose(fp);
  return 0;
}
