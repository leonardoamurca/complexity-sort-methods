#ifndef SORTMETHODS_H
#define SORTMETHODS_H
#include "InputInfo.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class SortMethods {

  public: 
    SortMethods() { };
    void bubbleSort();
    void readFile();
    

  private:
    int *array;
    int arraySize;
    InputInfo *input;
  
  friend class InputInfo;
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

void SortMethods::bubbleSort() {
  cout << "Bubble Sort!" << endl;
  for (int i = 0; i < 3; i++) {
    cout << input[i].arrayType << endl;
    cout << input[i].arraySize << endl;
    cout << input[i].sortMethod << endl;
  }
}

#endif