#include <iostream>
#include "SortMethods.h"
#include "InputInfo.h"
#include "SortMethods.h"

using namespace std;

int main() {
  
  // Entrada de dados
  InputInfo input;
  int arraySize = input.getArraySize();
  int *array = input.generateData();
  string sortMethod = input.getSortMethod();
  
  // Instanciando objeto para a escolha do método de ordenação a ser usado
  SortMethods sort(array, arraySize);

  if(sortMethod == "Bubble") {
    sort.bubbleSort();
  } else {
    cout << "Errrou" << endl;
  }
  


  
  return 0;
}