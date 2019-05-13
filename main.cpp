#include <iostream>
#include "SortMethods.h"

using namespace std;

int main() {
  
  SortMethods sort;
  sort.readFile();
  sort.generateArray();
  sort.bubbleSort();
  
  return 0;
}