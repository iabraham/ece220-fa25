/* Swaps `one` with `two` */
void swap(int *one, int *two) {
  int temp = *one;
  *one = *two;
  *two = temp;
}

void sort(int arr[], int n) {
  int i, j, flag;
  for (i = 0; i < n - 1; i++) {
    flag = 0;
    for (j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        swap(&arr[i], &arr[j]);
        flag++;
      }
    }
    if (flag == 0)
      break;
  }
}
