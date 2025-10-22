#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *infile = fopen("matrix.csv", "r");
  int nr, nc, i, j;

  fscanf(infile, "%d, %d", &nr, &nc);

  int **mat = (int **)malloc(sizeof(int *) * nr);

  for (i = 0; i < nr; i++) {
    mat[i] = (int *)malloc(sizeof(int) * nc);
  }

  for (i = 0; i < nr; i++) {
    for (j = 0; j < nc; j++) {
      fscanf(infile, "%d,", &mat[i][j]);
    }
  }
  fclose(infile);

  for (j = 0; j < nc; j++) {
    for (i = 0; i < nr; i++) {
      printf("%d, ", mat[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < nr; i++) {
    free(mat[i]);
  }

  free(mat);

  return 0;
}
