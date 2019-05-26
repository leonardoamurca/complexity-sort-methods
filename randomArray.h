#ifndef RANDOMARRAY_H
#define RANDOMARRAY_H

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <ctime> 
#include <cassert>

using namespace std;

// Gera um valor aleatório entre 0 e 1
float randomFloat();

// Converte um vetor de inteiros em uma string
string arrToString(int r[], int c);

// Converte "string" para "int"
int strToInt(string r);

// Converte uma string de 0s e 1s (Binária) em decimal
int binaryToDecimal(string a);

// Função que gera números aletórios de acordo com o intervalo
// dado pelo usuário
int generateRandomValue(int a, int b);

// Entrada de dados pelo usuário
//void inputValues(int &a, int &b, int &size);

int *randomArray(int a, int b, int size);

int *randomArray(int a, int b, int size) {
  srand(static_cast<unsigned int>(clock()));

  //inputValues(a, b, size);

  int *randomValues = new int[size];

  for (int i = 0; i < size; i++) {
    randomValues[i] = generateRandomValue(a, b);
  }

  return randomValues;
}

// Gera um valor aleatório entre 0 e 1
float randomFloat() {
  return ((float) rand()) / (float) RAND_MAX;
}

// Converte um vetor de inteiros em uma string
string arrToString(int r[], int c) {
  ostringstream oss("");
  for (int i = 0; i < c; i++) {
    oss << r[i];
  }

	return oss.str();
}

// Converte "string" para "int"
int strToInt(string r) {
  int n = stoi(r);
  return n;
}

// Converte uma string de 0s e 1s (Binária) em decimal
int binaryToDecimal(string a) {  
  int decimal = 0;
  int indexCounter = 0;
  for (int i = a.length()-1 ; i>=0 ; i--){
    if(a[i]=='1'){
      decimal += pow(2, indexCounter);
    }
  indexCounter++;
  }
  return decimal;
} 

// Função que gera números aletórios de acordo com o intervalo
// dado pelo usuário
int generateRandomValue(int a, int b) {
  int n, c;
  n = b - a;
  c = ceil(log(n) / log(2));
  float *r = new float[c];
  int *rInteger = new int[c];
  int rDecimal = n + 1;

  while (rDecimal > n) {
    for (int i = 0; i < c; i++) {
      r[i] = randomFloat();
      r[i] < 0.5 ? rInteger[i] = 0 : rInteger[i] = 1;
    }
    string rString = arrToString(rInteger, c);
    rDecimal = binaryToDecimal(rString);
  }
  return rDecimal + a;
}

// Entrada de dados pelo usuário
// void inputValues(int &a, int &b, int &size) {
//   cout << "Quantos números deseja gerar? " << endl;
//   cin >> size;

//   cout << "Digite o intervalo que deseja gerar os números aleatórios!" << endl;
  
//   cout << "Limite mínimo: ";
//   cin >> a;

//   cout << "Limite máximo: ";
//   cin >> b;
// }

#endif