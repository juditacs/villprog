/*
 * inherit.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

class A {
public:
    virtual void f2() {std::cout << "AF2";}
    virtual ~A () {std::cout << "AD";}
};
class B: public A {
public:
    B() {}
    B(const B&) {std::cout << "Bcpy";}
    void f1() {std::cout << "BF1";}
    void f2() {std::cout << "BF2";}
    ~B () {std::cout << "BD";}
};
class C: public A {
};
class D: public B {
public:
    void f1() {std::cout << "DF1";}
    void f2() {std::cout << "DF2";}
    ~D () {std::cout << "DD";}
};
B func(A* pa) {
    B b;
    return b;
}
int main(int argc, char* argv[]) {
    A* pa = new D;
    func(pa);
    delete pa;

    B* pb = new D;
    pb->f1();
    pb->f2();
    std::cout << std::endl;
}

