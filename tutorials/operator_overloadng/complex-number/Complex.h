#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

using std::ostream;

namespace caveofprogramming {

class Complex {
private:
	double real;
	double imaginary;

public:
	Complex();
	Complex(double real, double imaginary);
	Complex(const Complex& other);
	const Complex& operator=(const Complex& other);
	double getReal() const{ return real;}
	double getImaginary() const { return imaginary;}
};

ostream& operator<<(ostream& out, const Complex& other);
Complex operator+(const Complex& c1, const Complex& c2);
Complex operator+(const Complex& c1, const double d);
Complex operator+(const double d, const Complex& c1);
bool operator==(const Complex lhs, const Complex s);
bool operator!=(const Complex lhs, const Complex s);
Complex operator*(const Complex& c);

} /* namespace caveofprogramming */

#endif /* COMPLEX_H_ */
