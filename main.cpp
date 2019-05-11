#include <iostream>
#include "SortMethods.h"

using namespace std;

int main() {

  int arr[] = {5, 2, 4, 1};

  SortMethods s(arr);
  s.bubbleSort();

  return 0;
}