#ifndef OUTPUTDATA_H
#define OUTPUTDATA_H
#include "InputData.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

class OutputData {
  
  public:
    
    OutputData() { }; 
    void setArrayType(string type);
    void setArraySize(int size);
    void setSortMethod(string method);
    void setComparisonsQtd(long int comparisons);
    void setMovimentationsQtd(long int movimentations);
    void setRuntime(double time);
    void writeOnFile(string fileName, int fileSamplesQtd);

    long int comparisonsQtd; // Número de comparações
    long int movimentationsQtd; // Número de movimentações
    double runtime; // Tempo gasto (em milisegundos)
    int arraySize; // Tamanho do vetor
    char *arrayType; // Tipo de ordenação || Tipo do vetor (OrdC, OrdD, OrdA ou OrdP)
    char *sortMethod; // Método de ordenção (Bubble, Insert, Select)

};

void OutputData::setArrayType(string type) {
  char *typeChar = new char[type.size() + 1];
	strcpy(typeChar, type.c_str());	// or pass &s[0]
  arrayType = typeChar;
}

void OutputData::setArraySize(int size) {
  arraySize = size;
}

void OutputData::setSortMethod(string method) {
	char *methodChar = new char[method.size() + 1];
	strcpy(methodChar, method.c_str());	// or pass &s[0]
  sortMethod = methodChar;
}

void OutputData::setComparisonsQtd(long int comparisons) {
  comparisonsQtd = comparisons;
}

void OutputData::setMovimentationsQtd(long int movimentations) {
  movimentationsQtd = movimentations;
}

void OutputData::setRuntime(double time) {
  runtime = time;
}


void OutputData::writeOnFile(string fileName, int fileSamplesQtd) {
  
  OutputData *outputAux = new OutputData[fileSamplesQtd];
  string line;
  ofstream outputFile(fileName);
  cout << sortMethod[0] << endl;

  for (int i = 0; i < fileSamplesQtd; i++) {
    outputFile << "Sort Method: " << outputAux[i].sortMethod << endl;
    outputFile << "Array Type: " << outputAux[i].arrayType << endl;
    outputFile << "Runtime: " << outputAux[i].runtime << " ms" << endl;
    outputFile << "Comparisons: " << outputAux[i].comparisonsQtd << endl;
    outputFile << "Movimentations: " << outputAux[i].movimentationsQtd << endl;
    outputFile << " " << endl;
  }

  outputFile.close();
  delete[] outputAux;
}


#endif