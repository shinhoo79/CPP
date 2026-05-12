#include <iostream>
using namespace std;

class Complex {
public:
    double real, img;

    Complex(double r = 0, double i = 0) {
        real = r;
        img = i;
    }

    void print() {
        cout << real << " + " << img << "i" << endl;
    }
};

void add(Complex a, Complex b, Complex& result) {
    result.real = a.real + b.real;
    result.img = a.img + b.img;
}

Complex add_return(Complex a, Complex b) {
    return Complex(a.real + b.real, a.img + b.img);
}

int main() {
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c;

    add(a, b, c);
    c.print();

    c = add_return(a, b);
    c.print();

    return 0;
}