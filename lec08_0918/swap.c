#include <stdio.h>
void Swap(int *first, int *second);

int main() {
  int valueA = 3;
  int valueB = 4;
  Swap(&valueA, &valueB);
}

void Swap(int *first, int *second) {
  int temp;
  temp = *first;
  *first = *second;
  *second = temp;
}
