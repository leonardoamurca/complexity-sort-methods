#include <iostream>
#include <string>
#include "SortMethods.h"

using namespace std;

int main() {
  

  SortMethods inputs;
  string fileName;
  cout << "Digite o nome do arquivo com as entradas (Ex: 100.txt): " << endl;
  cin >> fileName;
  inputs.readFile(fileName);
  inputs.sort();
  inputs.bubbleSort();
  
  return 0;
}