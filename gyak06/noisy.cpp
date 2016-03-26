/*
 * noisy.cpp
 * Copyright (C) 2016 Judit Acs <judit@sch.bme.hu>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>
#include <cstdlib>

class Noisy {
public:
    Noisy() {printf("N");}
    Noisy(const Noisy&) {printf("C");}
    Noisy(int) {printf("I");}
    Noisy(int, int) {printf("i");}
    Noisy& operator=(const Noisy&) {printf("="); return *this;}
    ~Noisy() {printf("D");}
    void mfunc() {printf("M1");}
    void mfunc() const {printf("M2");}
    void mcall() {mfunc(); printf("X1");}
    void mcall() const {mfunc(); printf("X2");}
};

void f1(Noisy) {printf("F1");}
void f2(const Noisy& ) {printf("F2");}
void f3(Noisy& ) {printf("F3");}

int main(int argc, char* argv[]) {
    Noisy n1;
    const Noisy n2;
    //((const Noisy&)n1).mfunc();
    //const Noisy* pn = &n2;
    //pn->mfunc();
    //n1.mcall();
    const Noisy* pn = &n1;
    pn->mcall();
    printf("\nEND\n");
}

