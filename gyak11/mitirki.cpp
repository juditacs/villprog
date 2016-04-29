/*
 * mitirki.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

class B;

class A {
public:
    A() {std::cout<<"Adef\n";}
    A(const B&) {std::cout<<"ActorB\n";}
};

class C {
public:
    C(const B&) {std::cout<<"CctorB\n";}
    C(const C&) {std::cout<<"CctorCpy\n";}
    C() {std::cout<<"CctorDef\n";}
};

class B {
public:
    B(const A&) {std::cout<<"BctorA\n";}
    operator A() const {std::cout<<"BconvA\n"; return A();}
    operator C() const {std::cout<<"BconvC\n"; return C();}
};

int main(int argc, char* argv[]) {
    A a;
    B b = a;
    A a2 = b;
    b = a;
    C c((B)a);
}

