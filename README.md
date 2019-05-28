# Complexity Sort Methods
Analysis and Reporting of the complexity of the following sorting methods: BubbleSort, InsertSort, SelectionSort, ShellSort, QuickSort, and HeapSort.

This project counts the number of: movimentations, comparisons and runtime of each of the sorting algorithms mentioned above.

## Bubble Sort
```cpp 
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

## Insertion Sort

```cpp
  for (int k = 1; k < size; k++) {  
    movimentations++;
    key = arr[k];  
    j = k - 1;
    comparisons ++;
    while (j >= 0 && arr[j] > key) {
      movimentations++;;  
      arr[j + 1] = arr[j];  
      j = j - 1;  
    }  
    movimentations++;
    arr[j + 1] = key;  
  }  
```

## Selection Sort

```cpp
  int first, temp;
  for (int k = size - 1; k > 0; k--) {
    first = 0;
    for (int j = 1; j <= k; j++) {
      comparisons++;
      if (arr[j] < arr[first])
        first = j;
    }
    movimentations++;
    temp = arr[first]; 
    movimentations++;
    arr[first] = arr[k];
    movimentations++;
    arr[k] = temp;
  }
```

## Shell Sort

```cpp
  for (int gap = size/2; gap > 0; gap /= 2) { 
    for (int i = gap; i < size; i++) { 
      int temp = arr[i]; 
      int j;
      comparisons+=2;             
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        movimentations++;
        arr[j] = arr[j - gap]; 
      }
      movimentations++;    
      arr[j] = temp; 
    } 
  } 
```

## Quick Sort
```cpp
void quickSort(int arr[], int l, int h) {
  comparisons++;
  if (l < h) { 
    /* Partitioning index */
    int p = partition(arr, l, h, comparisons, movimentations); 
    quickSort(arr, l, p - 1); 
    quickSort(arr, p + 1, h); 
  }
}

int partition(int arr[], int l, int h, long int &c, long int &m)  { 
  int x = arr[h]; 
  int i = (l - 1); 
  int aux;
  for (int j = l; j <= h - 1; j++) { 
    c++;
    if (arr[j] <= x) { 
      i++; 
      m++;
      aux = arr[i];
      m++;
      arr[i] = arr[j];
      m++;
      arr[j] = aux; 
    } 
  } 
  m++;
  aux = arr[i+1];
  m++;
  arr[i+1] = arr[h];
  m++;
  arr[h] = aux;

  return (i + 1); 
} 
```