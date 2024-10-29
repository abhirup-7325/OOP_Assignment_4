/*
Design a COMPLEX class, which will behave like normal integer with respect to

 addition,
 subtraction,
 accepting the value and
 Displaying the value.
*/


#include <iostream>


class Complex {
public:
    Complex(double real, double imag) {
        _real = real;
        _imag = imag;
    }

    double getRealPart() const {
        return _real;
    }

    double getImagPart() const {
        return _imag;
    }

    Complex operator+(Complex other) {
        return Complex(_real + other.getRealPart(), _imag + other.getImagPart());
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& c) {
        out << c.getRealPart() << " + " << c.getImagPart() << "i";
        return out;
    }

private:
    double _real;
    double _imag;
};


int main() {
    

    return 0;
}