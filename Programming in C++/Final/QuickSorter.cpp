#include "QuickSorter.h"
#include <fstream>
using namespace std;

QuickSorter::QuickSorter(ifstream& ifs, int size) : BaseSorter(ifs, size) {
  ifs.clear();
  ifs.seekg(0);
  
  buf = new int[numEntries];

  for(int i = 0; i < numEntries; i++)
    ifs >> buf[i];
};

void QuickSorter::sort(int A[], int p, int r) {
  sort();
  A = buf;   
  if (p < r) {
    int q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

void QuickSorter::print() {
  print();
}

int QuickSorter::partition(int A[], int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j <= r - 1; j++) {
    if (A[j] <= x) {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i+1], A[r]);
  return i + 1;
}
