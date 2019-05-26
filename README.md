# complexity-sort-methods
Analysis and Reporting of the complexity of the following sorting methods: BubbleSort, InsertSort, SelectSort, ShellSort, QuickSort, and HeapSort.

## Bubble Sort
```cpp 
  int comparisons = 0;
  int movimentations = 0;
  int aux;
  for (int j = 0; j < size-1; j++) {
    for (int k = 0; k < size-j-1; k++) {
      comparisons++;
      if (arr[k] > arr[k+1]) {
        movimentations++;
        aux= arr[k];
        movimentations++;
        arr[k] = arr[k+1];
        movimentations++;
        arr[k+1] = aux; 
      }
    }
```
