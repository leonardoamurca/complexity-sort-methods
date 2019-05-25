#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class InputData {

  public:
  
    InputData() { };
    void setArrayType(string type);
    void setArraySize(int size);
    void setSortMethod(string method);
    void setArrayOrdA(int arr[], int size);
    void setArrayOrdC(int arr[], int size);
    void setArrayOrdD(int arr[], int size);
    void setArrayOrdP(int arr[], int size);
    void printArray();

    int arraySize; // Tamanho do vetor
    string arrayType; // Tipo de ordenação || Tipo do vetor (OrdC, OrdD, OrdA ou OrdP)
    string sortMethod; // Método de ordenção (Bubble, Insert, Select)
    int *array; // Vetor

};

void InputData::setArrayType(string type) {
  arrayType = type;
}

void InputData::setArraySize(int size) {
  arraySize = size;
}

void InputData::setSortMethod(string method) {
  sortMethod = method;
}

void InputData::setArrayOrdA(int arr[], int size) {
  array = new int[size];

  for (int i = 0; i < size; i++) {
    array[i] = rand()%100;
  }
}

void InputData::setArrayOrdC(int arr[], int size) {
  array = new int[size];

  for (int i = 0; i < size; i++) {
    array[i] = i;
  }
}

void InputData::setArrayOrdD(int arr[], int size) {
  array = new int[size];
  int j = 0;
  for (int i = size; i > 0; i--) {
    array[j] = i;
    j++;
  }
}

void InputData::setArrayOrdP(int arr[], int size) {
  array = new int[size];
  for (int i = 0; i < size; i++) {
    i < floor(size*0.1) 
      ? array[i] = rand()%100
      : array[i] = i; 
  }
}

void InputData::printArray() {
  cout << "[ ";
  for (int i = 0; i < arraySize; i++) {
    cout << array[i] << " ";
  }
  cout << "]" << endl;
}

#endif