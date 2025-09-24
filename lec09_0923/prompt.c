#include <stdio.h>

int my_first_sum(int *myarr, int MYSIZE) {
  int sum = 0;
  for (int i = 0; i < MYSIZE; i++)
    sum += myarr[i];

  return sum;
}

int main(void) {
  int SIZE = 5;
  int arr[SIZE];
  for (int i = 0; i < SIZE; i++) {
    printf("Enter item #(%d)", i + 1);
    scanf("%d", &arr[i]);
  }

  //  printf("\n In reverse that is: \n");
  //  for (int i = SIZE - 1; i >= 0; i--) {
  //    printf("%d\t", arr[i]);
  //  }
  printf("Sum of the array is:\t %d", my_first_sum(arr, SIZE));
  return 0;
}
