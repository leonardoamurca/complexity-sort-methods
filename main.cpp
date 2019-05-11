#include <iostream>
#include "SortMethods.h"
#include "InputInfo.h"
#include "SortMethods.h"

using namespace std;

int main() {
  
  // Testando métodos do InputType
  InputInfo i;
  cout << i.getArrayType() << endl;
  cout << i.getArraySize() << endl;
  cout << i.getSortMethod() << endl;
  cout << i.generateData()[0] << endl;

  

  
  // Testando métodos do SortMethods
  int arr[] = {5, 2, 4, 1, 0, -1};
  SortMethods s(arr, 6);
  s.bubbleSort();


  
  return 0;
}