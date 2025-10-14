#include <stdio.h>

int main(void) {
  char name[20];
  char desc[100];
  int i, N = 3;

  FILE *outfile = fopen("directory.txt", "w");

  for (i = 0; i < N; i++) {
    printf("Enter name:\t");
    scanf("%s", name);
    printf("Enter a description:\t");
    scanf("%s", desc);

    fputs(name, outfile);
    fputs(", ", outfile);
    fputs(desc, outfile);
    fputs("\n", outfile);
  }

  fclose(outfile);
  return 0;
}
