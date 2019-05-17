#include <iostream>
#include <string>
#include "SortMethods.h"

using namespace std;

int main() {
  
  // Entrada de dados pelo usuário
  //string fileName;
  //cout << "Digite o nome do arquivo com as entradas (Ex: 100.txt): " << endl;
  //cin >> fileName;

  // Processamento das amostras
  SortMethods inputs;
  // inputs.readFile(fileName);
  inputs.readFile("100.txt");
  inputs.sort();
  
  return 0;
}