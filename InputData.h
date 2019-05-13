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

    private:
      
      int arraySize;
      string arrayType;
      string sortMethod;
    
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
#endif