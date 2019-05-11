#ifndef SORTMETHODS_H
#define SORTMETHODS_H

#include <iostream>

using namespace std;

class SortMethods {

  public: 
    SortMethods(int _unsortedArray[]);
    void bubbleSort();

  private:
    int *unsortedArray;
    int arraySize;
};

// Constructor
SortMethods::SortMethods(int _unsortedArray[]) {
  unsortedArray = _unsortedArray;
}

void SortMethods::bubbleSort() {
  for (int i = 0; i < 4; i++) {
    cout << unsortedArray[i] << endl;
  }
}

#endif