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
    void bubbleSort(int arr[], int size, int i, long int comparisons, long int movimentations, clock_t tStart);
    void insertionSort(int arr[], int size, int i, long int comparisons, long int movimentations, clock_t tStart);
    void selectionSort(int arr[], int size, int i, long int comparisons, long int movimentations, clock_t tStart);
    void shellSort(int arr[], int size, int i, long int comparisons, long int movimentations, clock_t tStart);
    void quickSort(int arr[], int l, int h, int i, long int comparisons, long int movimentations, clock_t tStart);
    int partition(int arr[], int l, int h, long int &c, long int &m) ;
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
  if (type == "OrdC") {
    input[i].setArrayOrdC(size);
  } else if (type == "OrdA")  {
    input[i].setArrayOrdA(size);
  } else if (type == "OrdD") {
    input[i].setArrayOrdD(size);
  } else if (type == "OrdP") {
    input[i].setArrayOrdP(size);
  } else {
    cout << "Erro ao gerar o vetor!" << endl;
  }
}

void SortMethods::bubbleSort(int arr[], int size, int i, long int comparisons, long int movimentations, clock_t tStart) {
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

void SortMethods::selectionSort(int arr[], int size, int i, long int comparisons, long int movimentations, clock_t tStart) {
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

void SortMethods::insertionSort(int arr[], int size, int i, long int comparisons, long int movimentations, clock_t tStart) {
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

void SortMethods::shellSort(int arr[], int size, int i, long int comparisons, long int movimentations, clock_t tStart) {
  for (int gap = size/2; gap > 0; gap /= 2) { 
    for (int i = gap; i < size; i++) { 
      int temp = arr[i]; 
      int j;
      comparisons+=2;             
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        movimentations++;
        arr[j] = arr[j - gap]; 
      }
      movimentations++;    
      arr[j] = temp; 
    } 
  } 
  output[i].setRuntime(runtime(tStart));
  output[i].setComparisonsQtd(comparisons);
  output[i].setMovimentationsQtd(movimentations);
}

void SortMethods::quickSort(int arr[], int l, int h, int i, long int comparisons, long int movimentations, clock_t tStart) { 
  comparisons++;
  if (l < h) { 
    /* Partitioning index */
    int p = partition(arr, l, h, comparisons, movimentations); 
    quickSort(arr, l, p - 1, i, comparisons, movimentations, tStart); 
    quickSort(arr, p + 1, h, i, comparisons, movimentations, tStart); 
  } else {
    // printSortedArray(i);  
  output[i].setRuntime(runtime(tStart));
  output[i].setComparisonsQtd(comparisons);
  output[i].setMovimentationsQtd(movimentations);
  } 
} 
  



void SortMethods::sort() {      
  for (int i = 0; i < qtdOfSamples; i++) {
    clock_t tStart;
    long int comparisons;
    long int movimentations;
    generateArray(i, input[i].arraySize, input[i].arrayType);
    if (input[i].sortMethod == "Bubble") {
      tStart = clock();
      comparisons = 0;
      movimentations = 0;
      bubbleSort(input[i].array, input[i].arraySize, i, comparisons, movimentations, tStart);
    } else if (input[i].sortMethod == "Insertion") {
      tStart = clock();
      comparisons = 0;
      movimentations = 0;
      insertionSort(input[i].array, input[i].arraySize, i, comparisons, movimentations, tStart);
    } else if (input[i].sortMethod == "Selection") { 
      tStart = clock();
      comparisons = 0;
      movimentations = 0;
      selectionSort(input[i].array, input[i].arraySize, i, comparisons, movimentations, tStart);
    } else if (input[i].sortMethod == "Shell") {
      tStart = clock();
      comparisons = 0;
      movimentations = 0;
      shellSort(input[i].array, input[i].arraySize, i, comparisons, movimentations, tStart);
    } else if (input[i].sortMethod == "Quick") {
      tStart = clock();
      comparisons = 0;
      movimentations = 0;
      quickSort(input[i].array, 0, input[i].arraySize - 1, i, comparisons, movimentations, tStart);
    }
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

int SortMethods::partition(int arr[], int l, int h, long int &c, long int &m)  { 
  int x = arr[h]; 
  int i = (l - 1); 
  int aux;
  for (int j = l; j <= h - 1; j++) { 
    c++;
    if (arr[j] <= x) { 
      i++; 
      m++;
      aux = arr[i];
      m++;
      arr[i] = arr[j];
      m++;
      arr[j] = aux; 
    } 
  } 
  m++;
  aux = arr[i+1];
  m++;
  arr[i+1] = arr[h];
  m++;
  arr[h] = aux;
  return (i + 1); 
} 

#endif