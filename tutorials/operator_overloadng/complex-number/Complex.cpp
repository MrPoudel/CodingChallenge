#include "Complex.h"

namespace caveofprogramming {

Complex::Complex():real(0), imaginary(0) {
	// TODO Auto-generated constructor stub
	cout << "Parameterless!" << endl;
}

Complex::Complex(double real, double imaginary):real(real), imaginary(imaginary){

}

Complex::Complex(const Complex& other){
	cout << "Copied" << endl;
	*this = other;    // This will again call the assignment operator.

	/* But the following code will not use the assignment operator. */
//	real = other.real;
//	imaginary = other.imaginary;
}

const Complex& Complex:: operator=(const Complex& other){
	cout << "Assignment" <<  endl;
	real = other.real;
	imaginary = other.imaginary;
	return *this;
}

ostream& operator<<(ostream& out, const Complex& other){
	out << "(" << other.getReal() << "," << other.getImaginary() << ")" << endl;
	return out;
}

Complex operator+(const Complex& c1, const Complex& c2){

	return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
}

Complex operator+(const Complex& c1, const double d){
	return Complex(c1.getReal() + d, c1.getImaginary() );
}

Complex operator+(const double d, const Complex& c1){
	return Complex(c1.getReal() + d, c1.getImaginary() );
}

} /* namespace caveofprogramming */
