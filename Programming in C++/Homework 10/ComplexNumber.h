#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
using namespace std;

////////////////////////////////////////////////////////////////////
//
// Class to represent complex numbers
//
////////////////////////////////////////////////////////////////////
class ComplexNumber {
public:
  ComplexNumber(double r = 0, double i=0);

  ComplexNumber operator+(ComplexNumber); // sum of two complex numbers
  ComplexNumber operator-(ComplexNumber); // difference between two complex numbers
  ComplexNumber operator*(ComplexNumber); // product of two complex numbers
  ComplexNumber operator/(ComplexNumber); // result of the division operation involving two complex numbers
  ComplexNumber operator~(); // Complex conjugate

  friend ostream& operator<< (ostream& ostr, const ComplexNumber& obj);
    // Displays the value of the complex number in the form
    // a + bi or
    // a - bi
    //
    // If there is no imaginary part, only the real part is displayed


protected:
  double real, imgnry;
};
#endif // COMPLEXNUMBER_H
