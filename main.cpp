#include <iostream>
#include "SortMethods.h"

using namespace std;

int main() {
  
  SortMethods inputs;
  inputs.readFile();
  inputs.sort();
  inputs.bubbleSort();
  
  return 0;
}