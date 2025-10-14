#include <stdio.h>
#include <unistd.h>

int main() {
  putchar('a');
  putchar('\n');
  sleep(5);
  putchar('b');
}
