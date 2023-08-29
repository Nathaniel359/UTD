#include <iostream>
using namespace std;
#include "ComplexNumber.h"

////////////////////////////////////////////////////////////////////
//
// Test method for adding two complex numbers and displaying
// the result.
//
////////////////////////////////////////////////////////////////////
void addComplex() {
  double dVar1, dVar2;
  cout << "Enter the data for the first ComplexNumber number (two floats, separated by white space): ";
  cin >> dVar1 >> dVar2;
  cin.ignore();

  ComplexNumber c1(dVar1, dVar2);

  cout << "Enter the data for the second ComplexNumber number (two floats, separated by white space): ";
  cin >> dVar1 >> dVar2;
  cin.ignore();

  ComplexNumber c2(dVar1, dVar2);

  ComplexNumber c3 = c1 + c2;

  cout << "The sum of the two ComplexNumber numbers is " << c3 << endl;
}


////////////////////////////////////////////////////////////////////
//
// Test method for subtracting two complex numbers and displaying
// the result.
//
////////////////////////////////////////////////////////////////////
void subtractComplex() {
  double dVar1, dVar2;
  cout << "Enter the data for the first ComplexNumber number (two floats, separated by white space): ";
  cin >> dVar1 >> dVar2;
  cin.ignore();

  ComplexNumber c1(dVar1, dVar2);

  cout << "Enter the data for the second ComplexNumber number (two floats, separated by white space): ";
  cin >> dVar1 >> dVar2;
  cin.ignore();

  ComplexNumber c2(dVar1, dVar2);

  ComplexNumber c3 = c1 - c2;

  cout << "The difference between the two ComplexNumber numbers is " << c3 << endl;
}


////////////////////////////////////////////////////////////////////
//
// Test method for multiplying two complex numbers and displaying
// the result.
//
////////////////////////////////////////////////////////////////////
void multiplyComplex() {
  double dVar1, dVar2;
  cout << "Enter the data for the first ComplexNumber number (two floats, separated by white space): ";
  cin >> dVar1 >> dVar2;
  cin.ignore();

  ComplexNumber c1(dVar1, dVar2);

  cout << "Enter the data for the second ComplexNumber number (two floats, separated by white space): ";
  cin >> dVar1 >> dVar2;
  cin.ignore();

  ComplexNumber c2(dVar1, dVar2);

  ComplexNumber c3 = c1 * c2;

  cout << "The product of the two ComplexNumber numbers is " << c3 << endl;
}


////////////////////////////////////////////////////////////////////
//
// Test method for dividing two complex numbers and displaying
// the result.
//
////////////////////////////////////////////////////////////////////
void divideComplex() {
  double dVar1, dVar2;
  cout << "Enter the data for the first ComplexNumber number (two floats, separated by white space): ";
  cin >> dVar1 >> dVar2;
  cin.ignore();

  ComplexNumber c1(dVar1, dVar2);

  cout << "Enter the data for the second ComplexNumber number (two floats, separated by white space): ";
  cin >> dVar1 >> dVar2;
  cin.ignore();

  ComplexNumber c2(dVar1, dVar2);

  ComplexNumber c3 = c1 / c2;

  cout << "The result of the division of the two ComplexNumber numbers is " << c3 << endl;
}


////////////////////////////////////////////////////////////////////
//
// Test method for displaying the complex number conjugate.
//
////////////////////////////////////////////////////////////////////
void displayConjugate() {
  double dVar1, dVar2;
  cout << "Enter the data for the ComplexNumber number (two floats, separated by white space): ";
  cin >> dVar1 >> dVar2;
  cin.ignore();

  ComplexNumber c1(dVar1, dVar2);

  ComplexNumber c2 = ~c1;

  cout << "The conjugate of the ComplexNumber number is " << c2 << endl;
}


////////////////////////////////////////////////////////////////////
//
// main method
//
////////////////////////////////////////////////////////////////////
int main()
{
  bool breakLoop = false;
  while(!breakLoop) {
    int usrChoice;
    cout << "\n\n Main Menu";
    cout << "\n =========\n";
    cout << "\n 1. Add";
    cout << "\n 2. Subtract";
    cout << "\n 3. Multiply";
    cout << "\n 4. Divide";
    cout << "\n 5. Find conjugate";
    cout << "\n 0. Exit";
    cout << "\n Please enter your selection: ";

    cin >> usrChoice;

    switch(usrChoice) {
      case 0:
        cout << "Goodbye...\n" << endl;
        breakLoop = true;
        break;

      case 1:
        addComplex();
         break;

      case 2:
        subtractComplex();
        break;
        
      case 3:
        multiplyComplex();
        break;
        
      case 4:
        divideComplex();
        break;
        
      case 5:
        displayConjugate();
        break;
        
      default:
        cout << "Invalid selection, try again\n";
        break;
     }
  }

  return 0;
}
