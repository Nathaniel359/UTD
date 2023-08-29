#ifndef BUBBLESORTER_H
#define BUBBLESORTER_H

#include <fstream>
#include "BaseSorter.h"
using namespace std;

class BubbleSorter : public BaseSorter{
  public:
  void sort(int A[]);

  protected:
    BubbleSorter(ifstream& ifs, int size); 
      
    void print();
};
#endif
