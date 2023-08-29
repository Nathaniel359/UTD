#include "InsertionSorter.h"
#include <fstream>
using namespace std;

InsertionSorter::InsertionSorter(ifstream& ifs, int size) : BaseSorter(ifs, size) {
  ifs.clear();
  ifs.seekg(0);
  
  buf = new int[numEntries];

  for(int i = 0; i < numEntries; i++)
    ifs >> buf[i];
};

void InsertionSorter::sort(int A[]) {
  sort();
  A = buf;
  int temp;
  for (int j = 1; j <= sizeof(&A); j++) {
    temp = A[j];
    int i = j-1;
    while (i >= 0 && A[i] > temp) {
      A[i + 1] = A[i];
      i--;
    }
    A[i+1] = temp;
  }
}



void InsertionSorter::print() {
  print();
}
