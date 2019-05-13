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
    

  private:

    int *array;
    int arraySize;
    InputData *input;
  
};


void SortMethods::readFile() {
  string line;
  ifstream txtFile;
  txtFile.open("100.txt");
  int i = 0;
  int a = 0, b = 0, c = 0;
  while (getline(txtFile, line)) {
    if (!line.length()) {
      i = 0;
    } 
    if (i == 1) {
      input[a].arrayType = line;
      a++;
    }
    if (i == 2) {
      input[b].arraySize = stoi(line);
      b++;
    }
    if (i == 3) {
      input[c].sortMethod = line;
      c++;
    }
    i++;
  }
  txtFile.close();
}

void SortMethods::generateArray() {
  arraySize = input[0].arraySize;
  int *arr = new int[arraySize];
  
  for(int i = 0; i < arraySize; i++) {
    arr[i] = rand()/10000000;
  }
  array = arr;
}

void SortMethods::bubbleSort() {
  cout << "Bubble Sort!" << endl;
 
  for (int i = 0; i < arraySize; i++) {
    cout << array[i] << " ";
  }
}


#endif