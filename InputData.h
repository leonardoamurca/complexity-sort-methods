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
    void setArrayType(string type);
    void setArraySize(int size);
    void setSortMethod(string method);
    void setArray(int arr[], int size);
    void printArray();

    private:
      
      int arraySize;
      string arrayType;
      string sortMethod;
      int *array;
    
    //friend class SortMethods;
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

void InputData::setArrayType(string type) {
  arrayType = type;
}

void InputData::setArraySize(int size) {
  arraySize = size;
}

void InputData::setSortMethod(string method) {
  sortMethod = method;
}

void InputData::setArray(int arr[], int size) {
  array = new int[size];

  for (int i = 0; i < size; i++) {
    array[i] = rand()/10000000;
  }

  cout << "ola " << endl;
}

void InputData::printArray() {
  cout << "[ ";
  for (int i = 0; i < arraySize; i++) {
    cout << array[i] << " ";
  }
  cout << "]" << endl;
}


#endif