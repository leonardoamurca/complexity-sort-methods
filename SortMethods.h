#ifndef SORTMETHODS_H
#define SORTMETHODS_H

#include "InputData.h"
#include "OutputData.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>
#include <limits>  
using namespace std;

class SortMethods {

  public: 

    SortMethods() { };
    void readFile(string fileName, int fileSamplesQtd);
    void generateArray(int i, int size, string type);
    void sort();
    int setQtdOfSamples(string fileName);
    void printOriginalArray(int i);
    void printSortedArray(int i); 
    void bubbleSort(int arr[], int size, int i);
    void insertionSort(int arr[], int size, int i);
    void selectionSort(int arr[], int size, int i);
    double runtime(clock_t tStart);

  private:

    InputData *input;
    OutputData *output;
    int qtdOfSamples;
    int *array;
  
};

int SortMethods::setQtdOfSamples(string fileName) {
  string line;
  qtdOfSamples = 0;
  ifstream txtFile;
  txtFile.open(fileName);
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
  return qtdOfSamples;
}


void SortMethods::readFile(string fileName, int fileSamplesQtd) {
  InputData *inputAux = new InputData[fileSamplesQtd];
  OutputData *outputAux = new OutputData[fileSamplesQtd];
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
      // cout << line << endl;
        outputAux[c].setSortMethod(line);
        inputAux[c].setSortMethod(line);
        c++;
        break;
    }
    i++;
  }
  txtFile.close();

  input = inputAux;
  output = outputAux;
  delete [] outputAux;
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
  clock_t tStart = clock();
  long int comparisons = 0;
  long int movimentations = 0;
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
  output[i].setRuntime(runtime(tStart));
  output[i].setComparisonsQtd(comparisons);
  output[i].setMovimentationsQtd(movimentations);
}

void SortMethods::insertionSort(int arr[], int size, int i) {
  clock_t tStart = clock();
  long int comparisons = 0;
  long int movimentations = 0;

  int key, j;  
  for (int k = 1; k < size; k++) {  
    movimentations++;
    key = arr[k];  
    j = k - 1;
    comparisons ++;
    while (j >= 0 && arr[j] > key) {
      movimentations++;;  
      arr[j + 1] = arr[j];  
      j = j - 1;  
    }  
    movimentations++;
    arr[j + 1] = key;  
  }  

  output[i].setRuntime(runtime(tStart));
  output[i].setComparisonsQtd(comparisons);
  output[i].setMovimentationsQtd(movimentations);
}

void SortMethods::selectionSort(int arr[], int size, int i) {
  clock_t tStart = clock();
  long int comparisons = 0;
  long int movimentations = 0;

  int first, temp;
  for (int k = size - 1; k > 0; k--) {
    first = 0;
    for (int j = 1; j <= k; j++) {
      comparisons++;
      if (arr[j] < arr[first])
        first = j;
    }
    movimentations++;
    temp = arr[first]; 
    movimentations++;
    arr[first] = arr[k];
    movimentations++;
    arr[k] = temp;
  }
  output[i].setRuntime(runtime(tStart));
  output[i].setComparisonsQtd(comparisons);
  output[i].setMovimentationsQtd(movimentations);
}



void SortMethods::sort() {
  for (int i = 0; i < qtdOfSamples; i++) {
    generateArray(i, input[i].arraySize, input[i].arrayType);
    //printOriginalArray(i);

    if (input[i].sortMethod == "Bubble") {
      bubbleSort(input[i].array, input[i].arraySize, i);
    } else if (input[i].sortMethod == "Insertion") {
      insertionSort(input[i].array, input[i].arraySize, i);
    } else if (input[i].sortMethod == "Selection") { 
      selectionSort(input[i].array, input[i].arraySize, i);
    }
    //printSortedArray(i);  
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

double SortMethods::runtime(clock_t tStart) {
  return (double) (clock() - tStart)/1000; // Tempo de relogio (em ms)
}

#endif