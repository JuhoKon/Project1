/* my-grep -ohjelma */
/* Tekijät: Juho Kontiainen 0503209 */
/*          Jesse Peltola   0523140 */
/* Lähteet: stackoverflow, fgets-toiminta https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXBUFFER 1024
int grep(char*,char *);

int main(int argc, char *argv[]) {
  char c[MAXBUFFER];
  int i;
  if (argc <= 1) { /*grep vaatii jotain argumentteja */
    printf("my-grep: searchterm [file...]\n");
    exit(1);
  }
  if (argc == 2) { /*jos 2 argumenttia,halutaan lukea terminaalia */
    while(fgets(c,MAXBUFFER-1,stdin)!=NULL) { /*lukee rivit, jotka ovat alle MAXBUFFERin kokoisia */ 
      if (strstr(c,argv[1])) {	/*strstr-funktiolla verrataan merkkijonoja keskenään ja printataan kyseinen merkkijono uudestaan jos vastaava löytyy */
	printf("%s",c);								
      }
    }
    return 0;
  }
  
  for (i=2;i<argc;++i) { /*käydään parametrit läpi */
    grep(argv[1],argv[i]); /*annetaan grep-funktiolle tiedostonimi sekä etsittävä avainsana */
  }
  return 0;
}
int grep(char *key,char *argv) {
  char c[MAXBUFFER];
  FILE *fp = fopen(argv, "r"); /*muutoin luetaan tiedostosta */
  if (fp == NULL) { 
   printf("my-grep: cannot open file\n");
   exit(1);
  }

  while(fgets(c,MAXBUFFER,fp)!=NULL) { /*lukee rivit, jotka ovat alle MAXBUFFERin kokoisia */ 
    if (strstr(c,key)) {
    printf("%s",c);
    }
  }
  fclose(fp);
  return 0;
}
