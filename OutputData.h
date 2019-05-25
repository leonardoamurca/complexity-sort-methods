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
    void setComparissonsQtd(int comparissons);

  private:

    int comparissonsQtd; // Número de comparações
    int drives; // Número de movimentações
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

void OutputData::setComparissonsQtd(int comparissons) {
  comparissonsQtd = comparissons;
}


#endif