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
    void readFile();
    void generateArray(int i, int size, string type);
    void bubbleSort();
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


void SortMethods::readFile() {
  setQtdOfSamples();
  InputData *inputAux = new InputData[qtdOfSamples];
  string line;
  ifstream txtFile;
  txtFile.open("100.txt");
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

void SortMethods::bubbleSort() {
  cout << "Bubble Sort!" << endl;
}

void SortMethods::sort() {

  for (int i = 0; i < qtdOfSamples; i++) {
    generateArray(i, input[i].getArraySize(), input[i].getArrayType());
    input[i].printArray();
  }
}


#endif