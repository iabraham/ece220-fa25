#include <stdio.h>

int main(void) {
  char *p = "A cat has nine lives";
  char *ptr = p; 
  printf("%s\n", p);
  for (; *ptr != '\0'; ptr++) {
    if (*ptr >= 97 && *ptr <= 122 && *ptr % 2 == 0)
      *ptr -= 32;
  }
  printf("%s\n", p);
}
