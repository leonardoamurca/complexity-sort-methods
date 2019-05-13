#ifndef INPUTINFO_H
#define INPUTINFO_H

#include <iostream>
#include <string>

using namespace std;

class InputInfo {

  public:
  
    InputInfo() { };
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

string InputInfo::getArrayType() {
  return arrayType;
}

int InputInfo::getArraySize() {
  return arraySize;
}

string InputInfo::getSortMethod() {
  return sortMethod;
}
#endif