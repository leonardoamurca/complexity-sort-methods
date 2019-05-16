#ifndef SORTMETHODS_H
#define SORTMETHODS_H

#include "InputData.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class SortMethods {

  public: 

    SortMethods() { };
    void readFile(string fileName);
    void generateArray(int i, int size, string type);
    void bubbleSort(int arr[], int size, int i);
    void sort();
    void setQtdOfSamples();

  private:

    InputData *input;
    int qtdOfSamples;
    int *array;

  friend class InputData;
  
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
  string line;
  ifstream txtFile;
  txtFile.open(fileName);
  int i = 0, a = 0, b = 0, c = 0;
  while (getline(txtFile, line)) {
    if (!line.length()) {
      i = 0;
    } 
    if (i == 1) {
      inputAux[a].setArrayType(line);
      a++;
    }
    if (i == 2) {
      inputAux[b].setArraySize(stoi(line));
      b++;
    }
    if (i == 3) {
      inputAux[c].setSortMethod(line);
      c++;
    }
    i++;
  }
  input = inputAux;
  txtFile.close();
}

void SortMethods::generateArray(int i, int size, string type) {
  int arraySize = input[i].getArraySize();
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
  for (int j = 0; j < size-1; j++) {
    for (int k = 0; k < size-j-1; k++) {
      if (arr[k] > arr[k+1]) {
        swap(arr[k], arr[k+1]); 
      }
    }
  }            
}

void SortMethods::sort() {
  for (int i = 0; i < qtdOfSamples; i++) {
    cout << endl;
    generateArray(i, input[i].getArraySize(), input[i].getArrayType());
    cout << "Array original: ";
    input[i].printArray();
    if (input[i].getSortMethod() == "Bubble") {
      bubbleSort(input[i].getArray(), input[i].getArraySize(), i);
    }
    cout << endl;
    cout << "Array ordenado: ";
    input[i].printArray();
    cout << endl;
    cout << "------------------------------------------------------------";
    cout << "------------------------------------------------------------";
    cout << "--------------------------------------------------------" << endl;
    
  }
}


#endif