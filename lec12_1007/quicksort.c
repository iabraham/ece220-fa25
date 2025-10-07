void Swap(int *one, int *two) {
  int temp = *one;
  *one = *two;
  *two = temp;
}

int partition(int arr[], int start, int end) {

  int pivotVal = arr[start];
  int left = start - 1;
  int right = end + 1;

  while (1) {
    do
      left++;
    while (arr[left] < pivotVal);

    do
      right--;
    while (arr[right] > pivotVal);

    if (left >= right)
      return right;

    Swap(&arr[left], &arr[right]);
  }
}

void QuickSort(int arr[], int start, int end) {
  if (start < end) {
    int split = partition(arr, start, end);
    QuickSort(arr, start, split);
    QuickSort(arr, split + 1, end);
  }
}
