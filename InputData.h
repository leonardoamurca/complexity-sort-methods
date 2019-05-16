#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <iostream>
#include <string>

using namespace std;

class InputData {

  public:
  
    InputData() { };
    string getArrayType();
    string getSortMethod();
    int getArraySize();
    int *generateData();
    int *getArray();
    void setArrayType(string type);
    void setArraySize(int size);
    void setSortMethod(string method);
    void setArrayOrdC(int arr[], int size);
    void setArrayOrdA(int arr[], int size);
    void setArrayOrdD(int arr[], int size);
    void setArrayOrdP(int arr[], int size);
    void printArray();

    private:
      
      int arraySize;
      string arrayType;
      string sortMethod;
      int *array;
    
};

int InputData::getArraySize() {
  return arraySize;
}

string InputData::getArrayType() {
  return arrayType;
}

string InputData::getSortMethod() {
  return sortMethod;
}

int *InputData::getArray() {
  return array;
}

void InputData::setArrayType(string type) {
  arrayType = type;
}

void InputData::setArraySize(int size) {
  arraySize = size;
}

void InputData::setSortMethod(string method) {
  sortMethod = method;
}

void InputData::setArrayOrdC(int arr[], int size) {
  array = new int[size];

  for (int i = 0; i < size; i++) {
    array[i] = i;
  }
}

void InputData::setArrayOrdA(int arr[], int size) {
  array = new int[size];

  for (int i = 0; i < size; i++) {
    array[i] = rand()%100;
  }
}

void InputData::printArray() {
  cout << "[ ";
  for (int i = 0; i < arraySize; i++) {
    cout << array[i] << " ";
  }
  cout << "]" << endl;
}

void InputData::setArrayOrdD(int arr[], int size) {
  array = new int[size];

  for (int i = size; i >= 0; i--) {
    array[i] = i;
  }
}

void InputData::setArrayOrdP(int arr[], int size) {
  array = new int[size];

  for (int i = 0; i < size; i++) {
    array[i] = 4;
  }
}

#endif