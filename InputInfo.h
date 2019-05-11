#ifndef INPUTINFO_H
#define INPUTINFO_H

#include <iostream>
#include <string>

class InputInfo {

  public:
    InputInfo();
    string getArrayType();
    int getArraySize();
    string getSortMethod();
    int *generateData();

  private:
    string sortMethod;
    int arraySize;
    string arrayType;

  friend class SortMethods;
};

InputInfo::InputInfo() {
  sortMethod = "";
  arraySize = 0;
  arrayType = "";
}

string InputInfo::getArrayType() {
  return "OrdC";
}

int InputInfo::getArraySize() {
  return 5;
}

string InputInfo::getSortMethod() {
  return "Bubble";
}

int *InputInfo::generateData() {
  arraySize = getArraySize();
  arrayType = getArrayType();
  int *array = new int[arraySize];

  cout << arrayType << endl;
  if (arrayType == "OrdC") {
    for(int i = 0; i < arraySize; i++) {
      array[i] = rand()/100000000;
      cout << array[i] << " ";
    }
    cout << endl;
  } else if (arrayType == "OrdD") {
    for(int i = 0; i < arraySize; i++) {
      array[i] = 1;
    }
  } else if (arrayType == "OrdA") {
    for(int i = 0; i < arraySize; i++) {
      array[i] = 2;
    }
  } else if (arrayType == "OrdP") {
    for(int i = 0; i < arraySize; i++) {
      array[i] = 3;
    }
  } else {
    cout << "Erro na leitura do Tipo!" << endl;
  }
  return array;
}

#endif