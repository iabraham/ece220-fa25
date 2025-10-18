#include <stdio.h>

int main(void) {

  FILE *infile = fopen("mat.csv", "r");
  FILE *outfile = fopen("tr_mat.csv", "w");
  int nr, nc, i, j;

  fscanf(infile, "%d, %d", &nr, &nc);

  /* Will fail if compiled as:
       gcc -ansi -pedantic-errors mat_transpose.c -o transpose

     Below is a VLA (introduce in C99, not part of ANSI C).
  */
  int arr[nr * nc];

  for (i = 0; i < nr; i++)
    for (j = 0; j < nc; j++)
      fscanf(infile, "%d, ", &arr[i * nc + j]);
  fclose(infile);

  fprintf(outfile, "%d, %d\n", nc, nr);

  for (j = 0; j < nc; j++) {
    for (i = 0; i < nr; i++)
      fprintf(outfile, "%d, ", arr[i * nc + j]);
    fprintf(outfile, "\n");
  }

  fclose(outfile);
}
