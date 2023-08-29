#ifndef QUICKSORTER_H
#define QUICKSORTER_H

#include <fstream>
#include "BaseSorter.h"
using namespace std;

class QuickSorter : public BaseSorter{
  public:
  void sort(int A[], int p, int r);

  protected:
    QuickSorter(ifstream& ifs, int size) : BaseSorter(ifs, size);

    void print();

    int partition(int A[], int p, int r);

};

#endif
