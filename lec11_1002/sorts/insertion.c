void sort(int arr[], int n) {
  int i, current, k;
  for (i = 1; i < n; i++) {
    current = arr[i];
    for (k = i - 1; k >= 0 && arr[k] > current; k--)
      arr[k + 1] = arr[k];

    // Insert the current element into list[k+1]
    arr[k + 1] = current;
  }
}
