#include <iostream>
#include "SortMethods.h"
#include "InputInfo.h"
#include "SortMethods.h"

using namespace std;

int main() {
  
  // Testando métodos do InputType
  InputInfo input;
  
    // Testando métodos do SortMethods
  SortMethods s(input.generateData(), 5);
  s.bubbleSort();


  
  return 0;
}