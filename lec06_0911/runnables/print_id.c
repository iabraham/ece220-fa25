#include <stdio.h>

void print_id(unsigned int size) {
  int i, j;
  for (i = 0; i < size; i++) {   // Looping over rows
    for (j = 0; j < size; j++) { // Looping over columns
      if (i == j)
        printf("1\t");
      else if (i < j)
        printf("0\t");
      else
        printf("\t");
    }
    printf("\n");
  }
}

int main() {
  int size;
  printf("What size:\t");
  scanf("%d", &size);
  if (size >= 1 && size <= 8)
    print_id(size);
  else
    printf("Invalid dimensions!");
}
