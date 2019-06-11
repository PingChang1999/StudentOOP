#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

bool operator== (const Complex& c1, const Complex& c2) {
	// /*
	if (c1.get_real() == c2.get_real() && c1.get_imag() == c2.get_imag()) {
		return true;
	}
	return false;
	// */
	return true;
}

ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
}


Complex::operator bool() const {
}

Complex& Complex::operator++() {
}

Complex Complex::operator++(int dummy) {
}

Complex operator+(const Complex& c1, const Complex& c2) {
}

double Complex::get_real() const {
}

double Complex::get_imag() const {
}

Complex Complex::operator*(const int i) {
}
