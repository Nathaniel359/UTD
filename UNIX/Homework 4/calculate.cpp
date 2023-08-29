#include "LineInfo.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

/*
Program Name: Calculate
Date: 2023-04-10
Author: Nathaniel Tan
Module Purpose
This program will calculate the sum, average, greatest,
or least value of a text file containing integers.
*/

int const COMMAND = 1;
int const FILE_NAME = 2;


int main(int argc, char *argv[]) {

  // incorrect number of arguments
  try {
    if (argc != 3)
      throw domain_error(LineInfo(
          "Wrong arguments \nUsage: \ncalculate < sum | average | greatest | "
          "least > filename.txt \nfilename ¦ a file that contains integers, 1 "
          "integer per line Example: \ncalculate sum filerandom.txt\n",
          __FILE__, __LINE__));
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }
  // invalid command
  try {
    if (strcmp(argv[COMMAND], "sum") != 0 && strcmp(argv[COMMAND], "average") != 0 &&
        strcmp(argv[COMMAND], "greatest") != 0 && strcmp(argv[COMMAND], "least") != 0)
      throw domain_error(
          LineInfo("Invalid Command: command \nUsage: \ncalculate < sum | "
                   "average | greatest | least > filename.txt \nfilename ¦ a "
                   "file that contains integers, 1 integer per line Example: "
                   "\ncalculate sum filerandom.txt\n",
                   __FILE__, __LINE__));
  } catch (exception &e) {
    cout << e.what() << endl;
    cout << "\nPress the enter key once or twice to leave...\n";
    cin.ignore();
    cin.get();
    exit(EXIT_FAILURE);
  }
  // copy file contents to vector
  vector<int> input;
  ifstream file(argv[FILE_NAME]);
  istream_iterator<int> iterator(file);
  if (file.is_open()) {
    copy(iterator, istream_iterator<int>(), back_inserter(input));
    file.close();
  }

  string output;
  if (strcmp(argv[COMMAND], "sum") == 0) {
    output = to_string(accumulate(input.begin(), input.end(), 0));
    cout << "./calculate sum " << argv[FILE_NAME] << endl << "Sum\t: " << output << endl;
  }
  if (strcmp(argv[COMMAND], "average") == 0) {
    output =
        to_string(accumulate(input.begin(), input.end(), 0) / input.size());
    cout << "./calculate average " << argv[FILE_NAME] << endl << "Average\t: " << output << endl;
  }
  if (strcmp(argv[COMMAND], "greatest") == 0) {
    auto max = max_element(input.begin(), input.end());
    cout << "./calculate greatest " << argv[FILE_NAME] << endl << "Greatest\t: " << *max << endl;
  }
  if (strcmp(argv[COMMAND], "least") == 0) {
    auto min = min_element(input.begin(), input.end());
    cout << "./calculate least " << argv[FILE_NAME] << endl << "Least\t: " << *min << endl;
  }
  exit(EXIT_SUCCESS);
}
