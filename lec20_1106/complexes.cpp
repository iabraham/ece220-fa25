#include <iostream>
using namespace std;

class Complex {
  double real;
  double imag;

public:
  Complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
  }

  void print() {
    cout << "(" << this->real << " , " << this->imag << "j)" << endl;
  }

  Complex operator+(Complex c) {
    return Complex(this->real + c.real, this->imag + c.imag);
  }

  Complex operator*(Complex z) {
    double a = this->real;
    double b = this->imag;
    double c = z.real;
    double d = z.imag;

    return Complex(a * c - b * d, a * d + b * c);
  }
};

int main() {
  Complex c1 = Complex(2, 4);
  Complex c2 = Complex(3, -5);
  c1.print();
  c2.print();

  Complex c3 = c1 + c2;
  c3.print();

  Complex c4 = c1 * c2;
  c4.print();
}
