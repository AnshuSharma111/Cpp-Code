#include <iostream>
#include <math.h>
using namespace std;

// To emulate complex numbers using C++

class complex
{
    private:
        int real;
        int imaginary;
        float modulus;
    public:
        void setReal(int r) { real = r; }
        void setImag(int i) { imaginary = i; }

        int getReal() { return real; }
        int getImag() { return imaginary; }

        float getModulus()
        {
            modulus = sqrt((real * real) + (imaginary * imaginary));
            return modulus;
        }
};

complex operator+(complex a, complex b)
{
    complex c;
    c.setReal(a.getReal() + b.getReal());
    c.setImag(a.getImag() + b.getImag());
    return c;
}

ostream& operator<<(ostream& cout, complex a)
{
    cout << a.getReal() << " + " << "i" << a.getImag();
    return cout;
}

int main()
{
    complex a, b;
    int r, i;
    cout << "Enter the real and imaginary part of complex number 1: ";
    cin >> r >> i;
    a.setReal(r); a.setImag(i);
    cout << "Enter the real and imaginary part of complex number 2: ";
    cin >> r >> i;
    b.setReal(r); b.setImag(i);

    cout << "A is: " << a << " |A|: " << a.getModulus() << endl;
    cout << "B is: " << b << " |B|: " << b.getModulus() << endl;
    cout << "A+B is: " << a+b << endl;

    return 0;
}