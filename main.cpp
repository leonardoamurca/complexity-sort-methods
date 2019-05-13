#include <iostream>
#include <fstream>
#include "SortMethods.h"
//#include "InputInfo.h"
//#include "SortMethods.h"

using namespace std;

// void readFile(InputInfo *input){
//   string line;
//   ifstream txtFile;
//   txtFile.open("100.txt");

//   int i = 0;
//   int j = 0;
//   while(getline(txtFile, line)) {
//     cout << "i: " << i << endl;
//     if(line == "" ) {
//       i=0;
//     }
//     cout << "j:" << j << endl;
//     if(i == 1) {
//       if(j < 3) {
//         input->arrayType = line; 
//       }
     
//     }
     
//     if(i == 3) {
//       if(j < 3) {
//         input->arraySize = 100;
//       }
    
//       j++;
//     }

//     if(i == 3) {
//       if(j < 3) {
//          input->sortMethod = line;
//       }
//     }
//     j++;  
//     i++;
    
//   }

//   txtFile.close();
// }

int main() {
  
  // Entrada de dados
  // InputInfo *input = new InputInfo[3];
  // int arrSize[3];

  SortMethods sort;
  sort.readFile();
  sort.bubbleSort();
  
  return 0;
}