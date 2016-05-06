/*
 * generic_basics.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

// Mit kovetelunk meg a tarolando tipusoktol?
template <typename T>
class Container {
    T* t;
    int elementNum;
public:
    Container(): t(NULL), elementNum(0) {}
    void addElement(const T& newElement) {
        if (elementNum > 0) {
            T* newt = new T[elementNum+1];
            for (int i=0; i<elementNum; i++) newt[i] = t[i]; // operator=
            newt[elementNum++] = newElement;
            delete[] t;
            t = newt;
        }
        else {
            t = new T[++elementNum]; // default ctor
            t[elementNum-1] = newElement; // operator=
        }
    }
    T top() const { // copy ctor
        return t[elementNum-1];
    }
};

class Complex {
    double re, im;
public:
    Complex(double re=0, double im=0): re(re), im(im) {}
    double getRe() const { return re; }
    bool operator<(const Complex& rhs) {
        return (re*re + im*im) < (rhs.re*rhs.re + rhs.im*rhs.im);
    }
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.re << "+j" << c.im;
    return os;
}

// template fuggvenyek
template <typename T1, typename T2>
bool less(T1 a, T2 b) {
    return a < b;
}
template <typename T>
T min(T a, T b) {
    // hivhatunk masik template fuggvenyt,
    // mindket template parameter a T less,
    // less<T, T> peldanyosodik
    return less(a, b) ? a : b;
}
template <typename T, int N=5>
bool less_than_N(T t) {
    // nem tul ertelmes fuggveny, de nezzunk peldat
    // az int template parameterre
    return t < N;
}

// tegyuk fel, hogy a komplexeket ugy hasonlitjuk ossze, hogy
// csak a valos reszt nezzuk,
// ez nem realis, de mutat egy peldat a template specializaciora
template <>
bool less<Complex>(Complex c1, Complex c2) {
    return c1.getRe() < c2.getRe();
}

int main(int argc, char* argv[]) {
    int a=2, b=3;
    double d=4.5, d2=0.2;

    std::cout << min(a, b) << std::endl;
    std::cout << min(d, d2) << std::endl;
    std::cout << min<double>(a, d2) << std::endl;
    std::cout << std::boolalpha << less(a, d2) << std::endl;
    std::cout << std::boolalpha << less_than_N(a) << std::endl;

    Complex c1(3, 4), c2(3.1);
    std::cout << less(c1, c2) << std::endl;


    // Container test
    Container<Complex> complexContainer;
    complexContainer.addElement(c1);
    complexContainer.addElement(c2);

    std::cout << complexContainer.top() << std::endl;
}

