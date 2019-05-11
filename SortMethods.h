#ifndef SORTMETHODS_H
#define SORTMETHODS_H

#include <iostream>
using namespace std;

class SortMethods {

  public: 
    SortMethods(int _array[], int _arraySize);
    void bubbleSort();

  private:
    int *array;
    int arraySize;
};

// Construtor
SortMethods::SortMethods(int _array[], int _arraySize) {
  array = _array;
  arraySize = _arraySize;
}

void SortMethods::bubbleSort() {
  for (int i = 0; i < arraySize; i++) {
    cout << array[i] << endl;
  }  
  cout << "Tamanho: " << arraySize << endl;
}

#endif