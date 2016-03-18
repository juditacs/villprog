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
};

void f1(Noisy) {printf("F1");}
void f2(const Noisy& ) {printf("F2");}
void f3(Noisy& ) {printf("F3");}

int main(int argc, char* argv[]) {
    Noisy n1, n2=n1;
    Noisy* n = (Noisy*)malloc(sizeof(Noisy)*3);
    free(n);
    Noisy* np = new Noisy[3];
    delete[] np;
    Noisy n3(2), n4;
    n4 = Noisy(42, 45);
    n4 = 42;
    f2(n1);
    const Noisy n5;
    // az f1 ertek szerint veszi at, masolat keszul, ezert
    // konstans parameterrel is mukodik
    f1(n5);
    printf("\nEND\n");
}

