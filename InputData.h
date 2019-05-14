#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <iostream>
#include <string>

using namespace std;

class InputData {

  public:
  
    InputData() { };
    string getArrayType();
    int getArraySize();
    string getSortMethod();
    int *generateData();
    void setArrayType(string type);
    void setArraySize(int size);
    void setSortMethod(string method);

    private:
      
      int arraySize;
      string arrayType;
      string sortMethod;
      int *array;
    
    friend class SortMethods;
};

string InputData::getArrayType() {
  return arrayType;
}

int InputData::getArraySize() {
  return arraySize;
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


#endif