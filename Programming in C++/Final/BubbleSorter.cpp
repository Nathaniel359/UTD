#include "BubbleSorter.h"
#include <fstream>
using namespace std;

BubbleSorter::BubbleSorter(ifstream& ifs, int size) : BaseSorter(ifs, size) {
  ifs.clear();
  ifs.seekg(0);
  
  buf = new int[numEntries];

  for(int i = 0; i < numEntries; i++)
    ifs >> buf[i];
};

void BubbleSorter::print() {
  print();
}

void BubbleSorter::sort(int A[]) {
  sort();
  A = buf;
  for (int i = 0; i <= sizeof(&A) - 1; i++) {
    for (int j = sizeof(&A); i >= i + 1; j--) {
      if (A[j] < A[j-1]) {
         swap(A[j], A[j-1]);
      }
    }
  }
}
