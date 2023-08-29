#include <iostream>
#include "ComplexNumber.h"
using namespace std;

// class variables
double real;
double imgnry;

// constructor
ComplexNumber::ComplexNumber(double r, double i) {
  real = r;
  imgnry = i;
}

// sum of two complex numbers
ComplexNumber ComplexNumber::operator+(ComplexNumber c) {
  ComplexNumber d(real + c.real, imgnry + c.imgnry);
  return d;
} 
// difference between two complex numbers
ComplexNumber ComplexNumber::operator-(ComplexNumber c) {
  ComplexNumber d(real - c.real, imgnry - c.imgnry);
  return d;
} 

// product of two complex numbers
ComplexNumber ComplexNumber::operator*(ComplexNumber c) {
  ComplexNumber d(real * c.real, imgnry * c.imgnry);
  return d;
} 

// result of the division operation involving two complex numbers
ComplexNumber ComplexNumber::operator/(ComplexNumber c) {
  ComplexNumber d(real / c.real, imgnry / c.imgnry);
  return d;
} 

// Complex conjugate
ComplexNumber ComplexNumber::operator~() {
  ComplexNumber d(real, -1 * imgnry);
  return d;
} 

  // Displays the value of the complex number in the form
    // a + bi or
    // a - bi
    //
  // If there is no imaginary part, only the real part is displayed
ostream& operator<< (ostream& ostr, const ComplexNumber& obj) {
  if (obj.imgnry == 0)
    ostr << obj.real;
  else if (obj.imgnry > 0)
    ostr << obj.real << " + " << obj.imgnry << "i" << endl;
  else
    ostr << obj.real << " - " << abs(obj.imgnry) << "i" << endl;
  return ostr;
}
    
