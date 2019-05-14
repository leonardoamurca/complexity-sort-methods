#ifndef SORTMETHODS_H
#define SORTMETHODS_H

#include "InputData.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class SortMethods {

  public: 

    SortMethods() { };
    void readFile();
    void generateArray();
    void bubbleSort();
    void setQtdOfSamples();
    

  private:

    InputData *input;
    int qtdOfSamples;
    int *array;

  friend class InputData;
  
};

void SortMethods::setQtdOfSamples() {
  string line;
  qtdOfSamples = 0;
  ifstream txtFile;
  txtFile.open("100.txt");
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
}


void SortMethods::readFile() {
  InputData *inputAux = new InputData[qtdOfSamples];
  string line;
  ifstream txtFile;
  txtFile.open("100.txt");
  int i = 0, a = 0, b = 0, c = 0;
  while (getline(txtFile, line)) {
    if (!line.length()) {
      i = 0;
    } 
    if (i == 1) {
      inputAux[a].setArrayType(line);
      a++;
    }
    if (i == 2) {
      inputAux[b].setArraySize(stoi(line));
      b++;
    }
    if (i == 3) {
      inputAux[c].setSortMethod(line);
      c++;
    }
    i++;
  }
  input = inputAux;
  txtFile.close();
}

void SortMethods::generateArray() {
  int arraySize = input[0].arraySize;
  int *arr = new int[arraySize];
  
  for(int i = 0; i < arraySize; i++) {
    arr[i] = rand()/10000000;
  }
  input[0].array = arr;
}

void SortMethods::bubbleSort() {
  cout << "Bubble Sort!" << endl;

  for (int i = 0; i < input[0].getArraySize(); i++) {
    cout << input[0].array[i] << " ";
  }
 
}


#endif