#include <iostream>
#include <string>
#include "SortMethods.h"
#include "OutputData.h"

using namespace std;

int main() {

  // Variavel que irá armazenar o numero de amostras de cada arquivo
  int fileSamplesQtd = 0;
  
  // Para instâncias de arrays de tamanhos: 100, 1000, 10000
  SortMethods inputs;
  string inputFileNames[3] = {
    "./InputFiles/100.txt", 
    "./InputFiles/1000.txt",
    "./InputFiles/10000.txt",
  };
  
  OutputData outputs;
  string outputFileNames[3] = {
    "./OutputFiles/100.txt", 
    "./OutputFiles/1000.txt",
    "./OutputFiles/10000.txt",
  };
  for (int i = 0; i < 3; i++) {
    fileSamplesQtd = inputs.setQtdOfSamples(inputFileNames[i]);
    inputs.readFile(inputFileNames[i], fileSamplesQtd);
    inputs.sort();
    outputs.writeOnFile(outputFileNames[i], fileSamplesQtd);
  }
   
  return 0;
}