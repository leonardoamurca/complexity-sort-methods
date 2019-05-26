#ifndef OUTPUTDATA_H
#define OUTPUTDATA_H
#include "InputData.h"

#include <string>

class OutputData : public InputData {
  
  public:
    
    OutputData() { }; 
    void setArrayType(string type);
    void setArraySize(int size);
    void setSortMethod(string method);
    void setComparisonsQtd(int comparisons, int i);
    void setMovimentationsQtd(int movimentations, int i);

  private:

    int comparisonsQtd; // Número de comparações
    int movimentationsQtd; // Número de movimentações
    int timeExpended; // Tempo gasto

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

void OutputData::setComparisonsQtd(int comparisons, int i) {
  comparisonsQtd = comparisons;
  cout << "Comparisons: " << comparisonsQtd << endl;
}

void OutputData::setMovimentationsQtd(int movimentations, int i) {
  movimentationsQtd = movimentations;
  cout << "Movimentations: " << movimentationsQtd << endl;
}


#endif