#include <stdio.h>

/* Driver code */
int main(void) {
  int arr[] = {17, 43, 9, 40, 11, 68, 13};
  int len = sizeof(arr) / sizeof(arr[0]);
  int i;

  for (i = 0; i < len; i++)
    printf("%d ", arr[i]);

  printf("\n");

  // QuickSortIterative(arr, 0, len - 1);

  for (i = 0; i < len; i++)
    printf("%d ", arr[i]);
}
