#ifndef INSERTIONSORTER_H
#define INSERTIONSORTER_H

#include <fstream>
#include "BaseSorter.h"
using namespace std;

class InsertionSorter : public BaseSorter{
  public:
  void sort(int A[]);

  protected:
    InsertionSorter(ifstream& ifs, int size) : BaseSorter(ifs, size);

    void print();
};

#endif
