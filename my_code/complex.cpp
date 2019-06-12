#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

bool operator== (const Complex& c1, const Complex& c2) {
	if (c1.get_real() == c2.get_real() && c1.get_imag() == c2.get_imag()) {
		return true;
	}
    return false;
}

bool operator!= (const Complex& c1, const Complex& c2) {
	if (c1.get_real() == c2.get_real() && c1.get_imag() == c2.get_imag()) {
		return false;
	}
	return true;
}

Complex operator+(const Complex& c1, const Complex& c2) {
	double new_real = c1.get_real() + c2.get_real();
	double new_imag = c1.get_imag() + c2.get_imag();
	Complex c3(new_real, new_imag);
	return c3;
}


ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
	os << c.get_real() << "+" << c.get_imag() << "i";
    return os;
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
	is >> c.real;
	is >> c.imag;
    return is;
}

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

Complex::operator bool() const {
	if ((real != 0) || (imag != 0)) {
		return true;
	}
	return false;
}

Complex& Complex::operator++() {
	++real;
    return *this;
}

Complex Complex::operator++(int dummy) {
	Complex temp = *this;
	real++;
	return temp;
}

Complex Complex::operator-=(const Complex& c) {
	real -= c.real;
	imag -= c.imag;
	return *this;
}

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

Complex Complex::operator*(const int i) {
	real *= i;
	imag *= i;
    return *this;
}

Complex& Complex::operator--() {
	--real;
	return *this;
}

Complex Complex::operator--(int dummy) {
	Complex temp = *this;
	real--;
	return temp;
}

Complex operator-(const Complex& c1, const Complex& c2) {
	double new_real = c1.get_real() - c2.get_real();
	double new_imag = c1.get_imag() - c2.get_imag();
	Complex c3(new_real, new_imag);
	return c3;
}