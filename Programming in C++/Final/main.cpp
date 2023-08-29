#include "BaseSorter.h"
#include "BubbleSorter.h"
#include "InsertionSorter.h"
#include "QuickSorter.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char *argv[]) {
  int read;
  int count;
  ifstream myFile;
  myFile.open(argv[1]);
  while(read >> myFile)
    count++;
  
  if (argv[2].compare("bubble")) {
    BubbleSorter b(myFile, count);
    b -> sort();
    b -> print();
  }
  /*else if (argv[2].compare("insertion")) {
    InsertionSorter i(myFile, count);
    i -> sort();
    i -> print();
  }
  else if (argv[2].compare("quick")) {
    QuickSorter q(myFile, count);
    q -> sort();
    q -> print();
  }*/
}
