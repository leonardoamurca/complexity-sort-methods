#include <iostream>
#include "SortMethods.h"
#include "InputInfo.h"

using namespace std;

int main() {
  
  // Testando métodos do InputType
  InputInfo i;
  cout << i.getSortMethod() << endl;
  cout << i.getArraySize() << endl;
  cout << i.getArrayType() << endl;

  
  // Testando métodos do SortMethods
  int arr[] = {5, 2, 4, 1, 0, -1};
  SortMethods s(arr, 6);
  s.bubbleSort();

  
  return 0;
}