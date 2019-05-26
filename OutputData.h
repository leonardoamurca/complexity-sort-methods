#ifndef OUTPUTDATA_H
#define OUTPUTDATA_H
#include "InputData.h"

#include <string>
#include <fstream>

class OutputData : public InputData {
  
  public:
    
    OutputData() { }; 
    void setArrayType(string type);
    void setArraySize(int size);
    void setSortMethod(string method);
    void setComparisonsQtd(long int comparisons, int i);
    void setMovimentationsQtd(long int movimentations, int i);
    void setRuntime(double time, int i);
    void writeOnFile(string fileName);

  private:

    long int comparisonsQtd; // Número de comparações
    long int movimentationsQtd; // Número de movimentações
    double runtime; // Tempo gasto (em milisegundos)
};

void OutputData::setArrayType(string type) {
  arrayType = type;
}

void OutputData::setArraySize(int size) {
  arraySize = size;
}

void OutputData::setSortMethod(string method) {
  sortMethod = method;
}

void OutputData::setComparisonsQtd(long int comparisons, int i) {
  comparisonsQtd = comparisons;
}

void OutputData::setMovimentationsQtd(long int movimentations, int i) {
  movimentationsQtd = movimentations;
}

void OutputData::setRuntime(double time, int i) {
  runtime = time;
}


void OutputData::writeOnFile(string fileName) {
  int qtdOfSamples = 4;
  OutputData *outputAux = new OutputData[qtdOfSamples];
  string line;
  ofstream outputFile(fileName);

  for (int i = 0; i < qtdOfSamples; i++) {
    outputFile << "Runtime: " << outputAux[i].runtime << " ms" << endl;
    outputFile << "Comparisons: " << outputAux[i].comparisonsQtd << endl;
    outputFile << "Movimentations: " << outputAux[i].movimentationsQtd << endl;
    outputFile << " " << endl;
  }

  outputFile.close();
  delete[] outputAux;
}


#endif