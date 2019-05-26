#ifndef SORTMETHODS_H
#define SORTMETHODS_H

#include "InputData.h"
#include "OutputData.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class SortMethods {

  public: 

    SortMethods() { };
    void readFile(string fileName);
    void generateArray(int i, int size, string type);
    void sort();
    void setQtdOfSamples();
    void printOriginalArray(int i);
    void printSortedArray(int i);
    
    void bubbleSort(int arr[], int size, int i);

  private:

    InputData *input;
    OutputData *output;
    int qtdOfSamples;
    int *array;
  
};

void SortMethods::setQtdOfSamples() {
  string line;
  qtdOfSamples = 0;
  ifstream txtFile;
  txtFile.open("100.txt");
  int i = 0;
  while(getline(txtFile, line)) {
    if (!line.length()) {
      i = 0;
    } 
    if (i == 1) {
      qtdOfSamples += 1;
    }
    i++;
  }
  txtFile.close();
}


void SortMethods::readFile(string fileName) {
  setQtdOfSamples();
  InputData *inputAux = new InputData[qtdOfSamples];
  OutputData *outputAux = new OutputData[qtdOfSamples];
  string line;
  ifstream txtFile;
  txtFile.open(fileName);
  int i = 0, a = 0, b = 0, c = 0;
  while (getline(txtFile, line)) {
    if (!line.length()) {
      i = 0;
    }
    switch (i) {
      case 1:
        inputAux[a].setArrayType(line);
        outputAux[a].setArrayType(line);
        a++;
        break;
      case 2:
        inputAux[b].setArraySize(stoi(line));
        outputAux[b].setArraySize(stoi(line));
        b++;
        break;
      case 3:
        inputAux[c].setSortMethod(line);
        outputAux[c].setSortMethod(line);
        c++;
        break;
    }
    i++;
  }
  input = inputAux;
  output = outputAux;
  delete[] inputAux;
  delete[] outputAux;

  txtFile.close();
}

void SortMethods::generateArray(int i, int size, string type) {
  int arraySize = input[i].arraySize;
  int *arr = new int[arraySize];

  if (type == "OrdC") {
    input[i].setArrayOrdC(arr, arraySize);
  } else if (type == "OrdA")  {
    input[i].setArrayOrdA(arr, arraySize);
  } else if (type == "OrdD") {
    input[i].setArrayOrdD(arr, arraySize);
  } else if (type == "OrdP") {
    input[i].setArrayOrdP(arr, arraySize);
  } else {
    cout << "Erro ao gerar o vetor!" << endl;
  }
}

void SortMethods::bubbleSort(int arr[], int size, int i) {
  int comparisons = 0;
  int movimentations = 0;
  int aux;
  for (int j = 0; j < size-1; j++) {
    for (int k = 0; k < size-j-1; k++) {
      comparisons++;
      if (arr[k] > arr[k+1]) {
        movimentations++;
        aux= arr[k];
        movimentations++;
        arr[k] = arr[k+1];
        movimentations++;
        arr[k+1] = aux; 
      }
    }
  }
  output[i].setComparisonsQtd(comparisons, i);
  output[i].setMovimentationsQtd(movimentations, i);
}

void SortMethods::sort() {
  for (int i = 0; i < qtdOfSamples; i++) {
    generateArray(i, input[i].arraySize, input[i].arrayType);
    printOriginalArray(i);

    if (input[i].sortMethod == "Bubble") {
      bubbleSort(input[i].array, input[i].arraySize, i);
    }
    printSortedArray(i);  
  }
}

void SortMethods::printOriginalArray(int i) {
  cout << "\n Array original: ";
  input[i].printArray();
}

void SortMethods::printSortedArray(int i) {
  cout << "\n Array ordenado: ";
  input[i].printArray();
  cout << endl;
  cout << "------------------------------------------------------------";
  cout << "------------------------------------------------------------";
  cout << "--------------------------------------------------------" << endl;
}




#endif