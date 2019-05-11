#ifndef INPUTINFO_H
#define INPUTINFO_H

#include <iostream>
#include <string>

class InputInfo {

  public:
    InputInfo();
    string getSortMethod();
    int getArraySize();
    string getArrayType();
  
  private:
    string sortMethod;
    int arraySize;
    string arrayType;
};

InputInfo::InputInfo() {
  sortMethod = "";
  arraySize = 0;
  arrayType = "";
}

string InputInfo::getSortMethod() {
  return "Bubble";
}

int InputInfo::getArraySize() {
  return 100;
}

string InputInfo::getArrayType() {
  return "OrdC";
}

#endif